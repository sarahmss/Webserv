# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2023/06/25 18:53:23 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Webserver

SRC_PATH		= ./
INCLUDES_PATH	= ./
OBJS_PATH		= ./objects/

SRCS_FILES =	tests/main.cpp							\
				Networking/Sockets/BindingSocket.cpp	\
				Networking/Sockets/ConnectingSocket.cpp	\
				Networking/Sockets/ListeningSocket.cpp	\
				Networking/Sockets/SimpleSocket.cpp		\
				Networking/Servers/SimpleServer.cpp		\
				Networking/Servers/WebServer.cpp

SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.cpp, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	httplib.hpp								\
					Networking/httpNetworking.hpp			\
					Networking/Sockets/httpSockets.hpp		\
					Networking/Sockets/BindingSocket.hpp	\
					Networking/Sockets/ConnectingSocket.hpp	\
					Networking/Sockets/ListeningSocket.hpp	\
					Networking/Sockets/SimpleSocket.hpp		\
					Networking/Servers/httpServers.hpp		\
					Networking/Servers/SimpleServer.hpp		\
					Networking/Servers/WebServer.hpp
					
					
HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

CC			= c++
FLAGS		= -Wall -Wextra -Werror -g -std=c++98
INCLUDES	= -I $(INCLUDES_PATH)

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(OBJS) $(FLAGS) $(INCLUDES) -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.cpp $(HEADERS)
			@mkdir -p objects
			@mkdir -p objects/tests
			@mkdir -p objects/Networking/Sockets
			@mkdir -p objects/Networking/Servers

			$(CC) $(FLAGS) -c  $< -o $@

clean:
			@rm -f $(OBJS)
			@rm -rf $(OBJS_PATH)
			@echo cleaned!

fclean:		clean
			@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re