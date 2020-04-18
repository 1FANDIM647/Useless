#it's program for  server  ,  it just sends message to another user
#Author : Shishov Mikhail
#contact: fandimfromitaly@yandex.ru

import socket,time 

host = socket.gethostbyname(socket.gethostbyname()) #get host
port = 9090

clients = []

s = socket.socket(socket.AF_INET,socket.S0CK_DGRAM)
s.bind((host,port))

quit = False
print ("[Server Started]")

while  not quit:
	try:
		data, addr = s.recvform(1024)

		if addr not in clients:
			clients.append(addr)
	    
	    itsatime = time.strftime("%Y-%m-%d-%H.%M.%S",time.localtime())

	    print("["+addr[0]+"]=["+str(addr[1])+"]=["+itsatime+"]/",end="")
	    print(data.decode("utf-8"))

	    for client in clients:
	    	if addr != client:
	    		s.sendto(data,client)
	except:
		print("\n[Server Stopped]")
		quit = True

s.close()		


	    		

