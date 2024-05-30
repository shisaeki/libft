# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 00:21:40 by shinsaeki         #+#    #+#              #
#    Updated: 2024/05/30 18:45:34 by shinsaeki        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(shell pkg-config --cflags cunit)
LDFLAGS = $(shell pkg-config --libs cunit)

SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

SRC_FILES = $(SRC_DIR)/libc_functions/ft_isalpha.c \
			$(SRC_DIR)/libc_functions/ft_islower.c \
			$(SRC_DIR)/libc_functions/ft_isupper.c \
			$(SRC_DIR)/libc_functions/ft_isdigit.c \
			$(SRC_DIR)/libc_functions/ft_isalnum.c \
			$(SRC_DIR)/libc_functions/ft_tolower.c \
			$(SRC_DIR)/libc_functions/ft_toupper.c \
			$(SRC_DIR)/libc_functions/ft_strlen.c \
			$(SRC_DIR)/libc_functions/ft_memset.c \
			$(SRC_DIR)/libc_functions/ft_bzero.c \
			$(SRC_DIR)/libc_functions/ft_memcpy.c
TEST_FILES = $(TEST_DIR)/test_libc_functions.c
OBJ_FILES = $(SRC_FILES:.c=.o) $(TEST_FILES:.c=.o)

TARGET = $(BUILD_DIR)/libc_functions_test

all : $(TARGET)

$(TARGET): $(OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(TARGET) $(OBJ_FILES) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) *.o $(SRC_DIR)/libc_functions/*.o $(TEST_DIR)/*.o

.PHONY: all clean