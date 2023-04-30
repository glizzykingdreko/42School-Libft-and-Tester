CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = tester.c
OBJ = $(SRC:.c=.o)
TARGET = test_libft

all: $(TARGET)

$(TARGET): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(if $(BONUS),-D BONUS) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft -o $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(if $(BONUS),-D BONUS) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
ifeq ($(BONUS),1)
	$(MAKE) -C $(LIBFT_DIR) bonus
else
	$(MAKE) -C $(LIBFT_DIR)
endif

bonus:
	$(MAKE) BONUS=1

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re bonus
