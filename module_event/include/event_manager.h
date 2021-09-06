
typedef void (* handler)(int, int);

void event_register(int event,int mod_id,handler mod_func);

int event_run(int event);

void event_unregister(void);
