NAME = libftprintf.a

SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):$(OBJECTS)
	ar -r $(NAME) $(OBJECTS)
	
clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re