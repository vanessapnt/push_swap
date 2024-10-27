# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 19:05:02 by varodrig          #+#    #+#              #
#    Updated: 2024/10/24 13:47:48 by varodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################################

## ARGUMENTS

NAME			= push_swap
FLAGS			= -Wall -Wextra -Werror
CC				= gcc

###########################################
## SOURCES

SRCS			= ft_push.c \
				ft_reverse_rotate.c \
				ft_rotate.c \
				ft_split.c \
				ft_swap.c \
				init_stack.c \
				handle_split.c \
				push_swap.c \
				set_members.c \
				sort_stacks.c \
				tiny_sort.c \
				tool_box_1.c \
				tool_box_2.c

OBJS			= ${SRCS:.c=.o}

HEADER			= push_swap.h \


###########################################
## RULES

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
		@${CC} ${FLAGS} ${OBJS} -o ${NAME} || { echo "Error during compilation of push_swap"; exit 1; }
		@echo "Push_swap compiled"

%.o: %.c
		@${CC} ${FLAGS} -c $< -o $@ || { echo "Error compiling $<"; exit 1; }

clean:
		@rm -f ${OBJS}
		@echo CLEAN DONE

fclean:	clean
		@rm -f ${NAME}
		@echo FCLEAN DONE

re: fclean all
		@echo RE DONE

.PHONY: all bonus clean fclean re