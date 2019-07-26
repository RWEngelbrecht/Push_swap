# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 07:49:21 by rengelbr          #+#    #+#              #
#    Updated: 2019/07/26 08:58:32 by rengelbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKELIB = -C libft
LIB = libft/libft.a
PNME = push_swap
CNME = checker
FLGS = -Wall -Werror -Wextra
DBFLG = -Wall -Werror -Wextra -g
CSRC = checker.c \
		$(LIB) \
		src/*.c
		# stack_functions.c \
		# push_to.c \
		# swap_ops.c \
		# rotate_ops.c \
		# read_input.c \
		# interpret_op.c \
		# validator.c \
		# sub_validator.c 
		
PSRC = push_swap.c \
		$(LIB) \
		src/*.c
		# validator.c \
		# sub_validator.c \
		# stack_functions.c
		

all: $(MAKELIB) $(CNME) $(PNME)

$(MAKELIB):
	$(MAKE) $(MAKELIB)

$(CNME):
	gcc $(FLGS) $(CSRC) -o $(CNME)

$(PNME):
	gcc $(FLGS) $(PSRC) -o $(PNME)

db:
	gcc $(DBFLG) $(CSRC) -o $(CNME)
	gcc $(DBFLG) $(PSRC) -o $(PNME)

clean:
	rm -fr $(CNME) $(PNME) $(CNME).dSYM $(PNME).dSYM

fclean: clean
	rm -f libft/*.o libft/libft.a

re: clean all

redb: clean db