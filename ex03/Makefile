# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME = AForm

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

OBJS = $(SRCS:.cpp=.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                   PHONY                                      #
# **************************************************************************** #

.PHONY: all clean fclean re
