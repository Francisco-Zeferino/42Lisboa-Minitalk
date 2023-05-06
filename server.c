/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:19:37 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/05/06 15:21:48 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binToChar(int sig)
{
	static int	i;
	static int	bit;

	if (sig == SIGUSR1)
	{
		i |= (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("No input required!");
		return (1);
	}
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, binToChar);
		signal(SIGUSR2, binToChar);
		pause();
	}
	return (0);
}
