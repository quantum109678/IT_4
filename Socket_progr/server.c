#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define SERV_PORT 5576

int main(int argc,char ** argv){

	char s[80],f[80];

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

	read(connfd,f,80);

	printf("Filename:%s",f);

	close(listenfd);

	return 0;
}