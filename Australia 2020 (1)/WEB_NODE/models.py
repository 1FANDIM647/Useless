from django.db import models
from datetime import date

class Category(models.Model):
	""" Category """
	name = models.CharField("Category" , max_length=150)
	description = models.TextField("description")
	url = models.SlugField(max_length=160 , unique=True)

	def __str__(self):
		return self.name
	class Meta:
		verbose_name = "Category"
		verbose_name_plural = "Categories"
		

    

class Actor(models.Model):
	name = models.CharField("Name", max_length=100)
	age = models.PositiveSmallIntegerField("Age",default=0)
	description = models.TextField("description")
	image = models.ImageField("Image", upload_to="actros/")

	def __str__(self):
		return self.name

	class Meta:
		verbose_name = "Actors and directors"
		verbose_name_plural = "Actors and directors"
			
class Genre(models.Model):

	name = models.CharField("Name",max_length=100)
	description = models.TextField("description")
	url = models.SlugField(max_length=160,unique=True)

	def __str__(self):
		return self.name

	class Meta:
		verbose_name = "Genre"
		verbose_name_plural ="Genres"
					
class Movie(models.Model):
	title = models.CharField("Title", max_length=100)
	tagline = models.CharField("Tagline" , max_length=100,default='')
	description = models.TextField("description")
	poster = models.ImageField("Poster", upload_to="movies/")
	year = models.PositiveSmallIntegerField("Date " , default=2019)
	country= models.CharField("Country",max_length = 30)
	directors = models.ManyToManyField(Actor, verbose_name="director" ,related_name="film_director")
	actors = models.ManyToManyField(Actor, verbose_name="actors",related_name="film_actor")
	geners = models.ManyToManyField(Genre,verbose_name="geners")
	world_premiere = models.DateField("world premiere" , default = date.today)
	budget = models.PositiveSmallIntegerField("Capital" , default=0 , help_text="sum in dollars")
	fees_in_usa = models.PositiveSmallIntegerField("Cast in USA", default=0,help_text="sum in dollars")
	fess_in_world = models.PositiveSmallIntegerField("Cast in world" , default=0,help_text="sum in dollars")
	category = models.ForeignKey(Category, verbose_name = "Category" , on_delete=models.SET_NULL, null=True)
	url = models.SlugField(max_length=160, unique=True)
	draft = models.BooleanField("Draft" , default=False)
    #url = models.SlugField(max_length=160,unique=True)
    

	def __str__(self):
		return self.title
    #category = models.ForeignKey(Category, verbose_name="Category" ,on_delete=models.SET_NULL, null=True)
   
    #draft = models.BooleanField("Draft" , default=False)
    



   


class MoviesShots(models.Model):
	title = models.CharField("title" , max_length=100)
	description = models.TextField("description")
	image = models.ImageField("Image" , upload_to="movie_shots/")
	movie = models.ForeignKey(Movie , verbose_name="Movie",on_delete=models.CASCADE)

	def __str__(self):
		return self.title

	class Meta:
		verbose_name = "Movie shoot"
		verbose_name_plural = "Movie shoots"
    	
   

class RattingStar (models.Model):

	 value = models.SmallIntegerField("Meaning " , default=0)

	 def __str__(self):
	 	return self.value

	 class Meta:
	 	verbose_name = "Ratting Star"
	 	verbose_name_plural =  "Ratting Stars"

class Ratting(models.Model):
	ip = models.CharField("IP address",max_length=15)
	star = models.ForeignKey(RattingStar,on_delete=models.CASCADE , verbose_name="Star")
	movie = models.ForeignKey(Movie, on_delete=models.CASCADE, verbose_name = "film")

	def __str__(self):
		return f"{self.star}-{self.movie}"

	class Meta:
		verbose_name = "Ratting"
		verbose_name_plural = "Rattings"

	 			


class Reviews(models.Model):

	email = models.EmailField()
	name  = models.CharField("Name" , max_length=100)
	text  = models.TextField("Message" , max_length=5000)
	parent = models.ForeignKey('self' , verbose_name="Parent" , on_delete=models.SET_NULL , blank=True , null=True)
	movie = models.ForeignKey(Movie , verbose_name="film" , on_delete=models.CASCADE)

	def __str__(self):
		return f"{self.name}-{self.movie}"

	class Meta:
		verbose_name = "Review"
		verbose_name_plural ="Reviews"



# Create your models here.
