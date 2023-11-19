/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:47:46 by mkhaing           #+#    #+#             */
/*   Updated: 2023/11/20 05:29:25 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	handle_signal(int sig)
{
	static char	*binary;
	static int	index;

	if (!binary)
	{
		binary = (char *)malloc(sizeof(char) * 9);
		if (!binary)
			return ;
		index = 0;
		binary[8] = '\0';
	}
	if (sig == SIGUSR1)
		binary[index] = '1';
	else
		binary[index] = '0';
	index++;
	if (index == 8)
	{
		ft_printf("%c", ft_binary_to_char(binary));
		free(binary);
		binary = NULL;
		index = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		usleep(500);
		pause();
	}
}
