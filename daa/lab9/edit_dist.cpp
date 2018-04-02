#include <iostream>
#include <string>

using namespace std;

int min_cost(int x,int y,int z){

	int min=(x<y)?(x<z)?x:z:(y<z)?y:z;

	return min;
}

int edit_dist(string s1,string s2,int m,int n){

	int memo[m+1][n+1];

	for(int i=0;i<=m;i++){

		for(int j=0;j<=m;j++){

			if(i==0) memo[i][j]=j;

			else if(j==0) memo[i][j]=i;

			else if(s1[i-1]==s2[j-1]) memo[i][j]=memo[i-1][j-1];

			else memo[i][j]=1+min_cost(memo[i][j-1],memo[i-1][j],memo[i-1][j-1]);
		}
	}

	return memo[m][n];
}

int main(){

	string s1,s2;

	cout<<"Enter the two strings:";

	cin>>s1>>s2;
	

	cout<<edit_dist(s1,s2,s1.length(),s2.length())<<endl;

	return 0;
}