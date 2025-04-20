/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:45:13 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 18:35:46 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	c;
	static int				i;

	if (signal == SIGUSR1)
		c |= 1 << i;
	else if (signal == SIGUSR2)
		c |= 0 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_putchar('\n');
			c = 0;
			i = 0;
		}
		else
		{
			ft_putchar(c);
			c = 0;
			i = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	(void)**argv;
	if (argc != 1)
	{
		ft_putstr("Error: INVALID number of arguments try again\n");
		return (0);
	}
	ft_putstr("server PID is : ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		;
	return (0);
}
