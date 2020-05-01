/*Program for creating of socket for WebGato
Data : 01.05.2020
Authour : Elkin Michael
License : WebGato License v1.0 
This program runs on server

*/
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 12345 /*Accord*/
#define BUF_SIZE 10000 /*SIZE OF BLOCKS IN FILE FOR  SENDING*/
#define QUEUE_SIZE 10

int int main(int argc, char const *argv[])
{
	int s,b,l,fd,,sa,bytes,on = 1;
	char buf[BUF_SIZE]; // buffer for income file
	struct sockaddr_in channel; // Ip address


    /*struct of address for link with socket*/
    memset(&channel , 0 , sizeof(channel)); // zero channel
    channel.sin_family = AF_INET;
    channel.sin_addr.s_addr = htonl(INADDR_ANY);
    channel.sin_port = htons(SERVER_PORT);

    s = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP); // create socket
    if (s<0) fatal("socket error");
    setsockopt(s, SOL_SOCKET , SO_REUSEADDR, (char *) &on, sizeof(on));
    b = bind(s , (struct sockaddr *) &channel , sizeof(channel)); //bind socket
    if (l<0) fatal("error of binding");

    l = listen(s , QUEUE_SIZE); /*define of size queue*/
    if (l<0) fatal("error of waiting");

    while (1)
    {
    	sa = accept(s, 0 ,0);
    	if (sa<0) fatal("Access error");

    	read(sa , buf ,BUF_SIZE); /*get name from the file */

    	/*get and return file*/
        fd = open(buf , O_RDONLY);
        if (fd < 0) fatal("error of opening");

        while (1)
        {
        	bytes = read(fd, buf, BUF_SIZE);/*read from the file */
        	if (bytes <= 0)break; /*checking of the end*/
        	write(sa , buf , bytes); /*write bytes in socket*/ 
        }
        close(fd); // close file 
        close(sa); // finish connection
    }
	return 0;
}