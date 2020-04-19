#function for creating of block
#contact:  "fandimfromitaly@yandex.ru"
#author: Mikhail Elkin


import json
import os
import hashlib

def write_block(filename):
	blockchain_dir = os.curdir + '/blockchain/'
	file = open(blockchain_dir + filename, 'rb').read()

	return hashlib.md5(file).hexdigest()

def check_integrity():
	#count hash of previous block
	#calculate hash
	#compraise got data

	blockchain_dir = os.curdir + '/blockchain/'
	files = os.listdir(blockchain_dir)
	files = sorted([int(i) for i in files])

	for file in files[1:]:
		f = open(blockchain_dir + str(file))
		h = json.load(f)['hash']

		actual_hash = get_hash(prev_file)

		if h ==actual_hash:
			res = 'Ok'
		else:
			res = 'Corrupted'
		result.append({'block': prev_file, 'result': res})	
		
		#print('block {} is: {}'.format(prev_file , res))





def write_block(name , amount , to_whom , prev_hash = ''):

	blockchain_dir = os.curdir + '/blockchain/'

	files = os.listdir(blockchain_dir)
	files = sorted([int(i) for i in files])

	last_file = files[-1]

	filename = str(last_file + 1)

	prev_hash = get_hash(str(last_file))

	data = {'name': name,
	        'amount': amount,
	        'to_whom': to_whom,
	        'hash':prev_hash}
	with open(blockchain_dir + filename , 'w') as file:
		json.dump(data ,  file, indent =4, ensure_ascii=False)
	        

def main():
	write_block(name='ivan' , amount=2 , to_whom='katja')


if __name__ == '__main__':
	main()

	
