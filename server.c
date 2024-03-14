#include "minitalk.h"

int	main(void)
{
	struct sigaction	sign;
	int					servpid;

	sign.sa_sigaction = handler;
	sign.sa_flags = SA_SIGINFO;
	sigemptyset(&sign.sa_mask);
	servpid = getpid();
	printf("PID %d\n", servpid);
	while (1)
	{
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
	}
}

void	handler(int signal, siginfo_t *siginfo, void *s)
{
	static unsigned char	c;
	static int				count;
	static unsigned char	*str;
	static int				i;

	(void)s;
	if (signal == SIGUSR1)
		c = c | 1 << (7 - count);
	count++;
	if (count == 8)
	{
		str = str_realloc(str);
		str[i] = c;
		count = 0;
		c = 0;
		i++;
		if (!str[i - 1])
		{
			ft_printf("%s\n", str);
			i = 0;
			free(str);
			str = NULL;
		}
	}
	kill(siginfo->si_pid, SIGUSR1);
}

unsigned char	*str_realloc(unsigned char *str)
{
	unsigned char	*newstr;
	int				i;

	i = 0;
	if (!str)
		return (ft_calloc((2), sizeof(char)));
	newstr = (ft_calloc((ft_strlen((char *)str) + 2), sizeof(char)));
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	free(str);
	str = NULL;
	return (newstr);
}
