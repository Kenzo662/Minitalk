#include "minitalk.h"

int	pid;

int	main(int ac, char **av)
{
	int i;
	(void)ac;
	i = -1;
	pid = ft_atoi(av[1]);
	while(av[2][++i])
		find_bit(av[2][i]);
	find_bit(av[2][i]);
}

void	find_bit(unsigned char c)
{
	int i;

	i = 128;

	while (i > 0)
	{
		if (c / i >= 1)
		{
			c = c % i;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		i /= 2;
		usleep(10000);
	}
}


