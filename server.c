/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:45:13 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 17:25:07 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "minitalk.h"

// Global variable to store the message being received
static char	g_char = 0;
static int	g_bit_count = 0;

/*
 * Signal handler for SIGUSR1 and SIGUSR2
 * SIGUSR1 represents a 0 bit
 * SIGUSR2 represents a 1 bit
 */
void	handle_signal(int signum, siginfo_t *info, void *context)
{
	(void)context;
	
	// Shift the current character and add the bit (1 for SIGUSR2, 0 for SIGUSR1)
	g_char = g_char << 1;
	if (signum == SIGUSR2)
		g_char = g_char | 1;
	
	g_bit_count++;
	
	// After receiving 8 bits (a complete character)
	if (g_bit_count == 8)
	{
		ft_putchar(g_char);
		g_bit_count = 0;
		g_char = 0;
		
		// In the bonus part, send acknowledgment to client
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;
	
	// Initialize variables
	g_char = 0;
	g_bit_count = 0;
	
	// Get and display server PID
	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	
	// Set up signal handling
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	
	// Register signal handlers
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr("Error setting up signal handlers\n");
		return (1);
	}
	
	// Keep the server running indefinitely
	while (1)
		pause();
	
	return (0);
}