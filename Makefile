CC = gcc
CFLAGS = -Wall -Wextra -std=c90 -pedantic
TARGET = publication_sort

SRCS = publication.c\
main.c\
io_operators.c\
dllist.c\
comb_sort.c\
argument_parser.c

OBJS = $(SRCS:.c=.o)

HEADER = publication.h\
io_operators.h\
dllist.h\
comb_sort.h\
argument_parser.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	rm -f $(OBJS) $(TARGET)

rebuild: clean all 

.PHONY: all clean rebuild