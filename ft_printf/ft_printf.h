/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltunda <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:14:43 by maltunda          #+#    #+#             */
/*   Updated: 2022/03/15 13:14:45 by maltunda         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<unistd.h>
# include	<stdlib.h>

int	ft_printf(const char *xd, ...);

int	ichecker(va_list argp, char c);

int	ft_putstr(char *a);

int	ft_putchar(char a);

int	ft_printpointer(unsigned long int n);

int	base(char *base, int nbr, int n, char c);

#endif
