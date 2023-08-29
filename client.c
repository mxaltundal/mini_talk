/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltunda <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:09:16 by maltunda          #+#    #+#             */
/*   Updated: 2022/06/21 14:27:44 by maltunda         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void	sendsignal(char *msg, int pid, int count, int i)
{
	unsigned char	a;

	while (msg[++i])
	{
		a = msg[i];
		count = 128;
		while (count > 0)
		{	
			if (a / count)
			{	
				kill(pid, SIGUSR1);
				a -= count;
			}
			else
				kill(pid, SIGUSR2);
			count /= 2;
			usleep(25);
		}
	}
	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(25);
	}
}

void	handler2(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Mesaj Başarıyla Gönderildi");
	exit(1);
}

int	main(int argc, char **argv)
{
	int				pid;
	int				i;
	int				count;

	i = -1;
	count = 7;
	signal(SIGUSR1, &handler2);
	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("yanlış sayıda argüman girdiniz tekrar deneyiniz");
		exit (0);
	}
	else
		sendsignal(argv[2], pid, count, i);
	while (1)
		pause();
	return (0);
}
