/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:20:45 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/03 11:32:37 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_FUNCTIONS_H
# define SPECIFIER_FUNCTIONS_H

# include <stdarg.h>
# include <stdint.h>

typedef struct s_vector				t_vector;
typedef struct s_subspecifiers		t_subspecifiers;

typedef int							(*t_specifier_function)(t_vector *buffer,
		t_subspecifiers *data, va_list args);

int	s_percent(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_error(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_integer_signed(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_integer_unsigned(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_octal_unsigned(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_hexa_unsigned_low(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_hexa_unsigned_up(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_float_low(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_float_up(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_float_scient_low(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_float_scient_up(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_float_short_low(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_float_short_up(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_float_hexa_low(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_float_hexa_up(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_char(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_string(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_pointer(t_vector *buffer, t_subspecifiers *data, va_list args);
int	s_store(t_vector *buffer, t_subspecifiers *data, va_list args);

enum e_test {
	e_error = 0,
	e_integer_signed = 1,
	e_integer_unsigned = 2,
	e_octal_unsigned = 3,
	e_hexa_unsigned_low = 4,
	e_hexa_unsigned_up = 5,
	e_float_low = 6,
	e_float_up = 7,
	e_float_scient_low = 8,
	e_float_scient_up = 9,
	e_float_short_low = 10,
	e_float_short_up = 11,
	e_float_hexa_low = 12,
	e_float_hexa_up = 13,
	e_char = 14,
	e_string = 15,
	e_pointer = 16,
	e_store = 17,
	e_percent = 18
};

static const t_specifier_function	g_specifier_functions[] = {
	s_error,				// 0
	s_integer_signed,		// 1
	s_integer_unsigned,		// 2
	s_octal_unsigned,		// 3
	s_hexa_unsigned_low,	// 4
	s_hexa_unsigned_up,		// 5
	s_float_low,			// 6
	s_float_up,				// 7
	s_float_scient_low,		// 8
	s_float_scient_up,		// 9
	s_float_short_low,		// 10
	s_float_short_up,		// 11
	s_float_hexa_low,		// 12
	s_float_hexa_up,		// 13
	s_char,					// 14
	s_string,				// 15
	s_pointer,				// 16
	s_store					// 17
};

static const int8_t					g_spec_function_id[] = {
	0,						// @ //
	e_float_hexa_up,		// A //
	0,						// B //
	0,						// C //
	0,						// D //
	e_float_scient_up,		// E //
	e_float_up,				// F //
	e_float_short_up,		// G //
	0,						// H //
	0,						// I //
	0,						// J //
	0,						// K //
	e_error,				// L // USED FOR LENGTH
	0,						// M //
	0,						// N //
	0,						// O //
	0,						// P //
	0,						// Q //
	0,						// R //
	0,						// S //
	0,						// T //
	0,						// U //
	0,						// V //
	0,						// W //
	e_hexa_unsigned_up,		// X //
	0,						// Y //
	0,						// Z //
	0,						// [ //
	0,						// \ //
	0,						// ] //
	0,						// ^ //
	0,						// _ //
	0,						// ` //
	e_float_hexa_low,		// a //
	0,						// b //
	e_char,					// c //
	e_integer_signed,		// d //
	e_float_scient_low,		// e //
	e_float_low,			// f //
	e_float_short_low,		// g //
	e_error,				// h // USED FOR LENGTH
	e_integer_signed,		// i //
	e_error,				// j // USED FOR LENGTH
	0,						// k //
	e_error,				// l // USED FOR LENGTH
	0,						// m //
	e_store,				// n //
	e_octal_unsigned,		// o //
	e_pointer,				// p //
	0,						// q //
	0,						// r //
	e_string,				// s //
	e_error,				// t // USED FOR LENGTH
	e_integer_unsigned,		// u //
	0,						// v //
	0,						// w //
	e_hexa_unsigned_low,	// x //
	0,						// y //
	e_error,				// z // USED FOR LENGTH
	0,						// { //
	0,						// | //
	0,						// } //
	0,						// ~ //
	0						// DEL //
};

#endif // SPECIFIER_FUNCTIONS_H
