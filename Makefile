##
## Makefile for borwein in /home/VEYSSI_B/rendu/Maths/110borwein
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Mon Apr  4 13:29:08 2016 Baptiste veyssiere
## Last update Mon Apr  4 13:47:37 2016 Baptiste veyssiere
##

NAME	= 110borwein

SRCS	= src/main.c	\
	  src/calc.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CC	= gcc

CFLAGS	= -I./include

LDFLAGS	= -lm

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
