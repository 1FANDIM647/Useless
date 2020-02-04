#include<iostream>
#include<cstring>
using namespace std;
struct Nod{
    char nameProc[100];
    int arrivalT;
    int burstT;
    Nod *next;
};
Nod *head = NULL;
Nod *tail = NULL;

struct process
{
    char nameProcess[100];
    int arrival_Time;
    int burst_Time;
    int inList;
};

void deleteHead (Nod *&head)
{
    Nod* toDelete = head;
    head = head->next;
    delete toDelete;
    return;
}

void addArrivals(int time,Nod *&head,struct process p[],int n){
    int i;
    for(i=0;i<n;i++){
        if((p[i].arrival_Time<=time)&&(p[i].inList==0))  {

            if(head==NULL)  // If the list is empty
            {
                head = new Nod; // memory for the first one
                strcpy(head->nameProc,p[i].nameProcess);
                head->arrivalT = p[i].arrival_Time;
                head->burstT = p[i].burst_Time;
                head->next = head; // It's the only one, so it's connected to itself
                tail =head; //  and it is tail also
                p[i].inList=1;
            }
            else // the list is not empty
            {   Nod * nod = new Nod; // memory for a new one
                strcpy(nod->nameProc,p[i].nameProcess);    // put the data in it
                nod->arrivalT = p[i].arrival_Time;
                nod->burstT = p[i].burst_Time;
                nod->next = head;  // link tail to the head
                tail->next = nod;    // the ex tail is linked to the new one
                tail = nod;          // the new one is tail now
                p[i].inList=1;

            }
        }
    }

    return;
}

void exeProc(Nod *&head, int quantum,int &time)  //execution
{   tail=head;         // the ex head becomes tail
    head=head->next;        // and the next one becomes head
    if(head->burstT>quantum)  {        //bt>quantum

        head->burstT=head->burstT-quantum;
        time=time+quantum;
        cout <<"At "<<time<<" ,"<< head->nameProc<< " has been executing for " <<quantum<<" secs. It has "<<head->burstT<<" more."<<endl;
    }
    else { if(head->burstT>0) {time=time+head->burstT;
        cout<<"At "<<time<<" ,"<<head->nameProc<<" has been executing for "  <<head->burstT<<" secs. The process "<<head->nameProc<<" is finished."<<endl;
        head->burstT=0;
        deleteHead(head);
    }}
}

int main()
{
    int quantum,n,i,time=0;   // time= current moment in time    n=number   of     proc      quantum= alocated execution time
    struct process p[100];


    cout<<"Give quantum: ";      //read quantum
    cin>>quantum;
    while (quantum<1||quantum>10)
    {
        cout << "Quantum is not valid. Give a valid one: ";
        cin >>quantum;
    }


    cout<<"Give number of proc:";
    cin>>n;

    for(i=0;i<n;i++)
    {   cout<<"Add name, at, bt "<<i+1<<": ";       //Arrival time & burst         time
        cin>>p[i].nameProcess;
        cin>>p[i].arrival_Time;
        cin>>p[i].burst_Time;
        p[i].inList=0;            //no process is in the list yet
    }


    // I start working with the circular linked list
    Nod*head=NULL;
    Nod*tail=NULL;

    do{
        addArrivals(time,head,p,n);
        exeProc(head,quantum,time);
    }while(head!=NULL);  ///??? condition for circular list ???
    cout<<"At "<<time<<", all they are all finished."<<endl;
    return 0;
}
