#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;



struct job{

	int arrival,bur,com,tot,wai,sch;
};

bool helper(job p1,job p2){

	return (p1.arrival<p2.arrival);
}

int get_min(job arr[],int n){

	int local_min=100,cur;

	for(int i=0;i<=n;i++){

		if(arr[i].sch!=1){

			if(local_min>arr[i].bur){

				local_min=arr[i].bur;

				cur=i;

			}
		}


	}

	return (cur);
}

int main(){

	int n;

	static int comp_time=0;

	cout<<"Enter number of processes:\n";

	cin>>n;

	job arr[n];

	cout<<"Enter the arrival time and burst time for each job:\n";

	for(int i=0;i<n;i++){

		cout<<"Enter arrival time of process "<<i+1<<":\t";

		cin>>arr[i].arrival;

		cout<<"Enter burst time of process "<<i+1<<":\t";

		cin>>arr[i].bur;
	}

	sort(arr,arr+n,helper);

	int min_job;

	int i=0,j=0;

	while(i<n){

		while(arr[j].arrival<comp_time  && j+1<n){

			++j;
		}

		//cout<<j;

		min_job=get_min(arr,j);

		//cout<<min_job;

		arr[min_job].com=comp_time+arr[min_job].bur;

		comp_time=arr[min_job].com;

		arr[min_job].sch=1;

		i++;
	}


	for(int i=0;i<n;i++){

		arr[i].tot=arr[i].com-arr[i].arrival;

	}

	for(int i=0;i<n;i++){

		arr[i].wai=arr[i].tot-arr[i].bur;

	}


	

	

	cout<<"The scheduling is as follows:\n";

	cout<<"Proc_numb Arri_time Bur_time Comp_time Tot_time Wait_time\n";

	for(int i=0;i<n;i++){

		cout<<"\t"<<i+1<<"\t"<<arr[i].arrival<<"\t"<<arr[i].bur<<"\t"<<arr[i].com<<"\t"<<arr[i].tot<<"\t"<<arr[i].wai<<"\n";

		
	}
}