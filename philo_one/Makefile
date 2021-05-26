NAME			= philo_one

HEADER			= -I includes/

SRCS			= main.c init.c utils.c exit.c philo_utils.c \
					philo_life.c

FOLDER			= $(addprefix srcs/, $(SRCS))

OBJS			= $(FOLDER:c=o)

CC				= clang
CFLAGS 			= -pthread -Wall -Wextra -Werror
FSAN			= -g3 -fsanitize=address
RM				= rm -f

all:			$(NAME)

%o: %.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

fsan:			$(OBJS)
				$(CC) $(CFLAGS) $(FSAN) -o $(NAME) $(OBJS)

leaks:			$(NAME)
				valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes ./$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re test fsan leaks