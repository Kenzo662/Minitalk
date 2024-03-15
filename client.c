/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:46:52 by klopez            #+#    #+#             */
/*   Updated: 2024/03/15 17:42:25 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_pid;

int	main(int ac, char **av)
{
	int	i;

	if (ac == 3)
	{
		signal(SIGUSR1, signal_ok);
		i = -1;
		g_pid = ft_atoi(av[1]);
		while (av[2][++i])
			find_bit(av[2][i]);
		find_bit(av[2][i]);
	}
	else
		ft_printf
		("Send the server pid as first argument and a string as second.\n");
}

void	find_bit(unsigned char c)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (c / i >= 1)
		{
			c = c % i;
			if (kill(g_pid, SIGUSR1) == -1)
				return (ft_printf("Unvalid PID"), exit(0));
		}
		else if (kill(g_pid, SIGUSR2) == -1)
			return (ft_printf("Unvalid PID"), exit(0));
		i /= 2;
		usleep(5000);
	}
}

void	signal_ok(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Signal received\n");
}
