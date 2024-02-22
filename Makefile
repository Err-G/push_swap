# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:33:41 by ecarvalh          #+#    #+#              #
#    Updated: 2024/02/21 17:12:40 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB		= libft
SRCS	= main.c $(wildcard utils/*.c)
ODIR	= objs
OBJS	= $(SRCS:%.c=$(ODIR)/%.o)
B_SRCS	= bonus/main.c $(wildcard utils/*.c) $(wildcard bonus/*.c)
B_OBJS	= $(B_SRCS:%.c=$(ODIR)/%.o)
CFLAGS	= -Wall -Wextra -Werror -pedantic -I. -I$(LIB) -g
LDFLAGS	= -L$(LIB)
LDLIBS	= -lft
NAME	= push_swap

all: $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

bonus: $(B_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o checker $^ $(LDLIBS)

$(LIB):
	@make -C libft

clean:
	$(RM)r $(ODIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) checker

re: fclean all

$(ODIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re $(LIB)
