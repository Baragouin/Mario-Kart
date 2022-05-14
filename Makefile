SRC = main.c \
      $(wildcard src/**/**/*.c) \
      $(wildcard src/**/*.c) \
      $(wildcard src/*.c) \

OBJ = $(SRC:.c=.o)

CC = gcc
NAME = kart
CFLAGS += -Wall -Wextra -Iinclude
CFLAGS += -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all: $(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME)_debug

clean:
	rm -f profile.txt gmon.out
	find . -type f -name '*.o' -delete
	find . -type f -name '*.gcda' -delete
	find . -type f -name '*.gcno' -delete
	find . -type f -name '*.gcov' -delete
	find . -type f -name 'vgcore.*' -delete

re: 	fclean all

debug:
	$(CC) $(SRC) -o $(NAME)_debug -g -g3 $(CFLAGS)

gdb: 	debug
	gdb --quiet $(NAME)_debug

profile:
	$(CC) $(SRC) -o $(NAME)_profile -pg
	./$(NAME)_profile
	gprof $(NAME) gmon.out > profile.txt

valgrind: debug
	valgrind ./$(NAME)_debug

leak: 	debug
	valgrind --leak-check=full ./$(NAME)_debug

origins: debug
	valgrind --track-origins=yes ./$(NAME)_debug
