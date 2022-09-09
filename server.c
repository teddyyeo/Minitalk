/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:33:58 by tayeo             #+#    #+#             */
/*   Updated: 2022/09/09 17:07:08 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h> //TODO remove!!!!!!!!!!

void	 showbit(char c)
{
	char	b = c;

	for (int i = 0; i < 8; i++)
	{
		if ((b & 128) == 128)
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

size_t	size_handler(int sig, char bit_idx)
{
	static size_t	len;

	if (bit_idx == 0)
		len = 0;
	if (sig == SIGUSR1)
	{
		len = len << 1;
		len = len | 1;
	}
	if (sig == SIGUSR2)
		len = len << 1;
	return (len);
}

char	*str_handler(int sig, char *str, size_t len)
{
	static char*	start;
	static int	bit_idx;
	static size_t	l;

	if (start == NULL)
		start = str;
	if (sig == SIGUSR1)
	{
		*str = *str << 1;
		*str = *str | 1;
	}
	if (sig == SIGUSR2)
		*str = *str << 1;
	bit_idx++;
	if (bit_idx == 8)
	{
		l++;
		bit_idx = 0;
		str++;
		if (l == len)
		{
			printf("%s\n", start);
			free(start);
			start = NULL;
			str = NULL;
			l = 0;
		}
	}
	return (str);
}

void	handler(int sig)
{
	static char		size_flag;
	static char		bit_idx;
	static char		*str;
	static size_t	len;

	if (bit_idx < 32 && size_flag == 0)
	{
		len = size_handler(sig, bit_idx);
		bit_idx++;
		if (bit_idx == 32)
		{
			size_flag = 1;
			bit_idx = 0;
		}
		return ;
	}
	if (str == NULL)
		str = malloc(len + 1);
	str = str_handler(sig, str, len);
	if (str == NULL)
		size_flag = 0;
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
	}
	return (0);
}
