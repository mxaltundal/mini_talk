SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
PRINTF_DIR = ./ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

ft_printf:
	make -C $(PRINTF_DIR)

server: server.o ft_printf
	$(CC) -o $@ $< -lftprintf -Lft_printf

client: client.o ft_printf
	$(CC) -o $@ $< -lftprintf -Lft_printf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)
	make -C ft_printf clean
	
fclean: clean
	rm -f server client ft_printf/ft_printf.a

re: fclean all

.PHONY: all bonus ft_printf clean fclean re

