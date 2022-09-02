#include "minitalk.h"

void send_string(char *str, int pid)
{
	while (*str)
	{
		for (int i = 0; i < 8; i++)
		{
			if((*str & 128) == 128)
			{
				write(1, "1", 2);
				kill(pid, SIGUSR1);
				usleep(100);
			}
			else
			{
				write(1, "0", 2);
				kill(pid, SIGUSR2);
				usleep(100);
			}
			*str = *str << 1;
		}
	}
}

void send_size(size_t len, int pid)
{
	for (int i = 0; i < 32; i++)
	{
		if((len & 2148473648UL) == 2147483648UL)
		{
			write(1, "1", 2);
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else
		{
			write(1, "0", 2);
			kill(pid, SIGUSR2);
			usleep(100);
		}
		len = len << 1;
	}

}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Argument Error\n");
		return (0);
	}
	//ft_printf("argv[0]: %s\n", argv[0]);
	int pid = ft_atoi(argv[1]);
	size_t len = ft_strlen(argv[2]);

	send_size(len, pid);
	return (0);
}
