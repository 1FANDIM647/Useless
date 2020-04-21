#how to count all numbers in array
def sum(arr):
	total = 0 
	for x in arr:
		total += x
	return total

result = sum([1,243,5,5,65,7,75])

print (result)
