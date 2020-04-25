#text console for results of calculating 
#text for
import random
import os
import pickle ,shelve
import datetime
import time
import colorama
from colorama import Fore, Back, Style
colorama.init()

version = 1.23


print(Fore.RED+    "Encrypt              | F1 |")
print(Fore.RED+    "Decrypt              | F2 |")
print(Fore.BLUE+   "Read Documintation   | F3 |")


choose_command=""
while not choose_command:
    choose_command=input("Enter command ")
    if (choose_command == "F1"):
    	salt = input("")
    	salt_array = [salt]
    	file = open("result.dat" , "wb")
    	pickle.dump(salt_array,file)
    	file.close() 
    elif (choose_command == "F2"):
    	print ("This simple program for cryptography created by Shishov Mikhail")




print(Style.RESET_ALL)
