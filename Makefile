CC = cc
NAME = getnextline.a
SRC = get_next_line.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# bonus: $(NAME) $(BONUS_OBJ)
#	ar -rcs $(NAME) $(BONUS_OBJ)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

.PHONY: all clean fclean re bonus

# all - compile starter (execute other rules)

# CFLAGS is used automatically

# ar -rcs adds files in archve and replace them
# if they have already been there
# (if the library already exists)
# c creates the library if there is no one
# s creates a sorted index
# that's why we can call ar -rcs again and add there bonus obj files
