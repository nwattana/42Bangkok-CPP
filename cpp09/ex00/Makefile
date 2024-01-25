NAME=btc
CXXFLAGS=-Wall -Werror -Wextra -std=c++98
CXX=c++

SRCS=${shell find . -name "*.cpp" -type f 2> /dev/null}
OBJS=${SRCS:.cpp=.o}


all:$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re

