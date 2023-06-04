NAME=megaphone
CXX=c++
CPPFLAG=-Wall -Wextra -Werror -std=c++98
CXXFLAG=
SRC=megaphone.cpp

# ‘$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c’. We encourage you to use the suffix ‘.cc’ or ‘.cpp’ for C++

all:
	@$(CXX) $(CPPFLAG) -o $(NAME) $(SRC)

clean:
	@rm megaphone.o

fclean: fclean
	@rm $NAME

re: fclean all

.PHONY: all clean fclean re