/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:48:42 by mvalient          #+#    #+#             */
/*   Updated: 2022/11/26 22:55:07 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handle(int signum, siginfo_t *info, void *context)
{
	static unsigned int		i = sizeof(char) * 8;
	static unsigned char	j;

	(void)context;
	i--;
	if (signum == TRUE)
		j |= 1 << i;
	if (!i)
	{
		write(1, &j, 1);
		i = sizeof(char) * 8;
		j = 0;
	}
	if (kill(info->si_pid, TRUE) == -1)
		write(1, "Error\n", 6);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handle;
	if (sigaction(TRUE, &sa, NULL) == -1)
		write(1, "Error\n", 6);
	if (sigaction(FALSE, &sa, NULL) == -1)
		write(1, "Error\n", 6);
	while (1)
		pause();
	return (0);
}
