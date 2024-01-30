# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:33:41 by ecarvalh          #+#    #+#              #
#    Updated: 2024/01/30 17:10:56 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB		= libft
SRCS	= main.c $(wildcard fun/*.c)
ODIR	= objs
OBJS	= $(SRCS:%.c=$(ODIR)/%.o)
CFLAGS	= -Wall -Wextra -Werror -pedantic -I. -I$(LIB) -g
LDFLAGS	= -L$(LIB)
LDLIBS	= -lft
NAME	= push_swap

all: $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(LIB):
	@make -C libft

clean:
	$(RM)r $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(ODIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re $(LIB)
