/////// Derek Yang 63118832
/////// James Kim 59088715

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int sockfd, port, w;
	struct sockaddr_in serveraddr;
	struct hostent *server;

	char buffer[256];

	if (argc < 3) {
		printf("Missing Address Name or Port Number\n");
		exit(1);
	}

	port = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0){
		printf("Could not Open Socket\n");
	exit(1);
	}

	server = gethostbyname(argv[1]);
	if (server == NULL) {
		printf("Host Does Not Exist\n");
		exit(0);
	}

	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
	serveraddr.sin_port = htons(port);

	if (connect(sockfd,(struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0){ 
		printf("Could Not Connect\n");
	exit(1);
	}		

   	do{
		printf("> ");
    	bzero(buffer,256);
    	fgets(buffer,255,stdin);
    	if ((w = write(sockfd,buffer,strlen(buffer))) < 0){
         	printf("Could Not Write to Socket\n");
		exit(1);
		}

    	bzero(buffer,256);
    	if ((w = read(sockfd,buffer,255)) < 0){ 
         	printf("Could Not Read From Socket\n");
		exit(1);
		}
	
		printf("%s\n",buffer);	
	} while (strcmp(buffer, "") != 0);
	close(sockfd);
	return 0;
}