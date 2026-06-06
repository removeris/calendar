CC := gcc

BUILD_DIR := build
TARGET := $(BUILD_DIR)/calendar.exe

CFLAGS := -Wall -Wextra
CPPFLAGS := -Iinclude

SRC := $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRC))

.PHONY: clean

$(TARGET): $(OBJ)
	@echo "Generating executable $@.."
	@$(CC) $^ -o $@

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $<.."
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	@echo "Deleting $(BUILD_DIR).."
	@rm -rf $(BUILD_DIR)
