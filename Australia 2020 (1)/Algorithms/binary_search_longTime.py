def binary_search (list1 , key):
	low = 0 
	high = len(list1)-1
	Found = False
	while low<=high and not Found:
		mid = (low+high)//2
		if key == list1[mid]:
			Found = True
		elif key>list1[mid]:
			low = mid +1
		else:
			high = mid-1
	if Found == True:
		print("key is Found")
		print(key)
	else:
		print("key is not Found")

list1 = [23,25,16,17,84]
list1.sort()
key = int(input("enter the key:"))
binary_search(list1,key)

			
			
		