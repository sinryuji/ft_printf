# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:37:19 by hyeongki          #+#    #+#              #
#    Updated: 2022/07/21 19:49:01 by hyeongki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFALGS = -Wall -Wextra -Werror
SRCS_PATH = ./source/
SRCS_NAME = ft_printf.c ft_printf_num.c ft_printf_num2.c ft_printf_prework.c ft_printf_string.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
RM = rm -rf
AR = ar rcs
NAME = libftprintf.a
LIBFT_PATH = ./lib/libft/
LIBFT = libft.a

%.o : %.c
	$(CC) $(CFALGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)$(LIBFT) $(NAME)
	$(AR) $@ $^

all : $(NAME)

clean : 
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(LIBFT_PATH)$(LIBFT)
	$(RM) $(NAME)

re : fclean all

.PHONY :
	all clean fclean re
