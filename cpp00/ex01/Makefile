NAME=MyAweSomePhoneBook
CC=c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98

# SRCS=
SRCS = ./src/PhoneBook.cpp \
		./src/Contact.cpp \
		./src/main.cpp

OBJS=$(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(CPPFLAGS) -c ${OBJS} -o ${NAME}
	printf "\033[32m[✔] %s\n\033[0m" "$<"

clean:
	rm -f ${OBJS}