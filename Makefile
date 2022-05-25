# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:37:19 by hyeongki          #+#    #+#              #
#    Updated: 2022/05/25 18:39:20 by hyeongki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFALGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_char.c ft_printf_other.c ft_printf_num.c ft_printf_width.c ft_printf_prework.c ft_printf_string.c
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
