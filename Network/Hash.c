#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ip_parsing.h"

#define size 10

char ip_addr[16];

typedef struct nodes{
	int fd;
	int port;
	int ip;
	struct nodes *next;
}node;

node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

int socket(int ip, int port)
{
	static int fd = 3;
    
	node *newNode = malloc(sizeof(node));
	newNode->fd = fd;
	newNode->port = port;
	newNode ->ip = ip;
    	newNode->next = NULL;

    
    	int key = fd % size;

    
    	if(chain[key] == NULL)
        	chain[key] = newNode;
    
    	else {
    	        
        	node *temp = chain[key];
        	while(temp-> next != NULL) {
            		temp = temp->next;
        	}

        	temp->next = newNode;
    	}
	fd++;
}

void search(int sock_fd)
{
    	int i;
	char ip_addr[16],*p;
    	for(i = 0; i < size; i++) {
        	node *temp = chain[i];
        	while(temp) {
			if(temp->fd == sock_fd) {
				printf("chain[%d]-->",i);
				p = numTostr(temp->ip,ip_addr);
           			printf("Ip: %s -->",ip_addr);
				printf("Port: %d ",temp->port);
				break;
			}
            		temp = temp->next;
        	}
        	printf("\n");
    	}	
}

int main()
{
	char ch;
	int sock_fd;
    	init();
	do {
		unsigned int ip=0;
		int port = 0;
		char ip_addr[16];
		printf("\nPort:");
		scanf("%d",&port);
		printf("\nIp_addr:");
		scanf("%s",ip_addr);
		ip = strTonum(ip_addr); 
		printf("Ip: %u Port: %d",ip,port);
		socket(ip,port);
		printf("\nDo you wanna continue[y/n]:");
		scanf("%s",&ch);
	} while(ch=='y');
	printf("Enter the socket fd to search greater than 2: ");
	scanf("%d",&sock_fd);
	search(sock_fd);	 	
	
    	return 0;
}
