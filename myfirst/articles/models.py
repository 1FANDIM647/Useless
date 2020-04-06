from django.db import models


class Article(models.Model):
	article_title = models.CharField('Name of article',max_length= 100)
	article_text =models.TextField('Your comment',max_length=450)
	pub_date = models.DateTimeField('data')



	
		
class Comment(models.Model):
	article = models.ForeignKey(Article, on_delete= models.CASCADE)
	author_name= models.CharField('Name' , max_length = 49)
	comment_text = models.CharField('comment' , max_length=450)

	

    
 
    