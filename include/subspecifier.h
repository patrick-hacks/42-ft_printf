/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subspecifiers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:44:12 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 02:52:32 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSPECIFIERS_H
# define SUBSPECIFIERS_H

# include <stdint.h>
# include <stdarg.h>

# define LENGTH_CHARS "hljztL"

typedef struct s_subspecifiers {
	uint8_t		flags[128];
	int			width;
	int			precision;
	char		length[sizeof(LENGTH_CHARS)];
}				t_subspecifiers;

int	process_flags(const char *format, t_subspecifiers *data);
int	process_width(const char *format, va_list args, t_subspecifiers *data);
int	process_precision(const char *format, va_list args, t_subspecifiers *data);
int	process_length(const char *format, t_subspecifiers *data);

#endif // SUBSPECIFIERS_H
