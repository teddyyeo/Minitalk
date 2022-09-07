/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:32:24 by tayeo             #+#    #+#             */
/*   Updated: 2022/09/07 21:10:01 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_string(char *str, int pid)
{
	while (*str)
	{
		for (int i = 0; i < 8; i++)
		{
			if((*str & 128) == 128)
			{
				kill(pid, SIGUSR1);
				usleep(100);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(100);
			}
			*str = *str << 1;
		}
		str++;
	}
}

void send_size(size_t len, int pid)
{
	for (int i = 0; i < 32; i++)
	{
		if ((len & 2148473648UL) == 2147483648UL)
		{
			write(1, "1", 1);
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else
		{
			write(1, "0", 1);
			kill(pid, SIGUSR2);
			usleep(100);
		}
		len = len << 1;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	len;

	if (argc != 3)
	{
		ft_printf("Argument Error\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	send_size(len, pid);
	send_string(argv[2], pid);
	return (0);
}
