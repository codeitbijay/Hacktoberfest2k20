from django.contrib import admin
from .models import Post, BlogComment
# Register your models here.

admin.site.register(Post)
admin.site.register(BlogComment)