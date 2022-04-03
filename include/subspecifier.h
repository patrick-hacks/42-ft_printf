/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subspecifier.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:44:12 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/03 10:59:04 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSPECIFIER_H
# define SUBSPECIFIER_H

# include <stdint.h>
# include <stdarg.h>

# define LENGTH_CHARS "hljztL"
# define FLAG_CHARS " !\"#$&'()+,-/0:;<=>?@[\\]^_`{|}~"

typedef struct s_subspecifiers {
	uint8_t		flags[128];
	int			width;
	int			precision;
}				t_subspecifiers;

void	init_t_subspecifiers(t_subspecifiers *data);
int		process_flags(const char *format, t_subspecifiers *data);
int		process_width(const char *format, va_list args, t_subspecifiers *data);
int		process_precision(const char *format, va_list args, t_subspecifiers *d);
int		process_length(const char *format, t_subspecifiers *data);

#endif // SUBSPECIFIER_H
