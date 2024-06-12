from django.contrib import admin
from django.urls import path
from . import views

urlpatterns = [
    path('/postcomment', views.Postcomment, name='Postcomment'),
    path('', views.bloghome, name='bloghome'),
    path('/<str:slug>', views.blogpost, name='blogpost'),
]
