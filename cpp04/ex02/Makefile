CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp AAnimal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = AAnimals
HEADERS = AAnimal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.cpp Brain.hpp

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
