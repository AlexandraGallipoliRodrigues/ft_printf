# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 19:13:50 by agallipo          #+#    #+#              #
#    Updated: 2021/09/23 10:37:10 by agallipo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c ft_printf_utils.c c_type.c i_d_type.c p_type.c s_type.c u_type.c x_type.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@echo [COMPILANDO...]
	ar rc $(NAME) $(OBJS) 
#$(OBJS) : $(SRCS)
#	@gcc $(CFLAGS) -c $(SRCS)
clean:
			$(RM) $(OBJS)
			
fclean:		clean
	$(RM) $(NAME)
re:			fclean all
.PHONY:     bonus all clean fclean re
