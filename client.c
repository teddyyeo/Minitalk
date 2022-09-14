/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:32:24 by tayeo             #+#    #+#             */
/*   Updated: 2022/09/14 19:12:48 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_string(char *str, int pid)
{
	int	i;

	i = 0;
	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if ((*str & 128) == 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(30);
			*str = *str << 1;
			i++;
		}
		str++;
	}
}

void	send_size(size_t len, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((len & 2148473648UL) == 2147483648UL)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(30);
		len = len << 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	len;

	if (argc != 3)
	{
		write(1, "Argument Error\n", 15);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid > 99998)
	{
		write(1, "PID error\n", 10);
		return (0);
	}
	len = ft_strlen(argv[2]);
	send_size(len, pid);
	send_string(argv[2], pid);
	return (0);
}
