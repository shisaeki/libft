# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 00:21:40 by shinsaeki         #+#    #+#              #
#    Updated: 2024/06/09 14:49:12 by shinsaeki        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(shell pkg-config --cflags cunit)
LDFLAGS = $(shell pkg-config --libs cunit)
AR = ar
ARFLAGS = rcs

SRC_DIR = src
LIBC_DIR = $(SRC_DIR)/libc_functions
ADDITIONAL_DIR = $(SRC_DIR)/additional_functions
TEST_DIR = test
BUILD_DIR = build
LIB_DIR = lib

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

ADDITIONAL_SRC_FILES = $(ADDITIONAL_DIR)/ft_substr.c \
			$(ADDITIONAL_DIR)/ft_strjoin.c \
			$(ADDITIONAL_DIR)/ft_strtrim.c \
			$(ADDITIONAL_DIR)/ft_split.c \
			$(ADDITIONAL_DIR)/ft_itoa.c \
			$(ADDITIONAL_DIR)/ft_strmapi.c \
			$(ADDITIONAL_DIR)/ft_striteri.c \
			$(ADDITIONAL_DIR)/ft_putchar_fd.c \
			$(ADDITIONAL_DIR)/ft_putstr_fd.c \
			$(ADDITIONAL_DIR)/ft_putendl_fd.c \
			$(ADDITIONAL_DIR)/ft_putnbr_fd.c

LIBC_OBJ_FILES = $(LIBC_SRC_FILES:.c=.o)
ADDITIONAL_OBJ_FILES = $(ADDITIONAL_SRC_FILES:.c=.o)

LIB_OBJ_FILES = $(LIBC_OBJ_FILES) $(ADDITIONAL_OBJ_FILES)
LIBRARY = $(LIB_DIR)/libft.a

LIBC_TEST_FILES = $(TEST_DIR)/test_libc_functions.c
ADDITIONAL_TEST_FILES = $(TEST_DIR)/test_additional_functions.c

LIBC_TEST_OBJ_FILES = $(LIBC_TEST_FILES:.c=.o)
ADDITIONAL_TEST_OBJ_FILES = $(ADDITIONAL_TEST_FILES:.c=.o)

LIBC_TARGET = $(BUILD_DIR)/libc_functions_test
ADDITIONAL_TARGET = $(BUILD_DIR)/additional_functions_test

all : $(LIBRARY)

$(LIBRARY): $(LIB_OBJ_FILES)
	mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $^

test: $(LIBC_TARGET) $(ADDITIONAL_TARGET)

$(LIBC_TARGET): $(LIBC_TEST_OBJ_FILES) $(LIBRARY)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(ADDITIONAL_TARGET): $(ADDITIONAL_TEST_OBJ_FILES) $(LIBRARY)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR) *.o $(LIBC_DIR)/*.o $(ADDITIONAL_DIR)/*.o $(TEST_DIR)/*.o

.PHONY: all clean test