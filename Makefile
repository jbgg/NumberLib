
PROG=test
OBJS= number.o main.o

CC=gcc
CFLAGS=

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


clean :
	rm -rf $(OBJS) $(PROG)
	@rm -rf .*~ *~


