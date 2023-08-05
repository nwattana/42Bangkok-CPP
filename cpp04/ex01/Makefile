NAME=Polymorphism
SRCS=main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp Brain.cpp
OBJS=$(SRCS:.cpp=.o)
CC=clang++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re