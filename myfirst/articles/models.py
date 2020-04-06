from django.db import models

class  Article(models.Model):

	article_title = models.CharField('Name of article' , max_length = 100)
    article_text = models.TextField( 'Your comment' , max_length= 450)
    pub_date = models.DateTimeField('data of publication')

	
		
class Comment(modesls.Model):
	
	article = modesls.Foreignkey(Article , on_delete = modesls.CASCADE)  
    author_name = modesls.CharField('Name' , max_length = 51)
    comment_text = modesls.CharField('comment' , max_length= 456)

    
 
    