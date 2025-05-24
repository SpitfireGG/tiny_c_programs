CC := gcc

FLAGS := -Wall -Werror -Wextra 

TARGET := main

SRC_DIR := .

BUILD_DIR := ./build

SRCS := $(SRC_DIR)/main.c

build:
	mkdir -p $(BUILD_DIR) 
	$(CC) $(FLAGS) -o $(BUILD_DIR)/$(TARGET) $(SRCS) -lm # if math libs are used
	$(BUILD_DIR)/$(TARGET)
	mv spk.ppm $(BUILD_DIR)
	$(shell feh) $(BUILD_DIR)/spk.ppm

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(BUILD_DIR)/spk.ppm # cleanup
