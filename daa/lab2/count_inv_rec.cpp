#include <iostream>
#include <stdio.h>

using namespace std;

int count_inv(int arr[],int temp[],int low,int high);

int count_split_inv(int arr[],int temp[],int low,int mid,int high); 

int count_inv(int arr[],int temp[],int low,int high){

	int inv_count=0;

	int mid=0;

	if(low<high){

		mid=(low+high)/2;

		inv_count=count_inv(arr,temp,low,mid);

		inv_count+=count_inv(arr,temp,mid+1,high);

		inv_count+=count_split_inv(arr,temp,low,mid+1,high);

	}

	return inv_count;
}

int count_split_inv(int arr[], int temp[], int low, int mid, int high){

	int i=low;

	int j=mid;

	int k=low;

	int inv_count=0;

	while((i<=mid-1) && (j<=high)){

	if(arr[i]<=arr[j]){

		temp[k++]=arr[i++];
	}

	else{

		temp[k++]=arr[j++];

		inv_count=inv_count+(mid-i);
	}
}

	while(i<=mid-1){

		temp[k++]=arr[i++];
	}

	while(j<=high){

		temp[k++]=arr[j++];
	}

	for(i=low;i<=high;i++){

		arr[i]=temp[i];
	}

	return inv_count;
}


int main(){

	int arr[]={5,8,2,6,1};

	int temp[5];

	int ans=count_inv(arr,temp,0,4);

	printf("%d",ans);

	
}