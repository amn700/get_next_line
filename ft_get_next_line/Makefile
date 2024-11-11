CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c
# SRCB = get_next_line_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
HEADER = get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJB)
	ar rcs $(NAME) $(OBJB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
