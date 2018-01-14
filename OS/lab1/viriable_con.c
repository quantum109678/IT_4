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

	while(1){

		if(node->size==pro_size){

			node->type='H';

			break;
		}

		node=node->next;

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

	int tot_size=240,processSize[]={50,15,45,25,39,26};

	printf("Total memory available:%dKB\n\n",tot_size);

	for(int i=0;i<6;i++){

		printf("Process_number:%d   Process_size:%d\n",i+1,processSize[i]);
	}

	struct Node* head=NULL;


	for(int i=0;i<6;i++){

		allocate(&head,processSize[i]);
	}

	printf("\nAfter allocating memory for each process:\n");

	printList(head);

	printf("\nTerminating process numbers 2,3 & 5\n");

	deallocate(head,processSize[1]);

	deallocate(head,processSize[2]);

	deallocate(head,processSize[4]);

	printf("\nAfter allocating memory for each process:\n");

	printList(head);
  
 
  return 0;
}