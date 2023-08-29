/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltunda <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:09:31 by maltunda          #+#    #+#             */
/*   Updated: 2022/06/15 16:36:59 by maltunda         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

void	signalprinter(int signal, int clientid)
{
	static int				count;
	static unsigned char	a;

	if (signal == SIGUSR1)
			a |= 1;
	if (count != 7)
	{
		a <<= 1;
	}
	count++;
	if (count == 8)
	{	
		if (!a)
		{
			ft_printf("\n");
			kill(clientid, SIGUSR1);
			usleep(25);
		}
		else
			ft_printf("%c", a);
		count = 0;
		a = 0;
	}
}

void	handler(int signal, siginfo_t *info, void *context)
{
	int						clientid;

	(void)context;
	clientid = info->si_pid;
	signalprinter(signal, clientid);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	return (0);
}
