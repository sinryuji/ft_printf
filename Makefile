# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:37:19 by hyeongki          #+#    #+#              #
#    Updated: 2022/04/08 00:00:02 by hyeongki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFALGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_char.c ft_printf_other.c ft_printf_num.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf
AR = ar rcs
NAME = libftprintf.a
LIBFTDIR = ./libft
LIBFT = libft.a

%.o : %.c
	$(CC) $(CFALGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	$(AR) $@ $^

all : $(NAME)

clean : 
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(LIBFT)/$(LIBFT)
	$(RM) $(NAME)

re : fclean all

.PHONY :
	all clean fclean re
