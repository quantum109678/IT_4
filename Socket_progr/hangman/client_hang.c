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

	int received_int=0;;

	char letter;

	

	struct sockaddr_in servaddr;

	int sockfd;

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family=AF_INET;

	servaddr.sin_port=htons(SERV_PORT);

	//inet_pton (AF_INET,argv[1],&servaddr.sin_addr);

	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

	read(sockfd,&received_int, sizeof(received_int));

	printf("Size of the word:");

	fprintf(stdout, "%d\n", ntohl(received_int));

	scanf("%c",&letter);

	char converted_letter=htonl(letter);

	write(sockfd,&converted_letter,sizeof(converted_letter));



	close(sockfd);

	return 0;
}