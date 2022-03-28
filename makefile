# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 13:56:06 by pfuchs            #+#    #+#              #
#    Updated: 2022/03/28 01:34:25 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Disable built-in rules and variables
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

VPATH = src specifier_functions subspecifiers

# Compiler Variables
CC		= cc
CFLAGSS	= -Wall -Wextra -Werror -g
INCFLAG	= -I include -I libft -I specifier_functions -I subspecifiers
AR		= ar
ARFLAGS = -rcs
# File Variables
NAME	= libft_printf.a
SRC		= $(wildcard src/*.c) $(wildcard specifier_functions/*.c) $(wildcard subspecifiers/*.c)
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

.PHONY: clean fclean re all
