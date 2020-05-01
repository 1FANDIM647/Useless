/*Program for geting file 
Data : 01.05.2020
Authour : Elkin Michael
License : WebGato License v1.0 
This program runs on Linux or  Unix

*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 12345 
#define BUF_SIZE 10000 /*Size of sending blocks*/

int main(int argc, char *argv)
{
 int c,s, bytes;
 char buf[BUF_SIZE]; /*BUFF for income file */
 struct hostent *h; /*information about server*/
 struct sockaddr_in channel; /*IP address*/
 
 if(argc!=3) fatal("Enter : client name and name of the file:");
 h = gethostbyname(argv[1]); /*search  of IP address*/
 if( !h ) fatal("can not  finsih gethostbyname "); 
 s = socket(PF_INET , SOCK_STREAM , IPPROTO_TCP);
 if(s<0) fatal("socket");
 memset(&channel , 0 ,sizeof(channel));
 channel.sin_family = AF_INET;
 memcpy(&channel.sin_addr.s_addr,h>h_addr,h>h_lenght);
 channel.sin_port = htons(SERVER_PORT);

 c = connect(s,(struct sockaddr *)&channel , sizeof(channel));
 if (c<0) fatal ("Error connection");

 /*if connection is stabilished*/
 write*s ,argv[2], srtlen(argv[2]+1);

 while (1)
 {
 	 bytes = read(s, buf, BUF_SIZE); // read from socket
 	 if (bytes <= 0) exit(0);        // Checking of the file end
 	 write(1, buf , bytes);          // Write in stardant devie of output    
 }
 
 fatal(char *string)
 {
 	printf("%s\n", string);
 	exit(1);
 }

}