#SRCS = $(wildcard *.c)
#OBJECT = $(SRCS: .c = .o)
OBJECT = $(patsubst %.c,%o,%(wildcard * .c))
all : test
test : $(OBJECT)
	$(CC) -o $@ $^

