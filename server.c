/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:48:42 by mvalient          #+#    #+#             */
/*   Updated: 2022/11/24 12:15:54 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handle(int signum)
{
	static int	i;

	if (signum == 10)
	{
		ft_printf("0");
		i++;
	}
	else if (signum == 12)
	{
		ft_printf("1");
		i++;
	}
	if (i == 8)
	{
		ft_printf("\n");
		i = 0;
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
