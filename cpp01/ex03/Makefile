NAME=UnnecessaryViolence
MNAME=UnnecessaryViolence2
MYSRC=my_test.cpp Weapon.cpp HumanA.cpp HumanB.cpp
SRCS=main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

MOBJS=$(MYSRC:.cpp=.o)
OBJS=$(SRCS:.cpp=.o)
CC=clang++
CFLAGS=-Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

mytest: $(MNAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(MNAME): $(MOBJS)
	$(CC) $(CFLAGS) $(MOBJS) -o $(MNAME)

clean:
	@rm -f $(OBJS) $(MOBJS)

fclean: clean
	@rm -f $(NAME) $(MNAME)

re: fclean all

.PHONY: clean fclean re all