# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 13:56:06 by pfuchs            #+#    #+#              #
#    Updated: 2022/04/25 18:51:35 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Disable built-in rules and variables
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

VPATH = src subspecifier specifier

# Compiler Variables
CC		= cc
CFLAGSS	= -Wall -Wextra -Werror -g
INCFLAG	= -I include -I libft
AR		= ar
ARFLAGS = -rcs
# File Variables
NAME	= libftprintf.a
SPECIFIERN	= char error float_hexa_up float_hexa_low float_low float_scient_low\
			float_scient_up float_short_low float_short_up float_up\
			hexa_unsigned_low hexa_unsigned_up integer_signed integer_unsigned\
			octal_unsigned percent pointer store string
SRCN		= specifier add_float add_nbr base set_float_data flags init length\
			precision width ft_vector ft_printf
SRC		= $(addsuffix .c,$(addprefix s_,$(SPECIFIERN)) $(SRCN))
OBJ		= $(addprefix _bin/,$(notdir $(SRC:.c=.o)))

$(NAME): $(OBJ) | libft/libft.a
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^

libft/libft.a :
	(cd libft && make && make clean)

_bin :
	mkdir _bin

_bin/%.o : %.c libft/libft.a | _bin
	$(CC) -c $(CFLAGSS) $(INCFLAG) $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME)

bonus:	$(NAME)

.PHONY: clean fclean re all
