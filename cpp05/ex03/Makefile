# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 16:16:10 by muel-bak          #+#    #+#              #
#    Updated: 2024/10/12 13:01:52 by muel-bak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C := c++
FLAGS := -std=c++98 -Wall -Wextra -Werror
SRC := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
HEADER_FILE := Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
OBJS := $(SRC:%.cpp=%.o)
NAME := Intern

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILE)
	@$(C) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m$(NAME) \033[1;32mhas been compiled\033[0;37m"

%.o: %.cpp $(HEADER_FILE)
	@$(C) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) *_shrubbery
	@echo "\033[1;32mThe object files have been removed\033[0;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;32mThe object files and the program have been removed\033[0;37m"

re: fclean all