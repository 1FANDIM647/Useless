import random
#review of function  "return"  in python 
def display(message):
    print(message)# You'll see what  you  wrote 

def give_me_any_number ():
    any_number = random.randint(1,100)
    return any_number
def ask_yes_no (question) :
  
    response = None
    while response not in ("yes " , "no"):
        response = input(question)
    return response #u need input yes or no to finish the loop
# call our functions 
display ("Your massage:\n")
number = give_me_any_number()
print ("How function worked :", give_me_any_number)
answer =ask_yes_no("yes or no")
print("Nice")
input("\n\nНажмите Enter , чтобы выйти.  ")
