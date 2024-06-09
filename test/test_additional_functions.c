/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_additional_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:22:35 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/07 15:28:34 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/libft.h"

void test_ft_putchar_fd(void)
{
	int fd;
	char buffer[4] = {0};

	// Basic Test
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putchar_fd('A', fd);
	lseek(fd, 0, SEEK_SET); // ファイルの先頭に戻す
	read(fd, buffer, 1);
	CU_ASSERT_STRING_EQUAL(buffer, "A");
	close(fd);
	remove("testfile.txt");

	// Multiple Text
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putchar_fd('A', fd);
	ft_putchar_fd('B', fd);
	ft_putchar_fd('C', fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 3);
	CU_ASSERT_STRING_EQUAL(buffer, "ABC");
	close(fd);
	remove("testfile.txt");

	// Edge case
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putchar_fd('\0', fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 1);
	CU_ASSERT_EQUAL(buffer[0], '\0');
	close(fd);
	remove("testfile.txt");
}

void test_ft_putstr_fd(void)
{
	int fd;
	char buffer[100] = {0};

	// Basic Test
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putstr_fd("Hello World!", fd);
	lseek(fd, 0, SEEK_SET); // ファイルの先頭に戻す
	read(fd, buffer, 100);
	CU_ASSERT_STRING_EQUAL(buffer, "Hello World!");
	close(fd);
	remove("testfile.txt");

	// Multiple Text
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putstr_fd("Hello", fd);
	ft_putstr_fd(" World", fd);
	ft_putstr_fd("!", fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 100);
	CU_ASSERT_STRING_EQUAL(buffer, "Hello World!");
	close(fd);
	remove("testfile.txt");

	// Edge case
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putstr_fd("", fd);
	lseek(fd, 0, SEEK_SET);
	ssize_t byte_read = read(fd, buffer, 100);
	CU_ASSERT_EQUAL(byte_read, 0);
	close(fd);
	remove("testfile.txt");
}

void test_ft_putendl_fd(void)
{
	int fd;
	char buffer[100] = {0};

	// Basic Test
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putendl_fd("Hello World!", fd);
	lseek(fd, 0, SEEK_SET); // ファイルの先頭に戻す
	read(fd, buffer, 100);
	CU_ASSERT_STRING_EQUAL(buffer, "Hello World!\n");
	close(fd);
	remove("testfile.txt");

	// Multiple Text
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putendl_fd("Hello", fd);
	ft_putendl_fd(" World", fd);
	ft_putendl_fd("!", fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 100);
	CU_ASSERT_STRING_EQUAL(buffer, "Hello\n World\n!\n");
	close(fd);
	remove("testfile.txt");

	// Edge case
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putendl_fd("", fd);
	lseek(fd, 0, SEEK_SET); // ファイルの先頭に戻す
	ssize_t bytes_read = read(fd, buffer, 1); // 改行文字のみを読み取る
	CU_ASSERT_EQUAL(bytes_read, 1);
	CU_ASSERT_EQUAL(buffer[0], '\n'); // 直接バッファの内容を比較
	close(fd);
	remove("testfile.txt");
}

void test_ft_putnbr_fd(void)
{
	int fd;
	char buffer[100] = {0};
	
	// Edge case: 0
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putnbr_fd(0, fd);
	lseek(fd, 0, SEEK_SET); // ファイルの先頭に戻す
	read(fd, buffer, 100);
	CU_ASSERT_STRING_EQUAL(buffer, "0");
	close(fd);
	remove("testfile.txt");

	// Basic Test
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putnbr_fd(12345, fd);
	lseek(fd, 0, SEEK_SET); // ファイルの先頭に戻す
	read(fd, buffer, 100);
	CU_ASSERT_STRING_EQUAL(buffer, "12345");
	close(fd);
	remove("testfile.txt");

	// Multiple Text
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putnbr_fd(-12345, fd);
	lseek(fd, 0, SEEK_SET); // ファイルの先頭に戻す
	read(fd, buffer, 100);
	CU_ASSERT_STRING_EQUAL(buffer, "-12345");
	close(fd);
	remove("testfile.txt");

	// Edge case: INT_MAX
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putnbr_fd(2147483647, fd);
	lseek(fd, 0, SEEK_SET); // ファイルの先頭に戻す
	read(fd, buffer, 100);
	CU_ASSERT_STRING_EQUAL(buffer, "2147483647");
	close(fd);
	remove("testfile.txt");

	// Edge case: INT_MIN
	fd = open("testfile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		CU_FAIL("Failed to open test file");
		return;
	}

	ft_putnbr_fd(-2147483648, fd);
	lseek(fd, 0, SEEK_SET); // ファイルの先頭に戻す
	read(fd, buffer, 100);
	CU_ASSERT_STRING_EQUAL(buffer, "-2147483648");
	close(fd);
	remove("testfile.txt");
}

int main()
{
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	CU_pSuite pSuite = NULL;
	pSuite = CU_add_suite("test_additional_functions", 0, 0);
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(pSuite, "test of ft_putchar_fd()", test_ft_putchar_fd) ||
		NULL == CU_add_test(pSuite, "test of ft_putstr_fd()", test_ft_putstr_fd) ||
		NULL == CU_add_test(pSuite, "test of ft_putendl_fd()", test_ft_putendl_fd) ||
		NULL == CU_add_test(pSuite, "test of ft_putnbr_fd()", test_ft_putnbr_fd))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}