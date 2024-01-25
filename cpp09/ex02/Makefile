NAME=PmergeMe
CXXFLAGS=-Wall -Werror -Wextra -std=c++98
# CXXFLAGS=-std=c++98 -g
CXX=c++

SRCS=${shell find . -name "*.cpp" -type f 2> /dev/null}
OBJS=${SRCS:.cpp=.o}

OS = $(shell uname -s)

all:$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:fclean all

test: re
	@bash ./test.sh

.PHONY: all clean fclean re