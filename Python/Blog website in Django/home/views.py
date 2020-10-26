from django.shortcuts import render, redirect
from .models import Contact
from blog.models import Post
from django.contrib import messages
from django.contrib.auth.models import User
from django.contrib.auth import authenticate, login, logout

# Create your views here.
def home(request):
    allpost = Post.objects.all()
    context = {'allposts': allpost}
    return render(request, 'home/home.html', context)

def contact(request):
    if request.method == 'POST':
        name = request.POST['name']
        email = request.POST['email']
        phone = request.POST['phonenumber']
        msg = request.POST['massage']
        
        if len(name)<2 or len(email)<5 or len(phone)<10 or len(msg)<10:
            messages.error(request, "Please fill the form correctly")
        else:
            contact = Contact(name=name, email=email, phone=phone, massage=msg)
            contact.save()
            messages.success(request, "Your message has been send")
        
    return render(request, 'home/contact.html')

def about(request):
    return render(request, 'home/about.html')

def search(request):
    query = request.GET['query']
    if len(query) > 50 or len(query) == 0:
        allpost = Post.objects.none()
    else:
        allposttitle = Post.objects.filter(title__icontains=query)
        allpostcontent = Post.objects.filter(content__icontains=query)
        allpostauthor = Post.objects.filter(author__icontains=query)

        allpostblog = allposttitle.union(allpostcontent)
        allpost = allpostblog.union(allpostauthor)
    params = {
        'allpost':allpost,
        'query':query,
    }
    return render(request, 'home/search.html', params)

def handleSignup(request):
    if request.method == 'POST':
        fname = request.POST['name']
        lname = request.POST['lastname']
        username = request.POST['username']
        email = request.POST['email']
        password = request.POST['password']
        cpassword = request.POST['cpassword']

        if not username.isalnum():
            messages.error(request, "Username should be alphanumeric")

        if password == cpassword:
            myuser = User.objects.create_user(username, email, password)
            myuser.first_name = fname
            myuser.last_name = lname
            myuser.save()
            messages.success(request, "Account Create Successfully")
        else:
            messages.error(request, "Password not correct")
        
        return redirect('home')
    return redirect('home')

def handlelogin(request):
    if request.method == 'POST':
        username = request.POST['loginusername']
        loginpassword = request.POST['loginpassword']

        user = authenticate(username=username, password=loginpassword)
        if user is not None:
            login(request, user)
            messages.success(request, "Successfully Logged In")
            return redirect('home')
        else:
            messages.error(request, "Login Unsuccessful")
            return redirect('home')
    return redirect('home')

def handlelogout(request):
    logout(request)
    messages.success(request, "Logout Successfully")
    return redirect('home')