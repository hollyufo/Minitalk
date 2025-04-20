/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:45:37 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 17:27:57 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include "minitalk.h"

// Global variable to track if an acknowledgment was received
static volatile sig_atomic_t g_ack_received = 0;

/*
 * Signal handler for acknowledgment from server
 */
void	handle_acknowledgment(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

/*
 * Send a single character to the server, bit by bit
 */
void	send_char(pid_t server_pid, char c)
{
	int	bit;
	int	i;
	
	i = 7;  // Start with the most significant bit
	while (i >= 0)
	{
		bit = (c >> i) & 1;  // Extract each bit
		
		// Send SIGUSR2 for 1, SIGUSR1 for 0
		if (bit == 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		
		// Wait for acknowledgment (bonus part)
		g_ack_received = 0;
		usleep(500);  // Give the server time to process
		
		i--;
	}
}

/*
 * Send the entire string to the server
 */
void	send_string(pid_t server_pid, char *str)
{
	while (*str)
	{
		send_char(server_pid, *str);
		str++;
	}
	
	// Optionally send a null terminator to indicate end of string
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	struct sigaction	sa;
	
	// Check arguments
	if (argc != 3)
	{
		ft_putstr("Usage: ./client [server_pid] [string_to_send]\n");
		return (1);
	}
	
	// Get server PID from arguments
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr("Invalid server PID\n");
		return (1);
	}
	
	// Set up signal handler for acknowledgment (bonus part)
	sa.sa_handler = handle_acknowledgment;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr("Error setting up signal handler\n");
		return (1);
	}
	
	// Send the string to the server
	send_string(server_pid, argv[2]);
	
	return (0);
}
