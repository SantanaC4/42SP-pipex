.PHONY: all clean fclean re

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

VALGRIND = valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --track-children=yes --s
NAME = pipex
SRC_DIR = src
OBJ_DIR = objects
HEADER = $(SRC_DIR)/pipex.h

SRC_FILES = pipex.c\
	ft_split.c\
	ft_strchr.c\
	ft_strlen.c\
	ft_strcat.c\
	ft_strlcpy.c\
	ft_strnstr.c\
	ft_strjoin.c\
	ft_paths.c\
	ft_strlcat.c\
	error.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf objects*

fclean:
	make  clean
	find -name '$(NAME)' -delete

re:
	@make fclean && make all

test: all
	./$(NAME) infile  "grep igor" "wc -l" outfile

val: all
	make re
	valgrind --track-origins=yes --leak-check=full -s ./$(NAME) infile "grep igor" "tr ' ' %" outfile
