from django.db import models

#articles on site
class Articles (models.Model):
	title = models.CharField(max_length = 120)
	post = models.TextField()
	date =models.DateTimeField()

	def __str__(self):
		return self.title

    
   

    