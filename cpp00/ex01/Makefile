CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = PhoneBook.cpp contact.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = PhoneBook
HEADERS = contact_class.hpp PhoneBook_class.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
