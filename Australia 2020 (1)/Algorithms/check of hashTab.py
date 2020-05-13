#we create hashTab 
vouters =dict()

vouters["Misha"] = 1
vouters["Masha"] = 2
vouters["Eva"]   = 3


    


#we check , there is vouter , isn't there?

def check_vouter(name):
	if vouters.get(name):
		print("He is not there")
	else:
		vouters[name]=True
		print("He exists")
		


check_vouter("Misha")
check_vouter("Masha")
check_vouter("Eva")


	 

