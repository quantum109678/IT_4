#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct job{

	int arrival,bur,com,tot,wai;
};

bool helper(job p1,job p2){

	return (p1.arrival<p2.arrival);
}

int main(){

	int n;

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

	static int comp_time=arr[0].arrival;

	for(int i=0;i<n;i++){

		arr[i].com=comp_time+arr[i].bur;

		comp_time=arr[i].com;
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