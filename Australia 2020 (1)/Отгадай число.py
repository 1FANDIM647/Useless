import random


print("Добро пожаловать в игру отгадай число \t")
print("Интрепритатор загадал число \n")
print("отгадай\n")

#начальное значение 

the_number = random.randint(1,100)
guess =int(input("Ваша версия:"))
tries = 1

  

while guess != the_number:
    if guess >the_number :
        print("Меньше:")
    else:
        print("Больше:")
    guess =int(input("Ваша версия:"))
    tries +=1        

print(" Это как Sekiro ?")

input("\n\nНажмите enter , чтобы выйти") 