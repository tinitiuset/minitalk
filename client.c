/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:52:56 by mvalient          #+#    #+#             */
/*   Updated: 2022/11/24 11:20:48 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(int target, char *message)
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
			usleep(10);
		}
		i = 8;
		message++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_send_message(ft_atoi(argv[1]), argv[2]);
	}
	else
		ft_printf("Error: You should input PID and MESSAGE as parameters");
	return (0);
}
