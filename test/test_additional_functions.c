/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_additional_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:22:35 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/09 14:52:08 by shinsaeki        ###   ########.fr       */
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

void test_ft_substr(void)
{
	char *result;

	// Test case 1: Normal case
	result = ft_substr("Hello, World!", 7, 5);
	CU_ASSERT_STRING_EQUAL(result, "World");
	free(result);

	// Test case 2: start index is greater than string length
	result = ft_substr("Hello", 10, 3);
	CU_ASSERT_STRING_EQUAL(result, "");
	free(result);

	// Test case 3: length exceeds the remaining string
	result = ft_substr("Hello", 1, 10);
	CU_ASSERT_STRING_EQUAL(result, "ello");
	free(result);

	// Test case 4: start index is exactly string length
	result = ft_substr("Hello", 5, 3);
	CU_ASSERT_STRING_EQUAL(result, "");
	free(result);

	// Test case 5: empty string input
	result = ft_substr("", 0, 5);
	CU_ASSERT_STRING_EQUAL(result, "");
	free(result);

	// Test case 6: start index 0 and length 0
	result = ft_substr("Hello", 0, 0);
	CU_ASSERT_STRING_EQUAL(result, "");
	free(result);

	// Test case 7: start index 0 and length equal to string length
	result = ft_substr("Hello", 0, 5);
	CU_ASSERT_STRING_EQUAL(result, "Hello");
	free(result);

	// Test case 8: NULL input
	result = ft_substr(NULL, 0, 5);
	CU_ASSERT_PTR_NULL(result);
}

void test_ft_strjoin(void)
{
	char *result;

	// Test case 1: Normal case
	result = ft_strjoin("Hello, ", "World!");
	CU_ASSERT_STRING_EQUAL(result, "Hello, World!");
	free(result);

	// Test case 2: s1 is an empty string
	result = ft_strjoin("", "World!");
	CU_ASSERT_STRING_EQUAL(result, "World!");
	free(result);

	// Test case 3: s2 is an empty string
	result = ft_strjoin("Hello, ", "");
	CU_ASSERT_STRING_EQUAL(result, "Hello, ");
	free(result);

	// Test case 4: both s1 and s2 are empty strings
	result = ft_strjoin("", "");
	CU_ASSERT_STRING_EQUAL(result, "");
	free(result);

	// Test case 5: s1 is NULL
	result = ft_strjoin(NULL, "World!");
	CU_ASSERT_PTR_NULL(result);

	// Test case 6: s2 is NULL
	result = ft_strjoin("Hello, ", NULL);
	CU_ASSERT_PTR_NULL(result);

	// Test case 7: both s1 and s2 are NULL
	result = ft_strjoin(NULL, NULL);
	CU_ASSERT_PTR_NULL(result);
}

void test_ft_strtrim(void)
{
	char *result;

	// Test case 1: Normal case with leading and trailing characters to trim
	result = ft_strtrim("  Hello, World!  ", " ");
	CU_ASSERT_STRING_EQUAL(result, "Hello, World!");
	free(result);

	// Test case 2: Leading characters to trim
	result = ft_strtrim("!!Hello, World!", "!");
	CU_ASSERT_STRING_EQUAL(result, "Hello, World");
	free(result);

	// Test case 3: Trailing characters to trim
	result = ft_strtrim("Hello, World!@@", "@");
	CU_ASSERT_STRING_EQUAL(result, "Hello, World!");
	free(result);

	// Test case 4: Both leading and trailing characters to trim
	result = ft_strtrim("***Hello, World!***", "*");
	CU_ASSERT_STRING_EQUAL(result, "Hello, World!");
	free(result);

	// Test case 5: No characters to trim
	result = ft_strtrim("Hello, World!", "");
	CU_ASSERT_STRING_EQUAL(result, "Hello, World!");
	free(result);

	// Test case 6: Only trim characters
	result = ft_strtrim("$$$$$", "$");
	CU_ASSERT_STRING_EQUAL(result, "");
	free(result);

	// Test case 7: s1 is an empty string
	result = ft_strtrim("", " ");
	CU_ASSERT_STRING_EQUAL(result, "");
	free(result);

	// Test case 8: set is NULL
	result = ft_strtrim("Hello, World!", NULL);
	CU_ASSERT_STRING_EQUAL(result, "Hello, World!");
	free(result);

	// Test case 9: s1 is NULL
	result = ft_strtrim(NULL, " ");
	CU_ASSERT_PTR_NULL(result);
}

void test_ft_split(void)
{
	char **result;
	int i;

	// Test case 1: Normal case with space delimiter
	result = ft_split("Hello World from CUnit", ' ');
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result[0], "Hello");
	CU_ASSERT_STRING_EQUAL(result[1], "World");
	CU_ASSERT_STRING_EQUAL(result[2], "from");
	CU_ASSERT_STRING_EQUAL(result[3], "CUnit");
	CU_ASSERT_PTR_NULL(result[4]);
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	// Test case 2: Delimiter at start and end
	result = ft_split("  Hello  World  ", ' ');
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result[0], "Hello");
	CU_ASSERT_STRING_EQUAL(result[1], "World");
	CU_ASSERT_PTR_NULL(result[2]);
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	// Test case 3: Multiple delimiters between words
	result = ft_split("Hello   World", ' ');
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result[0], "Hello");
	CU_ASSERT_STRING_EQUAL(result[1], "World");
	CU_ASSERT_PTR_NULL(result[2]);
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	// Test case 4: No delimiters
	result = ft_split("HelloWorld", ' ');
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result[0], "HelloWorld");
	CU_ASSERT_PTR_NULL(result[1]);
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	// Test case 5: Only delimiters
	result = ft_split("     ", ' ');
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_PTR_NULL(result[0]);
	free(result);

	// Test case 6: Empty string
	result = ft_split("", ' ');
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_PTR_NULL(result[0]);
	free(result);

	// Test case 7: s is NULL
	result = ft_split(NULL, ' ');
	CU_ASSERT_PTR_NULL(result);

	// Test case 8: Delimiter not in string
	result = ft_split("HelloWorld", ',');
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result[0], "HelloWorld");
	CU_ASSERT_PTR_NULL(result[1]);
	for (i = 0; result[i]; i++)
		free(result[i]);
	free(result);
}

void test_ft_itoa(void)
{
	char *result;

	// Test case 1: Positive number
	result = ft_itoa(12345);
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result, "12345");
	free(result);

	// Test case 2: Negative number
	result = ft_itoa(-12345);
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result, "-12345");
	free(result);

	// Test case 3: Zero
	result = ft_itoa(0);
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result, "0");
	free(result);

	// Test case 4: Smallest negative integer
	result = ft_itoa(-2147483648);
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result, "-2147483648");
	free(result);

	// Test case 5: Largest positive integer
	result = ft_itoa(2147483647);
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result, "2147483647");
	free(result);
}

char sample_map_func(unsigned int i, char c)
{
	return c + i;
}

void test_ft_strmapi(void)
{
	char *result;

	// Test case 1: Normal case
	result = ft_strmapi("abc", sample_map_func);
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result, "ace");
	free(result);

	// Test case 2: Empty string
	result = ft_strmapi("", sample_map_func);
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_STRING_EQUAL(result, "");
	free(result);

	// Test case 3: NULL string
	result = ft_strmapi(NULL, sample_map_func);
	CU_ASSERT_PTR_NULL(result);

	// Test case 4: NULL function
	result = ft_strmapi("abc", NULL);
	CU_ASSERT_PTR_NULL(result);
}

void sample_iteri_func(unsigned int i, char *c)
{
	*c = *c + i;
}

void test_ft_striteri(void)
{
	char str[100];

	// Test case 1: Normal case
	strcpy(str, "abc");
	ft_striteri(str, sample_iteri_func);
	CU_ASSERT_STRING_EQUAL(str, "ace");

	// Test case 2: Empty string
	strcpy(str, "");
	ft_striteri(str, sample_iteri_func);
	CU_ASSERT_STRING_EQUAL(str, "");

	// Test case 3: NULL string
	ft_striteri(NULL, sample_iteri_func);
	// Since there's no change, no need for assert

	// Test case 4: NULL function
	strcpy(str, "abc");
	ft_striteri(str, NULL);
	CU_ASSERT_STRING_EQUAL(str, "abc"); // The string should remain unchanged
}

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

	if (NULL == CU_add_test(pSuite, "test of ft_substr()", test_ft_substr) ||
		NULL == CU_add_test(pSuite, "test of ft_strjoin()", test_ft_strjoin) ||
		NULL == CU_add_test(pSuite, "test of ft_strtrim()", test_ft_strtrim) ||
		NULL == CU_add_test(pSuite, "test of ft_split()", test_ft_split) ||
		NULL == CU_add_test(pSuite, "test of ft_itoa()", test_ft_itoa) ||
		NULL == CU_add_test(pSuite, "test of ft_strmapi()", test_ft_strmapi) ||
		NULL == CU_add_test(pSuite, "test of ft_striteri()", test_ft_striteri) ||
		NULL == CU_add_test(pSuite, "test of ft_putchar_fd()", test_ft_putchar_fd) ||
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