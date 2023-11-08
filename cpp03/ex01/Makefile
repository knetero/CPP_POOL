CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ScavTrap
HEADERS = ClapTrap.hpp ScavTrap.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
