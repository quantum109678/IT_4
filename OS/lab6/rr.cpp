#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

struct job{

	int arrival,bur,com,tot,wai,bur_temp;
};

bool helper(job p1,job p2){

	return (p1.arrival<p2.arrival);
}

int Comp_time=0;
queue <int> q;

int main(){

	int n,tq,count=0;

	cout<<"Enter number of processes:\n";

	cin>>n;

	cout<<"Enter the Time Quantum: ";
	cin>>tq;

	job arr[n];

	cout<<"Enter the arrival time and burst time for each job:\n";

	for(int i=0;i<n;i++){

		cout<<"Enter arrival time of process "<<i+1<<":\t";

		cin>>arr[i].arrival;

		cout<<"Enter burst time of process "<<i+1<<":\t";

		cin>>arr[i].bur;
		arr[i].bur_temp=arr[i].bur;
	}

	sort(arr,arr+n,helper);

	for(int i=0;i<n;++i){
		q.push(i);
	}

	static int comp_time=arr[0].arrival;
	int i=q.front();
	while(!q.empty()){
		i=q.front();
		q.pop();
		cout<<i+1<<" ";
		if(arr[i].bur<=tq){
			comp_time+=arr[i].bur;
			arr[i].com=comp_time;
			arr[i].bur=0;
		}
		else{
			comp_time+=tq;
			arr[i].com+=tq;
			arr[i].bur-=tq;

		}
		if(arr[i].bur!=0)
			q.push(i);

		++count;
	}

	for(int i=0;i<n;i++){

		arr[i].tot=arr[i].com-arr[i].arrival;

	}

	for(int i=0;i<n;i++){

		arr[i].wai=arr[i].tot-arr[i].bur_temp;

	}
	
	cout<<"The scheduling is as follows:\n";

	cout<<"Proc_numb Arri_time Bur_time Comp_time Tot_time Wait_time\n";

	for(int i=0;i<n;i++){

		cout<<"\t"<<i+1<<"\t"<<arr[i].arrival<<"\t"<<arr[i].bur_temp<<"\t"<<arr[i].com<<"\t"<<arr[i].tot<<"\t"<<arr[i].wai<<"\n";
		
	}
	cout<<"Context Switches: "<<count<<"\n";
}