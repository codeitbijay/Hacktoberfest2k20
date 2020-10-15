from django.shortcuts import render, redirect
from .models import Post, BlogComment
from django.contrib import messages
from .templatetags import extras

# Create your views here.
def bloghome(request):
    allpost = Post.objects.all()
    context = {'allposts': allpost}
    return render(request, 'blog/bloghome.html', context)

def blogpost(request, slug):
    post = Post.objects.filter(slug=slug).first()
    comment = BlogComment.objects.filter(post=post, parent=None)
    replies = BlogComment.objects.filter(post=post).exclude(parent=None) #exclude none ke alawa

    replyDict = {}
    for reply in replies:
        if reply.parent.sno not in replyDict.keys():
            replyDict[reply.parent.sno] = [reply]
        else:
            replyDict[reply.parent.sno].append(reply)

    context = {
        'post':post, 
        'comment':comment,
        'replyDict':replyDict
    }
    return render(request, 'blog/blogpost.html',context)

def Postcomment(request):
    if request.method == 'POST':
        comment = request.POST['comment']
        user = request.user
        postSno = request.POST['postSno']
        post = Post.objects.get(sno=postSno)
        parent = request.POST['perentSno']

        if parent == "":
            Scomment = BlogComment(comment=comment, user=user, post=post)
            Scomment.save()
            messages.success(request, "Comment Added Successfully")
            return redirect(f"/blog/{post.slug}")
        else:
            parent = BlogComment.objects.get(sno=parent)
            Scomment = BlogComment(comment=comment, user=user, post=post, parent=parent)
            Scomment.save()
            messages.success(request, "Replay Added Successfully")
            return redirect(f"/blog/{post.slug}")
        
    return redirect('home')