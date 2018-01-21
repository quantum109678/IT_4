#include <stdio.h>

void Hanoi_sol(int n, char source,char inter,char dest){

    if(n==1){

        printf("Moving disc 1 from %c to %c\n",source,dest);

        return;
    }

    Hanoi_sol(n-1,source,dest,inter);

    printf("Moving disc %d from %c to %c\n",n,source,dest);

    Hanoi_sol(n-1,inter,source,dest);


}

int main(){

    int n;

    printf("Enter number of discs");

    scanf("%d",&n);

    Hanoi_sol(n,'A','B','C');

    return(0);
}