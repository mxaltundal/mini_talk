SRCS			=	ft_printf.c ft_itoa.c
OBJS			= $(SRCS:.c=.o)

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

.c.o:
				gcc $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)



.PHONY:			all clean fclean re .c.o
