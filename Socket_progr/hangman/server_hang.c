#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define SERV_PORT 5576

int main(int argc,char ** argv){

	char w[5]="there",received_char;

	int len=5;

	int converted_number = htonl(len);


	int count=0;

	struct sockaddr_in servadd,clienadd;

	int listenfd,clilen,connfd;

	listenfd=socket(AF_INET,SOCK_STREAM,0);

	bzero(&servadd,sizeof(servadd));

	servadd.sin_family=AF_INET;

	servadd.sin_port=htons(SERV_PORT);

	bind(listenfd,(struct sockaddr *)&servadd,sizeof(servadd));

	listen(listenfd,1);

	clilen=sizeof(clienadd);

	connfd=accept(listenfd,(struct sockaddr *)&clienadd,&clilen);

	printf("Connection established\n");

	write(connfd,&converted_number,sizeof(converted_number));

	read(connfd,&received_char, sizeof(received_char));


	print("%c\n",)


	

	close(listenfd);



	return 0;
}