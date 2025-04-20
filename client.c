/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:45:37 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 18:36:39 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(300);
		i--;
	}
}

int	argument_checker(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("Error: Wrong number of arguments\n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		ft_putstr("Error: Wrong PID try again!!!!\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argument_checker(argc, argv) == 0)
		return (0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
