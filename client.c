/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:52:56 by mvalient          #+#    #+#             */
/*   Updated: 2022/11/26 23:08:15 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handle(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == TRUE)
		write(1, "Signal sent correctly\n", 22);
}

static void	ft_send_message(int target, char *message)
{
	int	i;

	i = sizeof(char) * 8;
	while (*message)
	{
		while (i--)
		{
			if ((*message >> i) & 1)
				kill(target, TRUE);
			else
				kill(target, FALSE);
			usleep(100);
		}
		i = 8;
		message++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handle;
	if (sigaction(TRUE, &sa, NULL) == -1)
		write(1, "Error\n", 6);
	if (argc == 3)
		ft_send_message(ft_atoi(argv[1]), argv[2]);
	else
		ft_printf("Error: You should input PID and MESSAGE as parameters");
	return (0);
}
