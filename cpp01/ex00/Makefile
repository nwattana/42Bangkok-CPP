NAME=BraiiiiiiinnnzzzZ
SRCS=Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)
CXX=clang++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98


%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


clean:
	@rm -f $(OBJS)
	@echo "Removed object files!"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed executable file!"

re: fclean all

.PHONY: all clean fclean re
	