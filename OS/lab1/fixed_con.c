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

	int alloc[num_of_pro],bs_dup[num_of_blocks];

	int temp,cur;

	for(int i=0;i<num_of_blocks;i++){

		bs_dup[i]=blockSize[i];
	}

	for(int i=0;i<num_of_pro;i++){

		alloc[i]=-1;
	}

	for (int i=0;i<num_of_blocks-1;i++){

		for(int j=i+1;j<num_of_blocks;j++){

			if(blockSize[i]>blockSize[j]){

				temp=blockSize[i];

				blockSize[i]=blockSize[j];

				blockSize[j]=temp;

			}
		}
	}

	for (int i=0;i<num_of_pro;i++){
		 
		 for (int j=0; j<num_of_blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                alloc[i] = j;

                 for(int x=0;x<num_of_blocks;x++){

					if(blockSize[j]==bs_dup[x]){

						bs_dup[x] -= processSize[i];

						
					}
				}
                
 
                blockSize[j] -= processSize[i];
                 
                 break;
            }
        }
	}


	int rem_size=0;

	for(int i=0;i<num_of_blocks;i++){

		rem_size=rem_size+blockSize[i];
	}

	for(int i=0;i<num_of_pro;i++){

		if ((alloc[i]==-1) && (processSize[i]<=rem_size)){

			alloc[i]=-10;
		}
	}

	printf("\nThe best fit memory allocation is as follows:\n");

	printf("Process number\tProcess Size\tBlock number\tInternal fragment size(if any)\n");

	for(int i=0;i<num_of_pro;i++){

		if(alloc[i]>=0){

			for(int j=0;j<num_of_blocks;j++){

					if(blockSize[alloc[i]]==bs_dup[j]){

						cur=j;

						
					}
				}


			printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,processSize[i],cur+1,blockSize[alloc[i]]);
		}

		else if(alloc[i]==-10){

			printf("%d\t\t%d\t\tExternal fragmentation\n",i+1,processSize[i]);
		}

		else{

			printf("%d\t\t%d\t\tMemory not allocated\n",i+1,processSize[i]);
		}
	}



	
}

void firstfit(int blockSize[], int num_of_blocks, int processSize[], int num_of_pro){

	int alloc[num_of_pro];



	for(int i=0;i<num_of_pro;i++){

		alloc[i]=-1;
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

	int rem_size=0;

	for(int i=0;i<num_of_blocks;i++){

		rem_size=rem_size+blockSize[i];
	}

	for(int i=0;i<num_of_pro;i++){

		if ((alloc[i]==-1) && (processSize[i]<=rem_size)){

			alloc[i]=-10;
		}
	}

	printf("\nThe first fit memory allocation is as follows:\n");

	printf("Process number\tProcess Size\tBlock number\tInternal fragment size(if any)\n");

	for(int i=0;i<num_of_pro;i++){

		if(alloc[i]>=0){

			printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,processSize[i],alloc[i]+1,blockSize[alloc[i]]);
		}

		else if(alloc[i]==-10){

			printf("%d\t\t%d\t\tExternal fragmentation\n",i+1,processSize[i]);
		}

		else{

			printf("%d\t\t%d\t\tMemory not allocated\n",i+1,processSize[i]);
		}
	}


	
}

void worstfit(int blockSize[], int num_of_blocks, int processSize[], int num_of_pro){

	int bs_dup[num_of_blocks],cur;

	for(int i=0;i<num_of_blocks;i++){

		bs_dup[i]=blockSize[i];
	}


	int alloc[num_of_pro];

	int temp;

	for(int i=0;i<num_of_pro;i++){

		alloc[i]=-1;
	}

	for (int i=0;i<num_of_blocks-1;i++){

		for(int j=i+1;j<num_of_blocks;j++){

			if(blockSize[i]<blockSize[j]){

				temp=blockSize[i];

				blockSize[i]=blockSize[j];

				blockSize[j]=temp;

			}
		}
	}


	for (int i=0;i<num_of_pro;i++){
		 
		 for (int j=0; j<num_of_blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                alloc[i] = j;

                  for(int x=0;x<num_of_blocks;x++){

					if(blockSize[j]==bs_dup[x]){

						bs_dup[x] -= processSize[i];

						
					}
				}
                 
 
                blockSize[j] -= processSize[i];

              
                 break;
            }
        }
	}


	int rem_size=0;

	for(int i=0;i<num_of_blocks;i++){

		rem_size=rem_size+blockSize[i];
	}

	for(int i=0;i<num_of_pro;i++){

		if ((alloc[i]==-1) && (processSize[i]<=rem_size)){

			alloc[i]=-10;
		}
	}


	printf("\nThe worst fit memory allocation is as follows:\n");

	printf("Process number\tProcess Size\tBlock number\tInternal fragment size(if any)\n");

	for(int i=0;i<num_of_pro;i++){

		if(alloc[i]>=0){



				for(int j=0;j<num_of_blocks;j++){

					if(blockSize[alloc[i]]==bs_dup[j]){

						cur=j;

						
					}
				}

				
			

			printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,processSize[i],cur+1,blockSize[alloc[i]]);
		}

			
		

		else if(alloc[i]==-10){

			printf("%d\t\t%d\t\tExternal fragmentation\n",i+1,processSize[i]);
		}

		else{

			printf("%d\t\t%d\t\tMemory not allocated\n",i+1,processSize[i]);
		}
	}


	
}

int main(){
	int num_of_blocks=5,num_of_pro=5;

	int blockSize[num_of_blocks],blockSize_f[num_of_blocks],blockSize_w[num_of_blocks];

	for(int i=0;i<num_of_blocks;i++){
		
		blockSize[i]=(i+1)*100;

		blockSize_f[i]=(i+1)*100;

		blockSize_w[i]=(i+1)*100;
	}

	for(int i=0;i<num_of_blocks;i++){

		printf("Block:%d   Size:%d\n",(i+1),blockSize[i]);
	}


	int processSize[num_of_pro];

	processSize[0]=250;

	processSize[1]=199;

	processSize[2]=275;

	processSize[3]=10000;

	processSize[4]=320;

	for(int i=0;i<num_of_pro;i++){

		printf("Process_number:%d   Size:%d\n",(i+1),processSize[i]);
	}

	firstfit(blockSize, num_of_blocks, processSize, num_of_pro);
	
	bestfit(blockSize_w, num_of_blocks, processSize, num_of_pro);
	
	worstfit(blockSize_f, num_of_blocks, processSize, num_of_pro);

	return(0);


}