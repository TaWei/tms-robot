// sample code taken from: http://www.thegeekstuff.com/2011/12/c-socket-programming/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    int check = 0;
    int n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr; 

    char sendBuff[1025];
    time_t ticks; 

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10); 

    while(1)
    {
    	check = 0;
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 

        snprintf(sendBuff, sizeof(sendBuff), "Please enter path to follow! A, B, or C?\n");
        write(connfd, sendBuff, strlen(sendBuff));
        
        while (check == 0) {
        	check = 1;
        	n = read(connfd, recvBuff, sizeof(recvBuff)-1);
       		recvBuff[n] = 0;
        	if(fputs(recvBuff, stdout) == EOF)
        	{
            	printf("\n Error : Fputs error\n");
        	}
        	
      	  	if (strcmp(recvBuff,"A\n") == 0) {
        		snprintf(sendBuff, sizeof(sendBuff), "Moving to A!\n");
      	  		write(connfd, sendBuff, strlen(sendBuff));
        	} else if ((strcmp(recvBuff,"B\n") == 0)) {
        		snprintf(sendBuff, sizeof(sendBuff), "Moving to B!\n");
        		write(connfd, sendBuff, strlen(sendBuff));
        	} else if ((strcmp(recvBuff,"C\n") == 0)) {
        		snprintf(sendBuff, sizeof(sendBuff), "Moving to C!\n");
        		write(connfd, sendBuff, strlen(sendBuff));
        	} else {
        		snprintf(sendBuff, sizeof(sendBuff), "Wrong command dummy! Enter Again!\n");
        		write(connfd, sendBuff, strlen(sendBuff));
        		check = 0;
        	}
		}
		
        close(connfd);
        sleep(1);
     }
     
     printf("ERROR!");
}