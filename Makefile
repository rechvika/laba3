CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
INCLUDES = -Iinclude


SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin


SRC_FILES = $(SRC_DIR)/main.c \
            $(SRC_DIR)/dlist.c \
            $(SRC_DIR)/io_operators.c \
            $(SRC_DIR)/publication.c\
			$(SRC_DIR)/merge_sort.c\
			$(SRC_DIR)/comb_sort.c\
			$(SRC_DIR)/argument_parser.c

HEADER_FILES = $(INCLUDE_DIR)/dlist.h \
           $(INCLUDE_DIR)/io_operators.h \
           $(INCLUDE_DIR)/publication.h\
		   $(INCLUDE_DIR)/comb_sort.h \
           $(INCLUDE_DIR)/argument_parser.h\
		   $(INCLUDE_DIR)/merge_sort.h 

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))


TARGET = $(BIN_DIR)/program

all: $(TARGET)


$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(HEADER_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/dlist.o: $(SRC_DIR)/dlist.c $(INCLUDE_DIR)/dlist.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJ_DIR)/io_operators.o: $(SRC_DIR)/io_operators.c $(INCLUDE_DIR)/io_operators.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJ_DIR)/publication.o: $(SRC_DIR)/publication.c $(INCLUDE_DIR)/publication.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)


clean-all:
	rm -rf $(OBJ_DIR) $(BIN_DIR)


run: $(TARGET)
	./$(TARGET)


debug: CFLAGS += -g -O0
debug: clean $(TARGET)

release: CFLAGS += -O2 -DNDEBUG
release: clean $(TARGET)


depend:
	$(CC) -MM $(INCLUDES) $(SRC_FILES) > Makefile.deps

.PHONY: all clean clean-all run debug release show help

