/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:16:43 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/29 13:08:31 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btest.h"

#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>

#include "ft_printf.h"

void	test(char format[20])
{
	int		return_val;
	char	test[30] = {0};

	strcpy(test, format);
	printf("-----------\n");
	fflush(stdout);
	write(1, test, strlen(test));
	write(1, "\n", 1);
	return_val = ft_printf(test);
	printf("\nreturn: %d\n", return_val);
}

void	test_p(char format[20], void *c)
{
	int		return_val;
	char	test[30] = {0};

	test[0] = '%';
	strcpy(test + 1, format);
	strcat(test, "p");
	printf("-----------\n");
	fflush(stdout);
	write(1, test, strlen(test));
	write(1, "\n", 1);
	return_val = ft_printf(test, c);
	printf("\nreturn: %d\n", return_val);
}

void	test_c(char format[20], void *c)
{
	int		return_val;
	char	test[30] = {0};

	test[0] = '%';
	strcpy(test + 1, format);
	strcat(test, "c");
	printf("-----------\n");
	fflush(stdout);
	write(1, test, strlen(test));
	write(1, "\n", 1);
	return_val = ft_printf(test, c);
	printf("\nreturn: %d\n", return_val);
}

void	test_s(char format[20], void *str)
{
	int		return_val;
	char	test[30] = {0};

	test[0] = '%';
	strcpy(test + 1, format);
	strcat(test, "s");
	printf("-----------\n");
	fflush(stdout);
	write(1, test, strlen(test));
	write(1, "\n", 1);
	return_val = ft_printf(test, str);
	printf("\nreturn: %d\n", return_val);
}

void	test_duox(char format[20], void *n)
{
	int		return_val;
	char	test[30] = {0};

	test[0] = '%';
	strcpy(test + 1, format);
	printf("-----------\n");
	fflush(stdout);

	test[strlen(test)] = 'd';
	write(1, test, strlen(test));
	write(1, "\n", 1);
	fflush(stdout);
	return_val = ft_printf(test, n);
	printf("\nreturn: %d\n", return_val);

	fflush(stdout);
	test[strlen(test) - 1] = 'u';
	return_val = ft_printf(test, n);
	printf("\nreturn: %d\n", return_val);
	fflush(stdout);

	test[strlen(test) - 1] = 'o';
	return_val = ft_printf(test, n);
	printf("\nreturn: %d\n", return_val);
	fflush(stdout);

	test[strlen(test) - 1] = 'x';
	return_val = ft_printf(test, n);
	printf("\nreturn: %d\n", return_val);
	fflush(stdout);

	test[strlen(test) - 1] = 'X';
	return_val = ft_printf(test, n);
	printf("\nreturn: %d\n", return_val);
	fflush(stdout);
}

void	test_with_modifiers(char *modifiers, char *add, void *n, void(*f)(char *, void *))
{
	char test_str[20] = {0};
	char *test_str_it;
	int	modifier_count;
	int	i;
	int	j;

	modifier_count = strlen(modifiers);
	i = 0;
	while (i < (1 << modifier_count))
	{
		j = 0;
		test_str_it = test_str;
		memset(test_str, 0, 16);
		while (j < modifier_count)
		{
			int asd = 1 << j;
			if (i & asd)
			{
				*test_str_it = modifiers[j];
				test_str_it++;
			}
			j++;
		}
		strcat(test_str, add);
		f(test_str, n);
		i++;
	}
}

int	main()
{
	test_with_modifiers("-+ 0", "", (void *)4200, test_duox);

	test_with_modifiers("-+ 0#", "10", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", "5", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", "4", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", "3", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", "0", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", "0", (void *)0, test_duox);

	test_with_modifiers("-+ 0#", ".10", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", ".5", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", ".4", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", ".3", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", ".0", (void *)4200, test_duox);
	test_with_modifiers("-+ 0#", ".0", (void *)0, test_duox);

	test_with_modifiers("-+ 0#", "10.10", (void *)-4200, test_duox);
	test_with_modifiers("-+ 0#", "2.10", (void *)-4200, test_duox);
	test_with_modifiers("-+ 0#", "10.2", (void *)-4200, test_duox);
	test_with_modifiers("-+ 0#", "2.3", (void *)-4200, test_duox);
	test_with_modifiers("-+ 0#", "2.10", (void *)0, test_duox);
	test_with_modifiers("-+ 0#", "10.2", (void *)0, test_duox);

	test_with_modifiers("-+ 0#", "", (void *)INT_MAX, test_duox);
	test_with_modifiers("-+ 0#", "", (void *)INT_MIN, test_duox);

	test_with_modifiers("-+ 0#", "hh", (void *)__LONG_LONG_MAX__, test_duox);
	test_with_modifiers("-+ 0#", "h", (void *)__LONG_LONG_MAX__, test_duox);
	test_with_modifiers("-+ 0#", "l", (void *)__LONG_LONG_MAX__, test_duox);
	test_with_modifiers("-+ 0#", "ll", (void *)__LONG_LONG_MAX__, test_duox);
	test_with_modifiers("-+ 0#", "j", (void *)__LONG_LONG_MAX__, test_duox);
	test_with_modifiers("-+ 0#", "z", (void *)__LONG_LONG_MAX__, test_duox);
	test_with_modifiers("-+ 0#", "t", (void *)__LONG_LONG_MAX__, test_duox);

	test_with_modifiers("-+ 0#", "hh", (void *)__LONG_LONG_MAX__ + 1, test_duox);
	test_with_modifiers("-+ 0#", "h", (void *)__LONG_LONG_MAX__ + 1, test_duox);
	test_with_modifiers("-+ 0#", "l", (void *)__LONG_LONG_MAX__ + 1, test_duox);
	test_with_modifiers("-+ 0#", "ll", (void *)__LONG_LONG_MAX__ + 1, test_duox);
	test_with_modifiers("-+ 0#", "j", (void *)__LONG_LONG_MAX__ + 1, test_duox);
	test_with_modifiers("-+ 0#", "z", (void *)__LONG_LONG_MAX__ + 1, test_duox);
	test_with_modifiers("-+ 0#", "t", (void *)__LONG_LONG_MAX__ + 1, test_duox);

	// STRING

	test_with_modifiers("-", "", (void *)"", test_s);
	test_with_modifiers("-", ".10", (void *)"", test_s);
	test_with_modifiers("-", "10", (void *)"", test_s);
	test_with_modifiers("-", "10.2", (void *)"", test_s);
	test_with_modifiers("-", "2.10", (void *)"", test_s);
	test_with_modifiers("-", "", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", ".10", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", "10", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", "10.2", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", "2.10", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", ".19", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", "19", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", ".20", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", "20", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", ".21", (void *)"42 is a cool school", test_s);
	test_with_modifiers("-", "21", (void *)"42 is a cool school", test_s);

	// CHAR

	test_with_modifiers("-", "", (void *)'a', test_c);
	test_with_modifiers("-", "2.", (void *)'a', test_c);
	test_with_modifiers("-", ".", (void *)'a', test_c);
	test_with_modifiers("-", ".10", (void *)'a', test_c);
	test_with_modifiers("-", "10", (void *)'a', test_c);
	test_with_modifiers("-", "10.2", (void *)'a', test_c);
	test_with_modifiers("-", "2.10", (void *)'a', test_c);

	// POINTER

	void *p = (void *)0x55c8335596ed;
	test_with_modifiers("-", "", p, test_p);
	test_with_modifiers("-", "20", p, test_p);

	//size_t	i = 1;
	//while (i < 300)
	//	test_c("", (void *)i++);

	test("");
	test("42");
	test("psekfsoegspogmpgmrdgmdprg");
	test("%%");
	fflush(stdout);
	ft_printf("%d\n", 123);
	ft_printf("%dasdi\n", 123);
	ft_printf("42%deasy\n", 123);


}

// int	main()
// {
// 	char	modifiers[0xff] = {0};
// 	modifiers['-'] = 1;
// 	modifiers['+'] = 1;
// 	modifiers[' '] = 1;
// 	modifiers['#'] = 1;
// 	modifiers['0'] = 1;
// 	add_flags(modifiers, "%d\000000000000");

// 	// test("");
// 	// test("4");
// 	// test("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
// 	// test("%%");
// 	// test_d(0);
// 	// test_d(42);
// 	// test_d(-42);
// 	// test_d(INT_MAX);
// 	// test_d(INT_MIN);
// 	return (0);
// }
