#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "event_manager.h"

#define CHECK_BIT(data,pos) data & (1 << (pos-1))

typedef struct event_register {
	int event; 
	int module_id;
	handler func_name;
	struct event_register *next;
}event_details;

event_details *head;


void event_register(int event,int mod_id,handler callback)
{	
	event_details *current = head;

	if(current == NULL) {
		current = malloc(sizeof(event_details));
		head = current;
	}
	else {
		event_details *prev = head;
		while(prev ->  next) {
			prev = prev -> next;
		}
		prev -> next = malloc(sizeof(event_details));
		current = prev -> next;
	}
	current -> event = event;
	current -> module_id = mod_id;
	current -> func_name = callback;
	current -> next = NULL;
	printf("\nRegistered\n");
}

int event_run(int event)
{
	event_details *current = head;
	while(current != NULL) {
		if(CHECK_BIT(current->event, event))
			current->func_name(current->module_id, event);		
		current=current->next;
	}
	return 1;
}
	
void event_unregister(void)
{
        event_details *current = head;
        while(current){
                event_details *p = current;
                current = current->next;
                p->next=NULL;
                free(p);
        }

}

