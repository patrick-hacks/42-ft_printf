/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 03:39:46 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 04:32:37 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_FUNCTIONS_H
# define SPECIFIER_FUNCTIONS_H

#include <stdarg.h>
#include <stdint.h>

typedef struct s_vector t_vector;
typedef struct s_subspecifiers t_subspecifiers;

// FUNCTIONS
# define SPEC_F_ARGS t_vector *buffer, t_subspecifiers *data, va_list args
typedef int (*t_specifier_function)(SPEC_F_ARGS);

int	s_error(SPEC_F_ARGS);
int	s_signed_integer(SPEC_F_ARGS);
int	s_unsigned_integer(SPEC_F_ARGS);
//int	unsigned_long_long(SPEC_F_ARGS);

# undef SPEC_F_ARGS
// =======

enum e_test {
	e_error = 0,
	e_signed_integer = 1,
	e_unsiged_integer = 2,
	e_unsigned_asd = 2
};

const static t_specifier_function	specifier_functions[] = {
	s_error,
	s_error,
	s_error,
	s_error
};

static const int8_t spec_function_id[] =
{
	0, // @ //
	0, // A //
	0, // B //
	0, // C //
	0, // D //
	0, // E //
	0, // F //
	0, // G //
	0, // H //
	0, // I //
	0, // J //
	0, // K //
	e_error, // L // USED FOR LENGTH
	0, // M //
	0, // N //
	0, // O //
	0, // P //
	0, // Q //
	0, // R //
	0, // S //
	0, // T //
	0, // U //
	0, // V //
	0, // W //
	0, // X //
	0, // Y //
	0, // Z //
	0, // [ //
	0, // \ //
	0, // ] //
	0, // ^ //
	0, // _ //
	0, // ` //
	0, // a //
	0, // b //
	0, // c //
	1, // d //
	0, // e //
	0, // f //
	0, // g //
	e_error, // h // USED FOR LENGTH
	0, // i //
	e_error, // j // USED FOR LENGTH
	0, // k //
	e_error, // l // USED FOR LENGTH
	0, // m //
	0, // n //
	0, // o //
	0, // p //
	0, // q //
	0, // r //
	0, // s //
	e_error, // t // USED FOR LENGTH
	0, // u //
	0, // v //
	0, // w //
	0, // x //
	0, // y //
	e_error, // z // USED FOR LENGTH
	0, // { //
	0, // | //
	0, // } //
	0, // ~ //
	0, // DEL //
};

#endif // SPECIFIER_FUNCTIONS_H
