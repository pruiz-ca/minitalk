/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 01:24:45 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/08/14 17:02:38 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

/* LIB */
void	ft_putchar(int c);
void	ft_putstr(char *str);
void	ft_putnbr(int num);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/* MINITALK */
void	ft_receivemsg(int signum);
void	ft_sendmsg(pid_t pid, char *msg);

#endif
