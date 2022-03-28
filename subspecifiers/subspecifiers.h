/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subspecifiers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:44:12 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 01:55:55 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUB_SPECIFIERS_H
# define SUB_SPECIFIERS_H

# include <stdint.h>
# include <stdarg.h>

typedef struct s_subspecifiers {
	uint8_t		flags[128];
	int			width;
	int			precision;
	char		length[128];
}				t_subspecifiers;

int	process_flags(const char *format, t_subspecifiers *data);
int	process_width(const char *format, va_list args, t_subspecifiers *data);
int	process_precision(const char *format, va_list args, t_subspecifiers *data);
int	process_length(const char *format, t_subspecifiers *data);

#endif // SUB_SPECIFIERS_H
