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
#include <limits.h>
#include <string.h>
#include <unistd.h>

#include "ft_printf.h"

void	test_c(char format[20], void *c)
{
	int		return_val;
	char	test[30];

	test[0] = '%';
	strcpy(test + 1, format);
	strcat(test, "c");
	printf("-----------\n");
	fflush(stdout);
	write(1, test, strlen(test));
	write(1, "\n", 1);
	return_val = ft_printf(test, (char)c);
	printf("\nreturn: %d\n", return_val);
}

void	test_s(char format[20], void *str)
{
	int		return_val;
	char	test[30];

	test[0] = '%';
	strcpy(test + 1, format);
	strcat(test, "s");
	printf("-----------\n");
	fflush(stdout);
	write(1, test, strlen(test));
	write(1, "\n", 1);
	return_val = ft_printf(test, (char*)str);
	printf("\nreturn: %d\n", return_val);
}

void	test_d(char format[20], void *n)
{
	int		return_val;
	char	test[30];

	test[0] = '%';
	strcpy(test + 1, format);
	strcat(test, "d");
	printf("-----------\n");
	fflush(stdout);
	write(1, test, strlen(test));
	write(1, "\n", 1);
	return_val = ft_printf(test, (int)n);
	printf("\nreturn: %d\n", return_val);
}

void	test_with_modifiers(char *modifiers, char *add, void *n, void(*f)(char *, void *))
{
	char test_str[30];
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
	test_with_modifiers("-+ 0", "", (void *)4200, test_d);

	test_with_modifiers("-+ 0", "10", (void *)4200, test_d);
	test_with_modifiers("-+ 0", "5", (void *)4200, test_d);
	test_with_modifiers("-+ 0", "4", (void *)4200, test_d);
	test_with_modifiers("-+ 0", "3", (void *)4200, test_d);
	test_with_modifiers("-+ 0", "0", (void *)4200, test_d);
	test_with_modifiers("-+ 0", "0", (void *)0, test_d);

	test_with_modifiers("-+ 0", ".10", (void *)4200, test_d);
	test_with_modifiers("-+ 0", ".5", (void *)4200, test_d);
	test_with_modifiers("-+ 0", ".4", (void *)4200, test_d);
	test_with_modifiers("-+ 0", ".3", (void *)4200, test_d);
	test_with_modifiers("-+ 0", ".0", (void *)4200, test_d);
	test_with_modifiers("-+ 0", ".0", (void *)0, test_d);

	test_with_modifiers("-+ 0", "10.10", (void *)-4200, test_d);
	test_with_modifiers("-+ 0", "2.10", (void *)-4200, test_d);
	test_with_modifiers("-+ 0", "10.2", (void *)-4200, test_d);
	test_with_modifiers("-+ 0", "2.3", (void *)-4200, test_d);
	test_with_modifiers("-+ 0", "2.10", (void *)0, test_d);
	test_with_modifiers("-+ 0", "10.2", (void *)0, test_d);

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

	// test("%-d", n);
	// test("%+d", n);
	// test("% d", n);
	// test("%#d", n);
	// test("%0d", n);

	// test("%-5d", n);
	// test("%+10d", n);
	// test("% 20d", n);
	// test("%#30d", n);
	// test("%040d", n);

	// test("%-.5d", n);
	// test("%+.10d", n);
	// test("% .20d", n);
	// test("%#.30d", n);
	// test("%0.40d", n);

	// test("%-5.5d", n);
	// test("%+5.10d", n);
	// test("% 5.20d", n);
	// test("%#5.30d", n);
	// test("%05.40d", n);

	// test("%-40.5d", n);
	// test("%+40.10d", n);
	// test("% 40.20d", n);
	// test("%#40.30d", n);
	// test("%040.35d", n);

	// test("%-+d", n);
	// test("%-+ d", n);
	// test("%-+ 0d", n);
	// test("%-+#0d", n);
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
