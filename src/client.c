/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:59:04 by pedro             #+#    #+#             */
/*   Updated: 2021/08/14 17:08:01 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendmsg(pid_t pid, char *msg)
{
	int		i;
	int		j;

	i = -1;
	while (msg[++i])
	{
		j = -1;
		while (++j < 8)
		{
			if (msg[i] & 128 >> j)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	while (--j >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(150);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = -1;
	if (argc != 3)
	{
		ft_putstr("Error: Arguments\n");
		return (1);
	}
	while (argv[1][++i])
	{
		if (!(ft_isdigit(argv[1][i])))
		{
			ft_putstr("Error: Wrong pid\n");
			return (1);
		}
	}
	pid = ft_atoi(argv[1]);
	ft_sendmsg(pid, argv[2]);
	return (0);
}
