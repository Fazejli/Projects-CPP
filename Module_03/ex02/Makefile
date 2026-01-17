# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 14:47:58 by fadzejli          #+#    #+#              #
#    Updated: 2026/01/17 12:55:19 by fadzejli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -I. $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re