/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:48:42 by mvalient          #+#    #+#             */
/*   Updated: 2022/11/25 20:47:03 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handle(int signum)
{
	static unsigned int		i = sizeof(char) * 8;
	static unsigned char	j;

	i--;
	if (signum == 12)
		j += 1 << i;
	if (!i)
	{
		write(1, &j, 1);
		i = sizeof(char) * 8;
		j = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = ft_handle;
	sigaction(TRUE, &sa, NULL);
	sigaction(FALSE, &sa, NULL);
	while (1)
		pause();
	return (0);
}
