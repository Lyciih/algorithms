cc = gcc
CFLAG = -I include -Wall
SRCS = $(wildcard ./src/*.c)
OBJS = \
	obj/algorithms.o \


all: test


test: test.c algorithms.a
	$(cc) $(CFLAG) -o test $^

%.a : $(OBJS)
	ar -rcs algorithms.a $^

obj/%.o : src/%.c
	$(cc) $(CFLAG) -c -o $@ $<
	

.PHONY: clean run

clean:
	rm -f *.exe *.a *.out *.elf obj/*.o
run:
	./test
