# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 00:21:40 by shinsaeki         #+#    #+#              #
#    Updated: 2024/06/09 13:54:58 by shinsaeki        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(shell pkg-config --cflags cunit)
LDFLAGS = $(shell pkg-config --libs cunit)

SRC_DIR = src
LIBC_DIR = $(SRC_DIR)/libc_functions
ADDITIONAL_DIR = $(SRC_DIR)/additional_functions
TEST_DIR = test
BUILD_DIR = build

LIBC_SRC_FILES = $(LIBC_DIR)/ft_isalpha.c \
			$(LIBC_DIR)/ft_islower.c \
			$(LIBC_DIR)/ft_isupper.c \
			$(LIBC_DIR)/ft_isdigit.c \
			$(LIBC_DIR)/ft_isalnum.c \
			$(LIBC_DIR)/ft_tolower.c \
			$(LIBC_DIR)/ft_toupper.c \
			$(LIBC_DIR)/ft_strlen.c \
			$(LIBC_DIR)/ft_strchr.c \
			$(LIBC_DIR)/ft_strrchr.c \
			$(LIBC_DIR)/ft_strncmp.c \
			$(LIBC_DIR)/ft_memchr.c \
			$(LIBC_DIR)/ft_memcmp.c \
			$(LIBC_DIR)/ft_memset.c \
			$(LIBC_DIR)/ft_bzero.c \
			$(LIBC_DIR)/ft_memcpy.c \
			$(LIBC_DIR)/ft_memmove.c \
			$(LIBC_DIR)/ft_strlcpy.c \
			$(LIBC_DIR)/ft_strlcat.c \
			$(LIBC_DIR)/ft_strnstr.c \
			$(LIBC_DIR)/ft_atoi.c \
			$(LIBC_DIR)/ft_calloc.c \
			$(LIBC_DIR)/ft_strdup.c
ADDITIONAL_SRC_FILES = $(ADDITIONAL_DIR)/ft_putchar_fd.c \
			$(ADDITIONAL_DIR)/ft_putstr_fd.c \
			$(ADDITIONAL_DIR)/ft_putendl_fd.c \
			$(ADDITIONAL_DIR)/ft_putnbr_fd.c

LIBC_TEST_FILES = $(TEST_DIR)/test_libc_functions.c
ADDITIONAL_TEST_FILES = $(TEST_DIR)/test_additional_functions.c
LIBC_OBJ_FILES = $(LIBC_SRC_FILES:.c=.o) $(LIBC_TEST_FILES:.c=.o)
ADDITIONAL_OBJ_FILES = $(ADDITIONAL_SRC_FILES:.c=.o) $(ADDITIONAL_TEST_FILES:.c=.o)

LIBC_TARGET = $(BUILD_DIR)/libc_functions_test
ADDITIONAL_TARGET = $(BUILD_DIR)/additional_functions_test

all : $(LIBC_TARGET) $(ADDITIONAL_TARGET)

$(LIBC_TARGET): $(LIBC_OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(LIBC_TARGET) $(LIBC_OBJ_FILES) $(LDFLAGS)

$(ADDITIONAL_TARGET): $(ADDITIONAL_OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(ADDITIONAL_TARGET) $(ADDITIONAL_OBJ_FILES) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) *.o $(LIBC_DIR)/*.o $(ADDITIONAL_DIR)/*.o $(TEST_DIR)/*.o

.PHONY: all clean