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

int main(int argc, char** argv)
{
     	int sockfd, newsockfd, port;
     	socklen_t clilen;
     	char buffer[256];
     	struct sockaddr_in serveraddr, clientaddr;
     	int w;

     	if (argc < 2) {
     	    printf("Missing Port Number\n");
     	    exit(1);
     	}

     	sockfd = socket(AF_INET, SOCK_STREAM, 0);
     	if (sockfd < 0){ 
		printf("Can't Open Socket\n");
		exit(1);
		}

     	bzero((char *) &serveraddr, sizeof(serveraddr));
     	port = atoi(argv[1]);
     	serveraddr.sin_family = AF_INET;
     	serveraddr.sin_addr.s_addr = INADDR_ANY;
     	serveraddr.sin_port = htons(port);

     	if (bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0){ 
        	printf("Could not Bind\n");
		exit(1);
		}

     	printf("Address server started\n");
	while(1){
		listen(sockfd,5);
		clilen = sizeof(clientaddr);
		newsockfd = accept(sockfd, (struct sockaddr *) &clientaddr, &clilen);
		if (newsockfd < 0){ 
			error("Could not Accept\n");
		exit(1);
		}

		while(2){
			bzero(buffer,256);
				if ((w = read(newsockfd,buffer,255)) < 0){
				error("Could not Read From Socket\n");
				exit(1);
			}			

			if(strncmp(buffer, "+++", 3) == 0)
				break;
			else if(strncmp(buffer, "harris@ics.uci.edu", 18) == 0){
				printf("%s",buffer);
				w = write(newsockfd, "Ian G. Harris", 13);
			}	
			else if(strncmp(buffer, "joe@cnn.com", 11) == 0){
				printf("%s",buffer);
				w = write(newsockfd, "Joe Smith", 9);
			}
			else if(strncmp(buffer, "jane@slashdot.org", 17) == 0){
				printf("%s",buffer);
				w = write(newsockfd, "Jane Smith", 10);
			}
			else{
				printf("%s",buffer);
				w = write(newsockfd, "unknown", 7);
			}
		}
		close(newsockfd);
	}
	close(sockfd);
	
	return 0;
}