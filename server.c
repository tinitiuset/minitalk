/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:48:42 by mvalient          #+#    #+#             */
/*   Updated: 2022/11/25 12:41:43 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handle(int signum)
{
	static int	i = sizeof(char) * 8;
	static char	j;

	i--;
	if (signum == 12)
		j += 1 << i;
	if (!i)
	{
		write(1, &j, 1);
		i = 8;
		j = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(TRUE, ft_handle);
	signal(FALSE, ft_handle);
	while (1)
		pause();
	return (0);
}
