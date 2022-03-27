/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prespecifiers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:00:16 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/26 19:14:37 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESPECIFIERS_H
# define PRESPECIFIERS_H

# include <stdarg.h>

int		process_flags(const char **format);
int		process_star_number(const char **num, va_list args);
int		process_specifier(const char **num);

#endif // PRESPECIFIERS_H
