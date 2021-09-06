#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "event_manager.h"
#include "module.h"

int main(void)
{
	char ch;
	int total_module,total_events,event;
	
	printf("\nEnter the no of module and events:");
	scanf("%d %d",&total_module,&total_events);
	int module_id=1;
	
	while(module_id<=total_module) {
		module_init(module_id,total_module,total_events);	
		module_id++;	
	}

	do {
		printf("\nEnter a event to occur:");
		scanf("%d",&event);
		event_run(event);
		printf("\nTo continue type[y/n]:");
		scanf("%s",&ch);
	} while(ch=='y');
	event_unregister();
	return 0;
}

