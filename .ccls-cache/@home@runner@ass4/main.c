#include <ctype.h>
#include <stdio.h>
  #include <stdlib.h>
#include <string.h>


typedef struct Group {
long long int arrive, size, process;
} Group;//group struct


typedef struct Node {
Group data;
struct Node * next;
}Node;//nodes



void sort(Node *head){//sorth method

  Node * i,*j;
  Group temp;  //same as reg int comparing sort but using nodes arrival as vars

  for(i=head;i->next!=NULL;i=i->next)
    {
      for(j=i->next;j!=NULL;j=j->next)
        {
          if(i->data.arrive>j->data.arrive)
          {
            temp=i->data;
            i->data=j->data;
            j->data=temp;
          }
          
        }
    }

  
}



Node * newNode(Group newGroup){//make new node
   Node* node = malloc(sizeof(Node));
  node->data=newGroup;
  node->next=NULL;
  return node;


  
}




Node *insert_at_head(Node **head, Node *insert){//insert node at head
  insert->next=*head;
  *head=insert;
  return insert;
}



void printlist(Node *head){//prinbt for to make sure linked list works and is soprted
  Node *temp=head;
  while(temp!=NULL){
    printf("%d\n", temp->data.arrive);
    temp= temp->next;
      
      
  }
}





//---------------------------------------------------


int main(void) {
  
  int n, s, a, p;
  scanf("%d", &n);
  Group groups[n];
 Node *head=NULL;
  Node *temp;
//beginning input +head for ll
  for(int i=0;i<n;i++){
    scanf("%d %d %d", &s, &a, &p);
    groups[i].arrive=a;
       groups[i].size =s; 
      groups[i].process=p;
    

    
    Node *temp=newNode(groups[i]);
   insert_at_head(&head, temp);
   // inserting to ll

    
      
  }

  //printlist(head);
 // printf("\n");
  sort(head);//sort
// printlist(head);


  int timeL=0;
  int timeR=0;
  int R=0;
  int L=0;
  int wait=0;
  //vars to calculate wait time

  temp=head;
  while(temp!=NULL){//go through linked
   //printf("%d\n", temp->data.arrive);


    

  if(timeL==timeR||timeL<timeR){//which line
    
       L++;
    if(timeL<temp->data.arrive){//for to start line
      timeL=temp->data.arrive;
    }
    
      timeL+=temp->data.process;//time to process is waiting
    wait+=(timeL-temp->data.arrive);//time-arrival
    

    
    
   
  }
  else{
    
     R++;
    if(timeR<temp->data.arrive){
      timeR=temp->data.arrive;
    }//same as L
    
      timeR+=temp->data.process;
    wait+=(timeR-temp->data.arrive);
    

    
    
    
  }

   temp= temp->next;//next node


  
}

  printf("\n\n%d", wait);
  }