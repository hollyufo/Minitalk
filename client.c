/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:45:37 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/06 20:45:42 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("Usage: ./client <PID> <string>\n");
		return (1);
	}

	pid_t	pid = ft_atoi(argv[1]);
	char	*str = argv[2];

	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\n'); // send newline
	return (0);
}
