# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2018/10/07 18:07:12 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft_retro

# directories
SRC_DIR		:= ./src
OBJ_DIR		:= ./obj

# src / obj files
SRC			:=	main.cpp \
				Player.cpp \
				Enemy.cpp \
				Bullet.cpp \
				IEntity.cpp \
				FakeList.cpp \
				NCurses.cpp

OBJ			:= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

# compiler
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c++98
CXXFLAGS	+= -O3 -march=native -pipe -flto

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -lncurses

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
