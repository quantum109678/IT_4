#include <stdio.h>
#include <stdlib.h>

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

	struct Node* ref=node;

	while(1){

		if(node->size==pro_size){

			node->type='H';

			break;
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

void printList(struct Node *node)
{
  while (node != NULL)

  {	if(node->type=='P'){
    
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

	int tot_size=260,processSize[]={50,15,45,25,39,26,20};

	printf("Total memory available:%dKB\n\n",tot_size);

	for(int i=0;i<7;i++){

		printf("Process_number:%d   Process_size:%d\n",i+1,processSize[i]);
	}

	struct Node* head=NULL;


	for(int i=0;i<7;i++){

		allocate(&head,processSize[i]);
	}

	printf("\nAfter allocating memory for each process:\n");

	printList(head);

	printf("\nTerminating process numbers 2,3,5 & 7\n");

	deallocate(head,processSize[1]);

	deallocate(head,processSize[2]);

	deallocate(head,processSize[4]);

	deallocate(head,processSize[6]);

	merge(head);

	printList(head);

	first_fit()
  
 
  return 0;
}