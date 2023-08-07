// P.V.S.PRANAV - CS21B1056

#include<stdio.h>
#include<stdlib.h>

struct node {
  int pid; // process id
  int at;  // arrival time
  int bt;  // burst time
  int ct;  // completion time
  int wt;  // waiting time
  int tat; // turn around time
  int rt;  // response time
  struct node * next;
};

struct node * head;

void insert_and_update();

int main() {
    insert_and_update();
    
    return 0;
}

void insert_and_update() {
    int n,arr,burst;
    printf("Enter the no.of processes : ");
    scanf("%d",&n);
    
    head = (struct node*)malloc(sizeof(struct node));
    struct node * temp;
    struct node * ptr;
    
    if(head == NULL) {
        printf("No memory allocated");
    }
    else {
        head->pid = 1;
        printf("Enter the Arrival Time for the Process - 1 : ");
        scanf("%d",&arr);
        
        head->at = arr;
        
        printf("Enter the Burst Time for the Process - 1 : ");
        scanf("%d",&burst);
        
        head->bt = burst;
        head->next = NULL;
        
        temp = head;
    }
    
    for(int i=1;i<n;i++) {
        ptr = (struct node*)malloc(sizeof(struct node));
        
        if(ptr == NULL) {
            printf("No memory allocated");
        }
        else {
            ptr->pid = i+1;
            printf("Enter the Arrival Time for the Process - %d : ",i+1);
            scanf("%d",&arr);
            
            ptr->at = arr;
            
            printf("Enter the Burst Time for the Process - %d : ",i+1);
            scanf("%d",&burst);
            
            ptr->bt = burst;
            ptr->next = NULL;
            
            temp->next = ptr;
            ptr->next = NULL;
            
            temp = temp->next;
        }
    }
    
    temp = head;
    int finish = 0;                       // variable used to calculate the completion time
    float wait=0,turn=0;
    
    while(temp!=NULL) {
        if(finish < temp->at) {
            temp->ct = temp->at + temp->bt;
            finish = temp->ct;
        }
        else {
            finish += temp->bt; // finish variable is the sum of the time taken to completed the previous processes and the burst time of the current process
            temp->ct = finish;
        }
        
        temp->tat = temp->ct - temp->at;
        temp->wt = temp->tat - temp->bt;
        
        temp->rt = temp->wt;      //rt is equal to wt if it is a non preemptive process
        temp = temp->next;
    }
    
    temp = head;
    
    printf("P_ID \t AT \t BT \t CT \t TAT \t WT \t RT \n");
    
    while(temp != NULL) {
        wait += temp->wt;        // total waiting time
        turn += temp->tat;      // total turn around time
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n",temp->pid,temp->at,temp->bt,temp->ct,temp->tat,temp->wt,temp->rt);
        
        temp = temp->next;
    }
    
    float avg_wait, avg_tat;
    avg_wait = wait/n;   // average waiting time
    avg_tat = turn/n;   // average turn around time
    
    printf("Average Waiting Time : %.2f \n", avg_wait);
    printf("Average TurnAround Time : %.2f \n", avg_tat);
}