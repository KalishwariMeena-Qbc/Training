#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "event_manager.h"
#include "module.h"

#define SET_BIT(n,bit) n|=(1<<(bit-1));

void module_init(int mod_id,int m_count,int total_event)
{
	int e_count,fp,p=0,i=0,e; 
	
	printf("\nRegister Module %d's call back function: \n    1.Module_func1 \n    2.Module_func2 \n",mod_id);
	scanf("%d",&fp);
	printf("\nEnter the no of interested events of module %d:",mod_id);
	scanf("%d",&e_count);
	if(e_count<=total_event) {
		printf("\nEnter the no:");
		for(i=0;i<e_count;i++) {
			scanf("%d",&e);
			if(e<=total_event)
				SET_BIT(p,e);
		}
	}
		
	if(fp==1)		
		event_register(p,mod_id,mod_func1);
	else if(fp==2)
		event_register(p,mod_id,mod_func2);
}

void mod_func1(int mod_id, int event_id)
{
	printf("\nModule func 1: Module  %d attended Event %d",  mod_id, event_id); 
}

void mod_func2(int mod_id, int event_id)
{
	printf("\nModule func 2: Module  %d attended Event %d",  mod_id, event_id); 
}
