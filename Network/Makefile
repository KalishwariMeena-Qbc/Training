# -*- Makefile -*- 

#target : dependencies
#	action
CC= gcc
CFLAGS = -I$(IDIR)  -Wall 
DEPS = ip_parsing.h
OBJ = ip_parsing.o Hash.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hashing : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm -f *.o hashing
