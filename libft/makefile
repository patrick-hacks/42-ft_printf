# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 02:09:09 by pfuchs            #+#    #+#              #
#    Updated: 2022/03/26 15:30:32 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Disable built-in rules and variables
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

# Compiler Variables
CC		= cc
CFLAGSS	= -Wall -Wextra -Werror
INCFLAG	= -I .
AR		= ar
ARFLAGS = -rcs
# File Variables
NAME	= libft.a
MAIN	= isalpha isdigit isalnum isascii isprint strlen memset bzero memcpy\
		memmove strlcpy strlcat toupper tolower strchr strrchr strncmp memchr\
		memcmp strnstr atoi calloc strdup substr strjoin strtrim split itoa\
		strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd
BONUS	= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear\
		lstiter lstmap
MAINFILES	= $(addprefix ft_,$(addsuffix .c, $(MAIN)))
BONUSFILES	= $(addprefix ft_,$(addsuffix _bonus.c, $(BONUS)))
MAINOBJ	= $(MAINFILES:.c=.o)
BONUSOBJ = $(BONUSFILES:.c=.o)

$(NAME): $(MAINOBJ)
	$(AR) $(ARFLAGS) $@ $^

bonus:	$(BONUSOBJ)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c
	@$(CC) -c $(CFLAGSS) $(INCFLAG) $< -o $@

clean:
	@rm -f $(MAINOBJ) $(BONUSOBJ)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME) bonus

.PHONY: bonus clean fclean re all
