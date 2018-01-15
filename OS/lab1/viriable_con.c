
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

void best_fit(struct Node* node,int pro_size){

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

	int tot_size=240,processSize[]={50,15,40,25,39,26,45};

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

	internal_frag(head);

	printf("\nReallocating memory for 3 processes of size 19, 38 & 43 KB\n");

	int dup_pro_size[]={19,38,43};

	printf("\nFirst fit case:\n");

	for(int i=0;i<3;i++){

		first_fit(head,dup_pro_size[i]);
	}

	printList(head);

	internal_frag(head);

	printf("jkfjdkjf");

	deallocate(head,dup_pro_size[0]);

	deallocate(head,dup_pro_size[1]);

	merge(head);

	struct Node *node=(struct Node*) malloc(sizeof(struct Node));

	node=head;

	while(node!=NULL){

		if(node->size==43){

			node->type='H';

			node->size=45;

			node->next=NULL;

		}

		node=node->next;

	}


	

	printList(head);

	printf("\nBest fit case:\n");

	for(int i=0;i<3;i++){

		best_fit(head,dup_pro_size[i]);
	}

	printList(head);

	internal_frag(head);



  
 
  return 0;
}