# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falarm <falarm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 20:51:45 by falarm            #+#    #+#              #
#    Updated: 2021/10/27 18:29:50 by falarm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c		ft_parser.c		ft_put.c	ft_puthex.c

HEADER		=	ft_printf.h
LIBFT_PATH	=	./libft_src
OBJ			=	$(SRCS:%.c=%.o)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -I $(HEADER)

all		:	$(NAME)	

$(NAME)	:	$(OBJ)	$(HEADER)
	make re -C $(LIBFT_PATH)
	ar rc $(NAME) $(OBJ) $(LIBFT_PATH)/*.o
	ranlib $(NAME)

%.o		:	%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
	
clean	:
	@rm -f	$(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean	:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re		:	fclean all

.PHONY	:	all clean fclean re