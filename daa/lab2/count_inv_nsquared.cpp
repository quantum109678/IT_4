#include <iostream>

using namespace std;

int main(){

	int arr[]={5,8,2,6,1};

	static int count=0;

	int n=sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<n-1;i++){

		for(int j=i+1;j<n;j++){

			if(arr[i]>arr[j]){

				++count;
			}
		}



	}

	cout<<count;
}