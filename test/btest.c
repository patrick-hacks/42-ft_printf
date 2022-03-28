/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:16:43 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/27 06:30:36 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btest.h"

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>

#include "ft_printf.h"

void	test(char *format, ...)
{
	int		return_val;
	va_list	args;

	printf("-----------\n");
	va_start (args, format);
	fflush(stdout);
	write(1, format, strlen(format));
	write(1, "\n", 1);
	return_val = ft_vprintf(format, args);
	va_end (args);
	printf("\nreturn: %d\n", return_val);
}

void	test_d(int n)
{
	test("%d", n);

	test("%-d", n);
	test("%+d", n);
	test("% d", n);
	test("%#d", n);
	test("%0d", n);

	test("%-5d", n);
	test("%+10d", n);
	test("% 20d", n);
	test("%#30d", n);
	test("%040d", n);

	test("%-.5d", n);
	test("%+.10d", n);
	test("% .20d", n);
	test("%#.30d", n);
	test("%0.40d", n);

	test("%-5.5d", n);
	test("%+5.10d", n);
	test("% 5.20d", n);
	test("%#5.30d", n);
	test("%05.40d", n);

	test("%-40.5d", n);
	test("%+40.10d", n);
	test("% 40.20d", n);
	test("%#40.30d", n);
	test("%040.35d", n);

	test("%-+d", n);
	test("%-+ d", n);
	test("%-+ 0d", n);
	test("%-+#0d", n);
}

int	main()
{
	test("");
	test("4");
	test("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	test("%%");
	test_d(0);
	test_d(42);
	test_d(-42);
	// test_d(INT_MAX);
	// test_d(INT_MIN);
	return (0);
}
