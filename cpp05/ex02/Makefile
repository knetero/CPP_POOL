CC = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
		ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Form
HEADERS = Bureaucrat.hpp AForm.hpp \
		ShrubberyCreationForm.hpp RobotomyRequestForm.hpp \
		PresidentialPardonForm.hpp

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