#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct activity{

	int st,fi;
};

bool compare(activity a1,activity a2){

	return(a1.fi<a2.fi);

}

void scheduling(activity arr[],int n){

	sort(arr,arr+n,compare);

	int i=0;

	printf("The following intervals are selected:\n");

	printf("(%d,%d)",arr[i].st,arr[i].fi);

	for(int j=1;j<n;j++){

		if(arr[j].st>arr[i].fi){

			printf("(%d,%d)",arr[j].st,arr[j].fi);

			i=j;

		}
	}


}


int main(){

	int n;

	printf("Enter the number of intervals:");

	scanf("%d",&n);

	activity arr[n];

	printf("Enter the intervals:\n");

	for(int i=0;i<n;i++){

		printf("Enter start time of %d interval:\t",i);

		scanf("%d",&arr[i].st);

		printf("Enter end time of %d interval:\t",i);

		scanf("%d",&arr[i].fi);
	}

	scheduling(arr,n);
}