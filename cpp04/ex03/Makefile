CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp ICharacter.cpp IMateriaSource.cpp MateriaSource.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Materials
HEADERS = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.cpp IMateriaSource.cpp  MateriaSource.cpp

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
