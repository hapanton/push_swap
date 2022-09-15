# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 22:37:15 by qsergean          #+#    #+#              #
#    Updated: 2022/03/12 14:44:46 by qsergean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                               ／ﾌﾌﾌ                ム｀ヽ      #
#												/ ノ)　　 ∧　　∧　　　　）　ヽ     #
#	█▒   █▒  █████▒ >ЧИТАЮ САБЖ					/ ｜　　(´・ω ・`）ノ⌒（ゝ._,ノ   #
#	█▒   █▒  █▒ 	>ПОЛЬЗУЮСЬ МАНОМ			/　ﾉ⌒＿⌒ゝーく　 ＼　　／ 		  #
#	██████▒  ████▒ 	>СПРАШИВАЮ ПИРА СПРАВА		丶＿ ノ 　　 ノ､　　|　/ 		  #
#	█▒   █▒  █▒		>СПРАШИВАЮ ПИРА СЛЕВА		　　 `ヽ `ー-‘人`ーﾉ / 			 #
#	█▒   █▒  █████▒ >ПРАВДА ВСЕ ЭТО				　　　 丶 ￣ _人’  ﾉ			    #
#												　　　／｀ヽ _/\__				 #
# 											 	　　 ／    _/\__				#
#																			   #
# **************************************************************************** #

NAME		=	push_swap

LIB			=	libft.a

SRCS		=	push_swap.c					sources/ft_ll_atoi.c		sources/parsing.c\
				sources/functions_1.c		sources/functions_2.c		sources/functions_3.c\
				sources/addons.c			sources/scores.c			sources/initiators.c\
				sources/sorters.c			sources/decision.c			sources/fillers.c

SRCS_LIB	=	libft/ft_isalpha.c			libft/ft_isdigit.c			libft/ft_isalnum.c\
				libft/ft_isascii.c			libft/ft_isprint.c			libft/ft_strlen.c\
				libft/ft_memset.c			libft/ft_bzero.c			libft/ft_memcpy.c\
				libft/ft_memmove.c			libft/ft_strlcpy.c			libft/ft_strlcat.c\
				libft/ft_toupper.c			libft/ft_tolower.c			libft/ft_strchr.c\
				libft/ft_strrchr.c			libft/ft_strncmp.c			libft/ft_memchr.c\
				libft/ft_memcmp.c			libft/ft_strnstr.c			libft/ft_atoi.c\
				libft/ft_calloc.c			libft/ft_strdup.c			libft/ft_substr.c\
				libft/ft_strjoin.c			libft/ft_strtrim.c			libft/ft_split.c\
				libft/ft_itoa.c				libft/ft_strmapi.c			libft/ft_striteri.c\
				libft/ft_putchar_fd.c		libft/ft_putstr_fd.c		libft/ft_putendl_fd.c\
				libft/ft_putnbr_fd.c\
				\
				libft/ft_lstnew.c			libft/ft_lstadd_front.c		libft/ft_lstsize.c\
				libft/ft_lstlast.c			libft/ft_lstadd_back.c		libft/ft_lstdelone.c\
				libft/ft_lstclear.c			libft/ft_lstiter.c			libft/ft_lstmap.c\
				\
				libft/helpers.c				libft/dec_to_hex.c\
				libft/print_address_perc.c	libft/print_char_string.c	libft/print_hexadecimal.c\
				libft/print_integer.c		libft/print_unsigned.c		libft/ft_printf.c

SRCS_BONUS	=	checker_bonus.c					bonus_files/get_next_line.c\
				bonus_files/get_next_line_utils.c\
				sources/ft_ll_atoi.c		sources/parsing.c\
				sources/functions_1.c		sources/functions_2.c		sources/functions_3.c\
				sources/addons.c			sources/scores.c			sources/initiators.c\
				sources/sorters.c			sources/decision.c			sources/fillers.c
OBJS		=	$(SRCS:.c=.o)
OBJS_LIB	=	$(SRCS_LIB:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

HEADER		=	includes/push_swap.h
HEADER_LIB	=	libft/libft.h			includes/ft_printf.h
HEADER_GNL	=	bonus_files/get_next_line.h

LIBC		=	ar rc
LIBR		=	ranlib

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@ 

all: ${LIB} ${NAME}

${LIB}: ${OBJS_LIB} ${HEADER_LIB}
	@${LIBC} ${LIB} ${OBJS_LIB}
	@${LIBR} ${LIB}

$(NAME): ${LIB} ${OBJS} ${HEADER}
	@${CC} ${CFLAGS} ${LIB} -o ${NAME} ${OBJS}

checker: ${LIB} ${HEADER} ${HEADER_GNL} ${OBJS_BONUS}
	@${CC} ${CFLAGS} ${LIB} -o checker ${OBJS_BONUS}

bonus: checker

clean:
	@${RM} ${OBJS} ${OBJS_LIB} ${OBJS_BONUS}

fclean: clean
	@${RM} ${LIB} ${NAME} checker

re: fclean all

.PHONY: all clean fclean bonus re .c.o
