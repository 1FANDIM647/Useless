/*
Transport file
Data 02.05.2020
Liscense : WebGato liscense v1.0

this program helps  us  to send file 
to anouther computer  

*/
#define MAX_CONN 32 
#define MAX_MSG_SIZE 1000000000 /* MAXIMUM size of messagen in bytes*/
#define MAX_PKT_SIZE 1000000000 /*MAXIMUM size of package in bytes*/
#define TIMEOUT 20
#define CRED 1
#define OK 0
#define ERR_FULL -1
#define ERR_REJECT -2
#define ERR_CLOSED -3
#define LOW_ERR -3

typedef int transport_address;
typedef enum {CALL_REQ,CALL_ACC,CLEAR_REQ,CLEAR_CONF,DATA_PKT,CREDIT} pkt_type;
typedef enum {IDLE,WAITING,QUEUED,ESTABLISHED,SENDING,RECEIVING,DISCONN} cstate;
/*global variables*/
transport_address listen_address 
/*local address*/
int listen_conn; 
unsigned char data[MAX_PKT_SIZE]; // package for holging of data
