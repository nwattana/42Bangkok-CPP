NAME=MyAweSomePhoneBook
CC=c++
CPPFLAGS= -std=c++98

# SRCS=
SRCS = ./src/PhoneBook.cpp \
		./src/Contact.cpp \
		./src/main.cpp

OBJS=$(SRCS:.cpp=.o)

%.o :%.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@printf "\033[32m[✔] %s\n\033[0m" "$<"

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(CPPFLAGS) ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean
	
