#server for using proceses read and write

import os ,request

def server():
	sock = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
	sock.bind(('127.0.0.1', 8888))
	sock.listen()
	while  True:
		conn, addr = sock.accept()
		request_data = conn.read(1024)
		response = businees_logic(request_data)
		conn.sendall(b"""\r\nHTTP/1.1 200 OK\r\n\r\n """+ response)
		conn.close()
		
