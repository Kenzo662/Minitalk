#ifndef MINITALK_H
#define MINITALK_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>

void	handler(int signal, siginfo_t *singinfo, void *s);
void	find_bit(unsigned char c);
void	signal_ok(int signal);
unsigned char	*str_realloc(unsigned char *str);

#endif
