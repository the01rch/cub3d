# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 19:41:59 by redrouic          #+#    #+#              #
#    Updated: 2025/02/26 20:59:48 by redrouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC     =	src/main.c\
			src/utils.c\
			src/gest_err.c\
			src/str2arr.c
		
CC      =   cc

SOBJ    =   $(SRC:.c=.o)

NAME    =   cub3d

RM      =   rm -rf

CFLAGS  +=  -Wall -Wextra -Werror -g3

# Colors
RED     =   \033[0;31m
GREEN   =   \033[0;32m
GREY    =   \033[90m
BLUE    =   \033[0;94m
NC      =   \033[0m
IRED    =   \033[0;91m
PURPLE  =   \033[0;95m

all: $(NAME)

$(NAME): $(SOBJ)
	@echo -e '$(BLUE)Cflags$(NC) : $(GREY)$(CFLAGS)$(NC)'
	@$(CC) $(CFLAGS) $(SOBJ) -o $(NAME) 2>>errors.txt\
		&& echo -e '$(BLUE)Create$(NC) : $(GREY)$(NAME)$(NC)' \
		|| echo -e '$(RED)[ FAILED ]$(NC): __Create__ $(GREY)$(NAME)$(NC)'

clean:
	@$(RM) $(SOBJ)
	@echo -e '$(BLUE)Clean$(NC)  : $(GREY)$(SOBJ)$(GREEN) [ OK ]$(NC)'

fclean: clean
	@$(RM) errors.txt
	@echo -e '$(BLUE)Clean$(NC)  : $(GREY)errors.txt$(GREEN) [ OK ]$(NC)'
	@$(RM) $(NAME)
	@echo -e '$(BLUE)Fclean$(NC) : $(GREY)$(NAME)$(GREEN) [ OK ]$(NC)'

re: fclean all

.PHONY: all clean fclean re
