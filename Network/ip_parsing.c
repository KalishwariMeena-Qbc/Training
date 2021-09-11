#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ip_parsing.h"


void reverse(char str[])
{
  int n = strlen(str);

  for (int i = 0; i < n / 2; i++)
  {
    char ch = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = ch;
  }
}

unsigned int strTonum(char des_ip[])
{
	unsigned int ip=0;
	const char s[2] = ".";
	char *token;
	token = strtok(des_ip , s);
	while( token != NULL ) {
     		ip = (ip << 8) | atoi(token);
    		token = strtok(NULL, s);
	}
	return ip;
}

char * numTostr(int ip,char ip_addr[])
{
	//int to string
	int num,x,i=4;
	while(i--) {
		char tmp[4]={0};
		x = ip & 255;
		sprintf(tmp,"%d",x);
		reverse(tmp);
		strcat(ip_addr,tmp);
		ip=ip-x;
		ip=ip>>8;	
		if(i>=1)			
			strcat(ip_addr,".");
	}
	reverse(ip_addr);
	return ip_addr;
}

/*
int main() 
{
	//string to int
	unsigned int ip=0;
	char gateway[16]={0};
	char des_ip[16],*g;
	scanf("%s",des_ip);
	ip = strTonum(des_ip);
	printf("String to Int: %u\n",ip);
	printf("Int to string %s\n",numTostr(ip,gateway));	
	return 0;
}*/
