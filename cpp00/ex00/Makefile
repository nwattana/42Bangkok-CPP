NAME=megaphone
CXX=c++
CPPFLAG=-Wall -Wextra -Werror -std=c++98
CXXFLAG=
SRC=megaphone.cpp

# ‘$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c’. We encourage you to use the suffix ‘.cc’ or ‘.cpp’ for C++


%.o:%.cpp

all:
	$(CXX) $(CPPFLAG) -o $(NAME) $(SRC)

clean:
	@printf "remove some gabage"

fclean: fclean
	@printf "remove execution and gabage"

re: fclean all
	@printf "Make re Done"

.PHONY: all clean fclean re