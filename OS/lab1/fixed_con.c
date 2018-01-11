/*Fixed size contiguous
User i/p: size of the processor
		  number of blocks
		  number of files
		  file size
Randomly determine the size of each block
3 methods for FF,BF & WF
Maintain a queue for processes*/

#include <stdio.h>
#include <stdlib.h>

void bestfit(int blockSize[], int num_of_blocks, int processSize[],int num_of_pro){
	return(0);
}

void firstfit(int blockSize[], int num_of_blocks, int processSize[], int num_of_pro){

	int alloc[num_of_pro];

	for(int i=0;i<num_of_pro;i++){

		alloc[i]=-1
	}

	for (int i=0;i<num_of_pro;i++){
		 
		 for (int j=0; j<num_of_blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                alloc[i] = j;
 
                blockSize[j] -= processSize[i];
                 
                 break;
            }
        }
	}

	rem_size=0;

	for(int i=0;i<num_of_blocks;i++){

		rem_size=rem_size+blockSize[i];
	}

	for(int i=0;i<num_of_pro;i++){

		if ((alloc[i]==-1) && (processSize[i]<=rem_size)){

			alloc[i]=-10;
		}
	}

	printf("The first fit memory allocation is as follows:");

	printf("Process number\tProcess Size\tBlock number\tFragment size");

	for(int i=0;i<num_of_pro;i++){

		if(alloc[i]>=0){

			printf("%d\t%d\t%d\t%d",i,processSize[i],alloc[i],blockSize[alloc[i]]);
		}

		else if(alloc[i]==-10){

			printf("%d\t%d\tExternal fragmentation",i,processSize[i]);
		}

		else{

			printf("%d\t%d\tMemory not allocated",i,processSize[i]);
		}
	}


	return(0);
}

void worstfit(int blockSize[], int num_of_blocks, int processSize[], int num_of_pro){
	return(0);
}

int main(){
	int num_of_blocks,num_of_pro;

	printf("Enter the number of number of blocks of memory:");
	
	scanf("%d",&num_of_blocks);

	int blockSize[num_of_blocks];

	for(int i=0;i<num_of_blocks;i++){
		
		printf("Enter the blocksize of %dth block:",i);
		
		scanf("%d",&blockSize[i]);
	}

	printf("Enter the number of number of processes:");
	
	scanf("%d",&num_of_pro);

	int processSize[num_of_pro];
	
	for(int i=0;i<num_of_pro;i++){
		
		printf("Enter the size of %dth process:",i);
		
		scanf("%d",&processSize[i]);
	}

	firstfit(blockSize, num_of_blocks, processSize, num_of_pro);
	
	bestfit(blockSize, num_of_blocks, processSize, num_of_pro);
	
	worstfit(blockSize, num_of_blocks, processSize, num_of_pro);

	return(0);


}