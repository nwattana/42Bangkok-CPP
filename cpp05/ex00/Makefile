NAME=Bureaucrat
CXXFLAGS=-Wall -Werror -Wextra -std=c++98
CC=c++

SRCS=${shell find ./srcs -name "*.cpp" -type f 2> /dev/null}
OBJS=${SRCS:.cpp=.o}


all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re
