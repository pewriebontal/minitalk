/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:47:39 by mkhaing           #+#    #+#             */
/*   Updated: 2023/11/20 05:29:22 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(pid_t pid, char *payload)
{
	if (!payload)
		return ;
	while (*payload)
	{
		if (*payload == '1')
			kill(pid, SIGUSR1);
		else if (*payload == '0')
			kill(pid, SIGUSR2);
		usleep(500);
		payload++;
	}
}

int	main(int argc, char *argv[])
{
	char	*msg;
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID_SERVER] [STRING_TO_PASS]\n");
		return (1);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Wrong PID: %s\n", argv[1]);
		ft_printf("PID must be greater than 0.\n");
		return (1);
	}
	msg = argv[2];
	while (*msg)
	{
		send_signal(pid, ft_char_to_binary(*msg));
		msg++;
	}
	return (0);
}
