#include <stdio.h>
#include <stdlib.h>
#define Tot_Size 200

struct Node
{
 
  int size;
  struct Node *next;
  char type;
};



void allocate(struct Node** head_ref, int new_size)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head_ref;

    new_node->size  = new_size;

    new_node->type= 'P';
 
    new_node->next = NULL;
 
    if (*head_ref == NULL)
    {
       *head_ref = new_node;

       return;
    }
 
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_node;



    return;
}
void deallocate(struct Node* node,int pro_size){

    while(node!=NULL){

        if(node->size==pro_size){

            node->type='H';

           
        }

        node=node->next;

    }

   

}

void merge(struct Node* ref){

    while(ref->next!=NULL){

        if(ref->type=='H' && ref->next->type=='H'){

            ref->size=ref->size+ref->next->size;

            ref->next=ref->next->next;


 
        }

        ref=ref->next;
    }

}

void shift(struct Node* ref){

    struct Node* last=ref;

    struct Node* dup=ref;

    struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));

    new_node->type='H';

    new_node->size=0;

    while(last->next!=NULL){

        last=last->next;
    }


    while(ref->next!=NULL){

        if(ref->type=='H'){

            new_node->size+=ref->size;

         }

        ref=ref->next;
    }

    while(dup->next!=NULL){

        if(dup->next->type=='H'){

            dup->next=dup->next->next;

         }

        dup=dup->next;
    }

    last->next=new_node;
}


void first_fit(struct Node* node,int pro_size){

    int rem;

    while(node!=NULL){

        if(node->type=='H' && node->size>=pro_size){

            node->type='P';

            rem=node->size-pro_size;

            node->size=pro_size;

            struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));

            new_node->size=rem;

            new_node->type='H';

            new_node->next=node->next;

            node->next=new_node;

            break;


        }

        node=node->next;

    }

}





void internal_frag(struct Node *node){

    int frag=0;

    while(node!=NULL){

        if(node->type=='H'){

            frag=frag+node->size;
        }

        node=node->next;
    }

    printf("\nToatl internal fragmentation size=%d\n",frag);

}



void printList(struct Node *node)
{
  while (node != NULL)

  {    if(node->type=='P'){
   
     printf("Process of size %d\n",node->size);
     }
     else{
       
        printf("Hole of size %d\n",node->size);
    }
     node = node->next;
  }
}
 
int main()
{

    int processSize[]={50,15,40,20,45,30};

    printf("Total memory available:%dKB\n\n",Tot_Size);

    for(int i=0;i<6;i++){

        printf("Process_number:%d   Process_size:%d\n",i+1,processSize[i]);
    }

   struct Node* head=NULL;


    for(int i=0;i<6;i++){

        allocate(&head,processSize[i]);
    }

    printf("\nAfter allocating memory for each process:\n");

    printList(head);

    printf("\nTerminating process numbers 2,3 &5 \n");

    deallocate(head,processSize[1]);

    deallocate(head,processSize[2]);

    deallocate(head,processSize[4]);

    merge(head);

    printList(head);

    internal_frag(head);

    printf("\nThis is the output of the previous version,in which the holes are scattered in between process\n");

    printf("\nThe following is the output after the modification in which all the holes are shifted to the end and merged\n");

    shift(head);

    printList(head);

  return 0;
}

