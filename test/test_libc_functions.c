/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libc_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:12:02 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/05/29 17:33:02 by shinsaeki        ###   ########.fr       */
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
		NULL == CU_add_test(pSuite, "test of ft_memset()", test_ft_memset) ||
		NULL == CU_add_test(pSuite, "test of ft_bzero()", test_ft_bzero) ||
		NULL == CU_add_test(pSuite, "test of ft_memcpy()", test_ft_memcpy))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}