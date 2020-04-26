import random
import os 
import datetime

print("STAY AT HOME")

print(datetime.date.today())#time now

def calculate_possibility():
	deaths=int(input("How many deaths were today?"))
	arrange_point = 25
	possiblity= arrange_point/deaths
	possiblity_for_file = str(possiblity)
	text_file = open("possiblity_for . txt" , "w", encoding="utf-8")
	text_file.writelines(possiblity_for_file)
	text_file.writelines("possiblity of death today\n")
	text_file.writelines("\n\n test works with help Cpython\n ")
	text_file.close()

calculate_possibility()
