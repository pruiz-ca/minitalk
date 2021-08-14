/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 01:24:17 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/08/14 16:54:58 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receivemsg(int signum)
{
	static int		j = -1;
	static char		ch = 0;

	j++;
	if (signum == SIGUSR2)
		ch |= (128 >> j);
	if (j == 7)
	{
		if (!ch)
			ft_putchar('\n');
		else
			ft_putchar(ch);
		j = -1;
		ch = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid < 0)
		ft_putstr("Error\n");
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, ft_receivemsg);
	signal(SIGUSR2, ft_receivemsg);
	while (1)
		pause();
	return (0);
}
