/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukfe <mbuyukfe@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:04:45 by mbuyukfe          #+#    #+#             */
/*   Updated: 2025/02/18 18:08:36 by mbuyukfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}

static void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*message;

	if (ac != 3)
	{
		write(1, "Error: Invalid arguments\n", 25);
		write(1, "Usage: ./client <server_pid> <message>\n", 39);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "Error: Invalid PID\n", 19);
		return (1);
	}
	message = av[2];
	i = 0;
	while (message[i] != '\0')
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
