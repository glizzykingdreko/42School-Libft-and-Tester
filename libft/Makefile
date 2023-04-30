# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcampoba <dcampoba@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 20:27:50 by dcampoba          #+#    #+#              #
#    Updated: 2023/04/30 22:25:35 by dcampoba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
BONUS_ADDED = .bonus_functions_added
SRC_DIR		= ./
SRC_MAND    = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c      \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c  \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c  ft_strnstr.c  \
			ft_atoi.c  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c      \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c     \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c          \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c       \
			ft_lstmap.c
OBJ_FILES	= $(SRC_MAND:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)
SRCS		= $(addprefix $(SRC_DIR), $(SRC_MAND))
SRCS_BONUS	= $(addprefix $(SRC_DIR), $(SRC_BONUS))     
OBJS		= $(addprefix $(SRC_DIR), $(OBJ_FILES))
OBJS_BONUS	= $(addprefix $(SRC_DIR), $(OBJ_BONUS))

all: $(SRCS) $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(SRCS)

$(OBJS_BONUS): $(SRCS_BONUS)

$(BONUS_ADDED): $(NAME) $(SRCS_BONUS) $(OBJS_BONUS)
	ar -rs $(NAME) $(OBJS_BONUS)
	touch .bonus_functions_added

bonus: $(BONUS_ADDED)

clean: clean_bonus
	rm -f $(OBJS)

clean_bonus:
	rm -f $(OBJS_BONUS) $(BONUS_ADDED)

fclean: clean
	rm -f $(NAME) $(BONUS_ADDED)

re: fclean all