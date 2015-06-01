VPATH = fun1 fun2 fun3 main
OBJECTS = fun1.o fun2.o fun3.o main.o
CFLAGS = -I ./include

test : $(OBJECTS)
	$(CC) -o $@ $^

clean :
	cd fun1 && make clean
	cd fun2 && make clean
	cd fun3 && make clean
	cd main && make clean
	rm -rf *.o
