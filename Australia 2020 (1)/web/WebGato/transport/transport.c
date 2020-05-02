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

struct conn
{
	transport_address local_address , remote_address;  // status of conection
	cstate state;
	unsigned char *user_buf_addr;
	int byte_count;
	int clr_req_received;
	CLEAR_REQ
	int timer;
	int credits;

} conn[MAX_CONN+1];

void sleep(void);
void wakeup(void);
void to_net(int cid, int q, int m,pkt_type pt, unsigned char *p,int bytes);
void from_net(int *cid, int *q, int *m, pkt_type *pt, unsigned char *,int bytes);

int listen(transport_address t)
{  // customer waits for connection
	int i = 1, found = 0;
    
    for (i = 1; i <= MAX_CONN; i++)
    	if (conn[i].state == QUEUED && conn[i].local_address ==t)
    	{
    		found = i;
    		break;
    	}

    if (found == 0)
    {
    	listen_address = t; sleep(); i = listen_conn ;
    }

    conn[i].state = ESTABLISHED;
    conn[i].state = 0;
    listen_conn = 0;
    to_net (i,0,0,CALL_ACC ,data , 0);

    return(i);	
}

