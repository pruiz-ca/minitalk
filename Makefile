# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 22:05:06 by pedro             #+#    #+#              #
#    Updated: 2021/08/14 17:11:26 by pruiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			=	/bin/bash

NAME			=	server
CLIENT			=	client

S				=	src/
O				=	obj/
I				=	inc/

NOCOL			=	\033[0m
RED				=	\033[0;31m
ORG				=	\033[0;33m
YEL				=	\033[1;33m
GRN				=	\033[1;32m
BLU				=	\033[0;34m
CYN				=	\033[0;36m

SRCS_SERVER		=	$Sserver.c $Slib.c
SRCS_CLIENT		=	$Sclient.c $Slib.c

OBJS_SERVER		=	$(SRCS_SERVER:$S%.c=$O%.o)
OBJS_CLIENT		=	$(SRCS_CLIENT:$S%.c=$O%.o)

HEADER			=	-I $I

CC				=	clang

FLAGS			=	-Wall -Werror -Wextra

ECHO			=	echo -e -n

all:				$(NAME) $(CLIENT)

$(NAME):			$(OBJS_SERVER)
					@$(ECHO) "$(ORG)[Server] $(NOCOL)"
					@$(CC) $(FLAGS) $(SRCS_SERVER) $(HEADER) -o $(NAME)
					@$(ECHO) "$(GRN)=> Success!$(NOCOL)"

$(CLIENT):			$(OBJS_CLIENT)
					@$(ECHO) "\n$(ORG)[Client] $(NOCOL)"
					@$(CC) $(FLAGS) $(SRCS_CLIENT) $(HEADER) -o $(CLIENT)
					@$(ECHO) "$(GRN)=> Success!\n$(NOCOL)"

$O%.o: 				$S%.c
					@[ -d $(O) ] || mkdir -p $(O)
					@$(CC) $(CFLAGS) -c $< $(HEADER) -o $@

clean:
					@$(ECHO) "$(RED)[Objs] => Removed\n$(NOCOL)"
					@rm -rf $(O)

fclean:				clean
					@$(ECHO) "$(RED)[Binaries] => Removed\n$(NOCOL)"
					@rm -rf *.dSYM
					@rm -f $(NAME)
					@rm -f $(CLIENT)
					@find . -name ".DS_Store" -delete

re:					fclean all

run:				re
					@make clean
					@./server

bonus:				all

.PHONY:				all clean fclean re
