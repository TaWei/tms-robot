/* BSD Standard Socket Programming Example - UNIX */
#include <stdio.h>
#include <sys/types.h>
#ifdef __WIN32__
# include <winsock2.h>
#else
# include <sys/socket.h>
#endif
#include <netinet/in.h>
#include <arpa/inet.h>
#define SERV_TCP_PORT 59002
#define SERV_HOST_ADDR "127.0.0.1"
#define MAXLINE 512
int written(int fd, char *ptr, int nbytes);
int readline(int fd, char *ptr, int maxlen);
void str_cli(int sockfd);
char *pname;

int main(int argc, char *argv[])
{
  int sockfd;
  struct sockaddr_in serv_addr;
  char choice;
  
  pname = argv[0];
  
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
  serv_addr.sin_port = htons(SERV_TCP_PORT);
  
  if((sockfd = socket(AF_INET, SOCK_STREAM,0)) < 0){
    printf("Client: Can’t Open Stream Socket\n");
  }
  
  printf("Client: Connecting...\n");
  
  if(connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr))<0){
    printf("Client: Can’t Connect to the server\n");
  }
  else{
	printf("Connected. \n");
	char choice = 'f';

	while((choice != 'l') && (choice != 'r') && (choice != 'e')) {
		printf("Choose Left or Right:"" \n");
		printf("1. Left (l)\n");
		printf("2. Right (r)\n");
		printf("3. End (e)\n");
		choice = getchar();
	}

	str_write (sockfd, &choice);

    //str_cli(sockfd);
  }
  exit(0);
}

void str_cli (int sockfd)
{
  int n, i;
  char sendline[MAXLINE], recvline[MAXLINE + 1];
  while(1)
  {
    memset (sendline, 2, 128);
    if(written(sockfd, sendline, 126)!=126){
       printf("strcli:written error on sock\n");
      }
      printf("Line 51: sockfd=%d, recvline=%s\n",sockfd,recvline);
      i = readline(sockfd, recvline, 126);
      printf("Print 2 : Line 51: sockfd=%d, recvline=%s\n",sockfd,recvline);
  }
}

void str_write (int sockfd , char *ptr)
{
	char sendline[MAXLINE];
	memset (sendline, ptr, 1);
	if(written(sockfd, sendline, 1)!=1){
       printf("strcli:written error on sock\n");
    }
}

int readline(int fd, char *ptr, int maxlen)
{
  int n, rc;
  char c;
  //printf("readline start \n");
  for(n = 0; n < maxlen; n++){
     if((rc = read(fd, &c, 1)) == 1){
        *ptr++ = c;
        printf("%c",c);
        if(c=='\n'){
          break;
         }
         else if(rc== 0) {
            if(n== 0) {
              return (0);
             }
             else{
               break;
           }
      }
   }
   else{
   	 printf("read failed\n");
     return (-1);
   }
   printf("\n");
  }
*ptr = 0;
return (n);
 }

int written(int fd, char *ptr, int nbytes)
{
  int nleft, nwritten;
  nleft = nbytes;
  while(nleft > 0) {
    nwritten = write(fd, ptr, nleft);
    if(nwritten <= 0) {
       return(nwritten);
     }
     nleft -= nwritten;
     ptr += nwritten;
}
return(nbytes - nleft);
}
