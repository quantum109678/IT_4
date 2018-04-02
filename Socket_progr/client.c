#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_PORT 5576

int main(int argc,char **argv){

	char filename[80],word[80];

	struct sockaddr_in servaddr;

	int sockfd;

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family=AF_INET;

	servaddr.sin_port=htons(SERV_PORT);

	//inet_pton (AF_INET,argv[1],&servaddr.sin_addr);

	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

	printf("Type the word\n");

	read(sockfd,filename,80);

	printf("%s\n",filename);

	scanf("%s",word);

	write(sockfd,word,80);



	close(sockfd);

	return 0;
}