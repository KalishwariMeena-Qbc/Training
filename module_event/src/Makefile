# -*- Makefile -*- 

#target : dependencies
#	action
IDIR=../include
CC= gcc
CFLAGS = -I$(IDIR)  -Wall 

ODIR=../bin

_DEPS = event_manager.h module.h 
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = event_manager.o module.o init.o  
OBJ= $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

init: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm -f *.o init
