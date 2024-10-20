# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 12:23:50 by muel-bak          #+#    #+#              #
#    Updated: 2024/10/20 13:08:02 by muel-bak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C := c++
FLAGS := -std=c++98 -Wall -Wextra -Werror
SRC := main.cpp BitcoinExchange.cpp
HEADER_FILE := BitcoinExchange.hpp
OBJS := $(SRC:%.cpp=%.o)
NAME := btc

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILE)
	@$(C) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m$(NAME) \033[1;32mhas been compiled\033[0;37m"

%.o: %.cpp $(HEADER_FILE)
	@$(C) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "\033[1;32mThe object files have been removed\033[0;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;32mThe object files and the program have been removed\033[0;37m"

re: fclean all