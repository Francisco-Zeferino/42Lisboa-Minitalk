/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:57:21 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/05/10 11:58:28 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int sig, siginfo_t *siginfo, void *context)
{
	static int	i;
	static int	bit;
	int			pid;
	char		*str;

	(void)context;
	pid = siginfo->si_pid;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		str = &i;
		ft_printf("%s", str);
		bit = 0;
		if (i == 0)
		{
			kill(pid, SIGUSR1);
			write(1, "\n", 1);
		}
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	handler;
	int					pid;

	handler.sa_flags = SA_SIGINFO;
	handler.sa_sigaction = handle_signal;
	sigemptyset(&handler.sa_mask);
	(void)argv;
	if (argc != 1)
	{
		ft_printf("No input required!");
		return (1);
	}
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("Waiting for signal...\n");
	while (1)
	{
		sigaction(SIGUSR1, &handler, NULL);
		sigaction(SIGUSR2, &handler, NULL);
		pause();
	}
	//usleep(0);
	return (0);
}
