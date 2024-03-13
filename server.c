#include "minitalk.h"

int	main(void)
{
	int	pid;
	pid = getpid();
	printf("pid %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
}

void	handler(int signal)
{
	static unsigned char c;
	static int count;
	static unsigned char	*str;
	static int i;

	if (signal == SIGUSR1)
		c = c | 1 << (7 - count);
	count++;
	if (count == 8)
	{
		str = str_realloc(str);
		str[i] = c;
		count = 0;
		c = 0;
		if(!str[i])
			ft_printf("%s\n", str);
		i++;
	}
}

unsigned char	*str_realloc(unsigned char *str)
{
	unsigned char *newstr;\
	int i;

	i = 0;
	if (!str)
		return (ft_calloc((2), sizeof(char)));
	newstr = (ft_calloc((ft_strlen((char *)str) + 2), sizeof(char)));
	while(str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	free(str);
	return (newstr);
}
