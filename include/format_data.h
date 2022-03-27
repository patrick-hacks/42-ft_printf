/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:50:20 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/27 03:52:57 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_DATA_H
# define FORMAT_DATA_H

# define FLAG_MINUS 0b1
# define FLAG_PLUS 0b10
# define FLAG_SPACE 0b100
# define FLAG_HASH 0b1000
# define FLAG_ZERO 0b10000

typedef struct s_format_data {
	unsigned char	flag_bits;
	int				width;
	int				precision;
	int				specifier_id;
}					t_format_data;

#endif // FORMAT_DATA_H
