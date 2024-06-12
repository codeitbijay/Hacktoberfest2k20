from django.db import models

# Create your models here.
# Contact us database
class Contact(models.Model):
    sno = models.AutoField(primary_key=True)
    name = models.CharField(max_length=50)
    email = models.CharField(max_length=30)
    phone = models.CharField(max_length=13)
    massage = models.TextField()
    timeStamp = models.DateTimeField(auto_now_add=True, blank=True)

    def __str__(self):
        return self.name + ' - ' + self.email
    