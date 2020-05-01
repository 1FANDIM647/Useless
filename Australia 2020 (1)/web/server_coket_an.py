#ansyhron server for many requests

import os, request 
 
def server():
	server = create_passive_socket()
	server.setblocking(0)
	rlist = [server] # we can accept only if there is  a conn
	wlist , elist = [] , []
    while  True:
    	rs, ws, es = select.select(rlist , wlist , elist , 0.1)
    	for  rsock in rs:
    		if rsock is server:
    			new_read_sock, _= rsock.accept()
    			new_read_sock.setblocking(0)
    			rlist.append(new_read_sock)
    		else:
    			handle_read(rsock)
    	for wsock in ws:
    		handle_write(wsock)

    			


    	
