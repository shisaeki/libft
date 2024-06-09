/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libc_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:12:02 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/06/09 13:56:11 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/libft.h"

void test_ft_isalpha(void)
{
	CU_ASSERT(ft_isalpha('A') == 1);
	CU_ASSERT(ft_isalpha('z') == 1);
	CU_ASSERT(ft_isalpha('1') == 0);
	CU_ASSERT(ft_isalpha('@') == 0);
}

void test_ft_isdigit(void)
{
	CU_ASSERT(ft_isdigit('1') == 1);
	CU_ASSERT(ft_isdigit('9') == 1);
	CU_ASSERT(ft_isdigit('A') == 0);
	CU_ASSERT(ft_isdigit('@') == 0);
}

void test_ft_isalnum(void)
{
	CU_ASSERT(ft_isalnum('1') == 1);
	CU_ASSERT(ft_isalnum('9') == 1);
	CU_ASSERT(ft_isalnum('A') == 1);
	CU_ASSERT(ft_isalnum('a') == 1);
	CU_ASSERT(ft_isalnum('@') == 0);
}

void test_ft_tolower(void)
{
	CU_ASSERT(ft_tolower('1') == '1');
	CU_ASSERT(ft_tolower('9') == '9');
	CU_ASSERT(ft_tolower('A') == 'a');
	CU_ASSERT(ft_tolower('a') == 'a');
	CU_ASSERT(ft_tolower('@') == '@');
}

void test_ft_toupper(void)
{
	CU_ASSERT(ft_toupper('1') == '1');
	CU_ASSERT(ft_toupper('9') == '9');
	CU_ASSERT(ft_toupper('A') == 'A');
	CU_ASSERT(ft_toupper('a') == 'A');
	CU_ASSERT(ft_toupper('@') == '@');
}

void test_ft_strlen(void)
{
	CU_ASSERT(ft_strlen("abcd") == 4);
	CU_ASSERT(ft_strlen("") == 0);
	CU_ASSERT(ft_strlen("   ") == 3);
}

void test_ft_strchr(void) {
	const char *str = "hello world";

	/* Test finding a character that exists in the string */
	CU_ASSERT_PTR_EQUAL(ft_strchr(str, 'h'), &str[0]);
	CU_ASSERT_PTR_EQUAL(ft_strchr(str, 'o'), &str[4]);
	CU_ASSERT_PTR_EQUAL(ft_strchr(str, 'd'), &str[10]);

	/* Test finding a character that does not exist in the string */
	CU_ASSERT_PTR_NULL(ft_strchr(str, 'z'));

	/* Test finding the null terminator */
	CU_ASSERT_PTR_EQUAL(ft_strchr(str, '\0'), &str[11]);

	/* Test empty string */
	const char *empty_str = "";
	CU_ASSERT_PTR_NULL(ft_strchr(empty_str, 'a'));
	CU_ASSERT_PTR_EQUAL(ft_strchr(empty_str, '\0'), empty_str);
}

void test_ft_strrchr(void) {
	const char *str = "hello world";

	/* Test finding a character that exists in the string */
	CU_ASSERT_PTR_EQUAL(ft_strrchr(str, 'h'), &str[0]);
	CU_ASSERT_PTR_EQUAL(ft_strrchr(str, 'o'), &str[7]);
	CU_ASSERT_PTR_EQUAL(ft_strrchr(str, 'd'), &str[10]);

	/* Test finding a character that does not exist in the string */
	CU_ASSERT_PTR_NULL(ft_strrchr(str, 'z'));

	/* Test finding the null terminator */
	CU_ASSERT_PTR_EQUAL(ft_strrchr(str, '\0'), &str[11]);

	/* Test empty string */
	const char *empty_str = "";
	CU_ASSERT_PTR_NULL(ft_strrchr(empty_str, 'a'));
	CU_ASSERT_PTR_EQUAL(ft_strrchr(empty_str, '\0'), empty_str);
}

void test_ft_strncmp(void) {
	// Compare identical strings
	CU_ASSERT(ft_strncmp("hello", "hello", 5) == 0);

	// First character differs
	CU_ASSERT(ft_strncmp("hello", "world", 5) < 0);

	// First n characters are the same
	CU_ASSERT(ft_strncmp("hello", "helix", 3) == 0);

	// First n characters differ
	CU_ASSERT(ft_strncmp("hello", "helix", 4) > 0);

	// Comparing empty strings
	CU_ASSERT(ft_strncmp("", "", 1) == 0);

	// Partial match comparison
	CU_ASSERT(ft_strncmp("hello", "hell", 4) == 0);
	CU_ASSERT(ft_strncmp("hello", "hell", 5) > 0);

	// n is 0
	CU_ASSERT(ft_strncmp("hello", "world", 0) == 0);
}

void test_ft_memchr(void) {
	const char str[] = "hello, world";

	// Finding 'w' in "hello, world"
	char *result = ft_memchr(str, 'w', strlen(str));
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_EQUAL(*result, 'w');

	// Finding 'z' which is not in the string
	result = ft_memchr(str, 'z', strlen(str));
	CU_ASSERT_PTR_NULL(result);

	// Finding 'h' at the start of the string
	result = ft_memchr(str, 'h', strlen(str));
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_EQUAL(*result, 'h');

	// Finding ',' in the middle of the string
	result = ft_memchr(str, ',', strlen(str));
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_EQUAL(*result, ',');

	// Limiting the search to first 5 characters
	result = ft_memchr(str, 'o', 5);
	CU_ASSERT_PTR_NOT_NULL(result);
	CU_ASSERT_EQUAL(*result, 'o');

	// Limiting the search to first 4 characters, 'o' should not be found
	result = ft_memchr(str, 'o', 4);
	CU_ASSERT_PTR_NULL(result);
}

void test_ft_memcmp(void) {
	// Identical strings
	char str1[] = "hello";
	char str2[] = "hello";
	CU_ASSERT(memcmp(str1, str2, 5) == 0);

	// Different strings
	char str3[] = "hello";
	char str4[] = "world";
	CU_ASSERT(memcmp(str3, str4, 5) != 0);

	// Partially identical strings
	char str5[] = "hello";
	char str6[] = "heLlo";
	CU_ASSERT(memcmp(str5, str6, 2) == 0);
	CU_ASSERT(memcmp(str5, str6, 3) != 0);

	// Zero-length comparison
	CU_ASSERT(memcmp(str3, str4, 0) == 0);
}

void test_ft_memset(void)
{
	// general use case
	char buffer1[10];
	ft_memset(buffer1, 'A', sizeof(buffer1));
	for (size_t i = 0; i < sizeof(buffer1); i++)
		CU_ASSERT(buffer1[i] == 'A');

	// buffer size == 0
	char buffer2[10];
	ft_memset(buffer2, 'B', 0);
	for (size_t i = 0; i < sizeof(buffer2); i++)
		CU_ASSERT(buffer2[i] != 'B');

	// Fill memory with a specific value
	char buffer3[10] = {0};
	memset(buffer3, 0xAB, sizeof(buffer3));
	for (size_t i = 0; i < sizeof(buffer3); i++)
		CU_ASSERT((unsigned char)buffer3[i] == 0xAB);

	// partial memset
	char buffer4[10] = {0};
	ft_memset(buffer4, 'C', 5);
	for (size_t i = 0; i < 5; i++)
		CU_ASSERT(buffer4[i] == 'C');
	for (size_t i = 5; i < 10; i++)
		CU_ASSERT(buffer4[i] == 0);

	// null buffer
	char buffer5[1];
	ft_memset(buffer5, 'D', sizeof(buffer5));
	CU_ASSERT(buffer5[0] == 'D');
}

void test_ft_bzero(void)
{
	// zeroing the entire buffer
	char buffer1[10];
	ft_memset(buffer1, 'A', sizeof(buffer1));
	ft_bzero(buffer1, sizeof(buffer1));
	for (size_t i = 0; i < sizeof(buffer1); i++)
		CU_ASSERT(buffer1[i] == 0);

	// 0 size buffer
	char buffer2[10];
	ft_memset(buffer2, 'A', sizeof(buffer2));
	ft_bzero(buffer2, 0);
	for (size_t i = 0; i < sizeof(buffer2); i++)
		CU_ASSERT(buffer2[i] == 'A');

	// partial bzero
	char buffer3[10];
	ft_memset(buffer3, 'A', sizeof(buffer3));
	ft_bzero(buffer3, 5);
	for (size_t i = 0; i < 5; i++)
		CU_ASSERT(buffer3[i] == 0);
	for (size_t i = 5; i < sizeof(buffer3); i++)
		CU_ASSERT(buffer3[i] == 'A');

	// different buffer size
	char buffer4[20];
	ft_memset(buffer4, 'A', sizeof(buffer4));
	ft_bzero(buffer4, 15);
	for (size_t i = 0; i < 15; i++)
		CU_ASSERT(buffer4[i] == 0);
	for (size_t i = 15; i < sizeof(buffer4); i++)
		CU_ASSERT(buffer4[i] == 'A');

	// 0 buffer
	char buffer5[10] = {0};
	ft_bzero(buffer5, sizeof(buffer5));
	for (size_t i = 0; i < sizeof(buffer5); i++)
		CU_ASSERT(buffer5[i] == 0);
}

void test_ft_memcpy(void)
{
	//simple string copy
	char src1[] = "Hello, World!";
	char dst1[20];
	ft_memcpy(dst1, src1, ft_strlen(src1) + 1); // Include null terminator
	CU_ASSERT_STRING_EQUAL(dst1, "Hello, World!");
}

void test_ft_memmove(void)
{
	char buffer[100];

	// basic case
	char src1[] = "Hello, World!";
	ft_memmove(buffer, src1, strlen(src1) + 1);
	CU_ASSERT_STRING_EQUAL(buffer, "Hello, World!");

	// no overlap
	char src2[] = "1234567890";
	ft_memmove(buffer, src2, 10);
	CU_ASSERT_NSTRING_EQUAL(buffer, "1234567890", 10);

	// overlap (foward)
	char overlap1[] = "abcdefgh";
	ft_memmove(overlap1 + 2, overlap1, 6);
	CU_ASSERT_NSTRING_EQUAL(overlap1, "ababcdef", 8);

	// overlap (backward)
	char overlap2[] = "abcdefgh";
	ft_memmove(overlap2, overlap2 + 2, 6);
	CU_ASSERT_NSTRING_EQUAL(overlap2, "cdefghgh", 8);

	// small buffer case
	char small_src[] = "abc";
	char small_dest[4] = "";
	ft_memmove(small_dest, small_src, 3);
	CU_ASSERT_NSTRING_EQUAL(small_dest, "abc", 3);

	// byte unit
	char byte_src[] = {0x00, 0x01, 0x02, 0x03, 0x04};
	char byte_dest[5] = {0};
	ft_memmove(byte_dest, byte_src, 5);
	CU_ASSERT_NSTRING_EQUAL(byte_dest, byte_src, 5);
}


void test_ft_strlcpy(void)
{
	char dst[20];

	// Test 1: Normal case
	ft_strlcpy(dst, "Hello, World!", sizeof(dst));
	CU_ASSERT_STRING_EQUAL(dst, "Hello, World!");

	// Test 2: dstsize is zero
	ft_memset(dst, 'A', sizeof(dst));  // Fill dst with 'A'
	ft_strlcpy(dst, "Hello, World!", 0);
	CU_ASSERT_EQUAL(dst[0], 'A');  // dst should remain unchanged

	// Test 3: dstsize is smaller than src length
	ft_memset(dst, 0, sizeof(dst));
	ft_strlcpy(dst, "Hello, World!", 6);
	CU_ASSERT_STRING_EQUAL(dst, "Hello");

	// Test 4: src is an empty string
	ft_memset(dst, 0, sizeof(dst));
	ft_strlcpy(dst, "", sizeof(dst));
	CU_ASSERT_STRING_EQUAL(dst, "");

	// Test 5: dstsize is one
	ft_memset(dst, 0, sizeof(dst));
	ft_strlcpy(dst, "Hello, World!", 1);
	CU_ASSERT_STRING_EQUAL(dst, "");  // Only NUL-termination should be in dst

	// Test 6: src is exactly dstsize-1 long
	ft_memset(dst, 0, sizeof(dst));
	ft_strlcpy(dst, "Hello, World!", 14);
	CU_ASSERT_STRING_EQUAL(dst, "Hello, World!");

	// Test 7: src and dst are the same
	char buffer[20] = "Overlap test";
	ft_strlcpy(buffer, buffer, sizeof(buffer));
	CU_ASSERT_STRING_EQUAL(buffer, "Overlap test");
}

void test_ft_strlcat(void)
{
	char dst[30];

	// Test 1: Normal case
	strcpy(dst, "Hello");
	ft_strlcat(dst, ", World!", sizeof(dst));
	CU_ASSERT_STRING_EQUAL(dst, "Hello, World!");

	// Test 2: dstsize is zero
	strcpy(dst, "Hello");
	size_t result = ft_strlcat(dst, ", World!", 0);
	CU_ASSERT_STRING_EQUAL(dst, "Hello");
	CU_ASSERT_EQUAL(result, 8); // "Hello" length (5) + ", World!" length (8)

	strcpy(dst, "Hello");
	result = ft_strlcat(dst, ", World!", 10);
	CU_ASSERT_STRING_EQUAL(dst, "Hello, Wo");
	CU_ASSERT_EQUAL(result, 13); // "Hello" length (5) + ", World!" length (8)

	// Test 4: src is an empty string
	strcpy(dst, "Hello");
	ft_strlcat(dst, "", sizeof(dst));
	CU_ASSERT_STRING_EQUAL(dst, "Hello");

	// Test 5: dst is an empty string
	strcpy(dst, "");
	ft_strlcat(dst, "Hello, World!", sizeof(dst));
	CU_ASSERT_STRING_EQUAL(dst, "Hello, World!");

	// Test 6: dstsize is one
	strcpy(dst, "Hello");
	result = ft_strlcat(dst, ", World!", 1);
	CU_ASSERT_STRING_EQUAL(dst, "Hello");
	CU_ASSERT_EQUAL(result, 9); // "Hello" length (5) + ", World!" length (8)

	// Test 7: src is exactly dstsize-1 long
	strcpy(dst, "Hi");
	result = ft_strlcat(dst, "Hello", 7);
	CU_ASSERT_STRING_EQUAL(dst, "HiHell");
	CU_ASSERT_EQUAL(result, 7); // "Hi" length (2) + "Hello" length (5)
}

void test_ft_strnstr(void) {
	// Test case 1: Needle found in haystack
	char haystack1[] = "Hello, World!";
	char needle1[] = "World";
	CU_ASSERT_PTR_NOT_NULL(ft_strnstr(haystack1, needle1, strlen(haystack1)));

	// Test case 2: Needle not found in haystack
	char haystack2[] = "Hello, World!";
	char needle2[] = "Earth";
	CU_ASSERT_PTR_NULL(ft_strnstr(haystack2, needle2, strlen(haystack2)));

	// Test case 3: Needle is an empty string
	char haystack3[] = "Hello, World!";
	char needle3[] = "";
	CU_ASSERT_PTR_EQUAL(ft_strnstr(haystack3, needle3, strlen(haystack3)), haystack3);

	// Test case 4: Needle at the beginning of haystack
	char haystack4[] = "Hello, World!";
	char needle4[] = "Hello";
	CU_ASSERT_PTR_EQUAL(ft_strnstr(haystack4, needle4, strlen(haystack4)), haystack4);

	// Test case 5: Needle at the end of haystack
	char haystack5[] = "Hello, World!";
	char needle5[] = "World!";
	CU_ASSERT_PTR_EQUAL(ft_strnstr(haystack5, needle5, strlen(haystack5)), haystack5 + 7);

	// Test case 6: Needle longer than haystack
	char haystack6[] = "Hello";
	char needle6[] = "Hello, World!";
	CU_ASSERT_PTR_NULL(ft_strnstr(haystack6, needle6, strlen(haystack6)));

	// Test case 7: Partial match only within length limit
	char haystack7[] = "Hello, World!";
	char needle7[] = "World";
	CU_ASSERT_PTR_NULL(ft_strnstr(haystack7, needle7, 5));

	// Test case 8: Exact match with length limit
	char haystack8[] = "Hello, World!";
	char needle8[] = "Hello,";
	CU_ASSERT_PTR_EQUAL(ft_strnstr(haystack8, needle8, 6), haystack8);
}


void test_ft_atoi(void) {
	CU_ASSERT(ft_atoi("12345") == 12345);
	CU_ASSERT(ft_atoi("0") == 0);
	CU_ASSERT(ft_atoi("-12345") == -12345);
	CU_ASSERT(ft_atoi("   12345") == 12345); // 前に空白がある場合
	CU_ASSERT(ft_atoi("12345abc") == 12345); // 数字の後に文字がある場合
	CU_ASSERT(ft_atoi("") == 0); // 空文字列の場合
	CU_ASSERT(ft_atoi("abc12345") == 0); // 文字から始まる場合
	CU_ASSERT(ft_atoi("  -12345") == -12345); // 前に空白とマイナスがある場合
}

void test_ft_calloc(void) {
	size_t count = 5;
	size_t size = sizeof(int);
	int *ptr = (int *)ft_calloc(count, size);

	// Test if memory is allocated
	CU_ASSERT_PTR_NOT_NULL(ptr);

	// Test if allocated memory is zeroed
	for (size_t i = 0; i < count; ++i) {
		CU_ASSERT_EQUAL(ptr[i], 0);
	}

	free(ptr);

	// Test if zero allocation returns non-NULL
	ptr = (int *)ft_calloc(0, size);
	CU_ASSERT_PTR_NOT_NULL(ptr);
	free(ptr);

	// Test if zero size returns non-NULL
	ptr = (int *)ft_calloc(count, 0);
	CU_ASSERT_PTR_NOT_NULL(ptr);
	free(ptr);

	// Test large allocation (this might fail on systems with limited memory)
	// Adjust size if necessary to fit the testing environment
	size_t large_count = 1000000;
	ptr = (int *)ft_calloc(large_count, size);
	CU_ASSERT_PTR_NOT_NULL(ptr);
	free(ptr);
}

void test_ft_strdup(void) {
	const char *str1 = "Hello, World!";
	const char *str2 = "";
	char *dup1;
	char *dup2;

	// Test duplication of a regular string
	dup1 = ft_strdup(str1);
	CU_ASSERT_PTR_NOT_NULL(dup1);
	CU_ASSERT_STRING_EQUAL(dup1, str1);
	free(dup1);

	// Test duplication of an empty string
	dup2 = ft_strdup(str2);
	CU_ASSERT_PTR_NOT_NULL(dup2);
	CU_ASSERT_STRING_EQUAL(dup2, str2);
	free(dup2);

	// Test NULL input
	char *dup_null = ft_strdup(NULL);
	CU_ASSERT_PTR_NULL(dup_null);
}

int main()
{
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	CU_pSuite pSuite = NULL;
	pSuite = CU_add_suite("test_libc_functions", 0, 0);
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (NULL == CU_add_test(pSuite, "test of ft_isalpha()", test_ft_isalpha) ||
		NULL == CU_add_test(pSuite, "test of ft_isdigit()", test_ft_isdigit) ||
		NULL == CU_add_test(pSuite, "test of ft_isdigit()", test_ft_isalnum) ||
		NULL == CU_add_test(pSuite, "test of ft_tolower()", test_ft_tolower) ||
		NULL == CU_add_test(pSuite, "test of ft_toupper()", test_ft_toupper) ||
		NULL == CU_add_test(pSuite, "test of ft_strlen()", test_ft_strlen) ||
		NULL == CU_add_test(pSuite, "test of ft_strchr()", test_ft_strchr) ||
		NULL == CU_add_test(pSuite, "test of ft_strrchr()", test_ft_strrchr) ||
		NULL == CU_add_test(pSuite, "test of ft_strncmp()", test_ft_strncmp) ||
		NULL == CU_add_test(pSuite, "test of ft_memchr()", test_ft_memchr) ||
		NULL == CU_add_test(pSuite, "test of ft_memcmp()", test_ft_memcmp) ||
		NULL == CU_add_test(pSuite, "test of ft_memset()", test_ft_memset) ||
		NULL == CU_add_test(pSuite, "test of ft_bzero()", test_ft_bzero) ||
		NULL == CU_add_test(pSuite, "test of ft_memcpy()", test_ft_memcpy) ||
		NULL == CU_add_test(pSuite, "test of ft_memmove()", test_ft_memmove) ||
		NULL == CU_add_test(pSuite, "test of ft_strlcpy()", test_ft_strlcpy) ||
		NULL == CU_add_test(pSuite, "test of ft_strlcat()", test_ft_strlcat) ||
		NULL == CU_add_test(pSuite, "test of ft_strnstr()", test_ft_strnstr) ||
		NULL == CU_add_test(pSuite, "test of ft_atoi()", test_ft_atoi) ||
		NULL == CU_add_test(pSuite, "test of ft_calloc()", test_ft_calloc) ||
		NULL == CU_add_test(pSuite, "test of ft_strdup()", test_ft_strdup))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
