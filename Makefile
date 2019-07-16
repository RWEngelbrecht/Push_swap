# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 07:49:21 by rengelbr          #+#    #+#              #
#    Updated: 2019/07/16 10:40:48 by rengelbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a
PNME = push_swap
CNME = checker
FLGS = -Wall -Werror -Wextra
DBFLG = -Wall -Werror -Wextra -g
CSRC = checker.c \
		ft_operations.c \
		read_input.c \
		interpret_op.c \
		validator.c \
		$(LIB)
PSRC = push_swap.c \
		validator.c \
		ft_operations.c \
		$(LIB)

all: $(CNME) $(PNME)
	
$(CNME):
	gcc $(FLGS) $(CSRC) -o $(CNME)

$(PNME):
	gcc $(FLGS) $(PSRC) -o $(PNME)

db:
	gcc $(DBFLG) $(CSRC) -o $(CNME)
	gcc $(DBFLG) $(PSRC) -o $(PNME)

clean:
	rm -fr $(CNME) $(PNME) $(CNME).dSYM $(PNME).dSYM

re: clean all

redb: clean db