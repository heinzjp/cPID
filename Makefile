CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -fPIC
BUILD_DIR = build
LIB = $(BUILD_DIR)/libcPID.so
LIB_INSTALL_DIR = /usr/local/lib
INCLUDE_INSTALL_DIR = /usr/local/include

SRC = src/cPID.c
OBJ = $(BUILD_DIR)/cPID.o

all: $(LIB) examples

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ): $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJ)
	$(CC) -shared -o $@ $^

examples: $(LIB)
	$(CC) examples/example.c -o $(BUILD_DIR)/example -Iinclude -L$(BUILD_DIR) -lcPID

install: $(LIB)
	sudo cp $(LIB) $(LIB_INSTALL_DIR)
	sudo cp include/cPID.h $(INCLUDE_INSTALL_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean examples install
