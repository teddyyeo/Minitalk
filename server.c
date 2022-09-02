#include "minitalk.h"

void showbit(char c)
{
	write(1, "State:\n", ft_strlen("State:\n"));
	char b = c;
	for (int i = 0; i < 8; i++)
	{
		if((b & 128) == 128)
		{
			write(1, "1", 2);
		}
		else
		{
			write(1, "0", 2);
		}
		b = b << 1;
	}
	write(1, "\n", 2);
}

void	handler(int sig)
{
	static char c = 'A';
	if (c == 'A')
		showbit(c);
	if (sig == SIGUSR1)
	{
		c = c << 1;
		c = c | 1;
		showbit(c);
		//write(1, "1", ft_strlen("1"));
	}
	if (sig == SIGUSR2)
	{
		c = c << 1;
		showbit(c);
		//write(1, "0", ft_strlen("1"));
	}
	if (sig == SIGINT)
		write(1, &c, 1);
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	signal(SIGINT, handler);
	ft_printf("PID: %d\n", getpid());
	while(1){}
	return (0);
}
