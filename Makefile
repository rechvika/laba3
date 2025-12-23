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
            $(SRC_DIR)/publication.c \
            $(SRC_DIR)/merge_sort.c \
            $(SRC_DIR)/comb_sort.c \
            $(SRC_DIR)/argument_parser.c

HEADER_FILES = $(INCLUDE_DIR)/dlist.h \
               $(INCLUDE_DIR)/io_operators.h \
               $(INCLUDE_DIR)/publication.h \
               $(INCLUDE_DIR)/comb_sort.h \
               $(INCLUDE_DIR)/argument_parser.h \
               $(INCLUDE_DIR)/merge_sort.h \
               $(INCLUDE_DIR)/comparator.h

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

EXECUTABLE = publication_sort.exe
TARGET = $(BIN_DIR)/$(EXECUTABLE)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^
	@echo Сборка завершена: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)/*.o $(TARGET)
	@echo Файлы очищены
clean-all:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo Директории очищены

.PHONY: all clean clean-all run debug release