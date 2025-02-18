/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuyukfe <mbuyukfe@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:20:11 by mbuyukfe          #+#    #+#             */
/*   Updated: 2025/02/18 18:10:53 by mbuyukfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

static void	ft_handle(int sig)
{
	static int	bit = 0;
	static int	current_char = 0;

	if (sig == SIGUSR1)
		current_char |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &current_char, 1);
		bit = 0;
		current_char = 0;
	}
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		pause();
	return (0);
}
