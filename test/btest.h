/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:19:56 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/26 14:26:05 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTEST_H
# define BTEST_H

# define COL_NRM "\033[0m"
# define COL_RED "\033[0;31m"
# define COL_GRN "\033[0;32m"
# define COL_YEL "\033[0;33m"
# define COL_BLU "\033[0;34m"
# define COL_MAG "\033[0;35m"
# define COL_CYN "\033[0;36m"
# define COL_WHT "\033[0;37m"

#ifdef EXPECTED
# define ft_vprintf vprintf
#endif

#endif
