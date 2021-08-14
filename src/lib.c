/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:40:42 by pedro             #+#    #+#             */
/*   Updated: 2021/08/14 16:54:52 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putnbr(int num)
{
	if (num < 0)
		ft_putchar('-');
	else if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + '0');
	}
	else
		ft_putchar(num % 10 + '0');
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * sign >= 2147483647)
			return (2147483647);
		else if (num * sign <= -2147483648)
			return (-2147483648);
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (sign * num);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
