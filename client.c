/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:52:56 by mvalient          #+#    #+#             */
/*   Updated: 2022/11/24 10:20:22 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(char *message)
{
	int	i;

	i = 8;
	while (*message)
	{
		while (i--)
		{
			if ((*message >> i) & 1)
				ft_printf("1");
			else
				ft_printf("0");
		}
		i = 8;
		message++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_send_message(argv[2]);
	}
	else
		ft_printf("Error: You should input PID and MESSAGE as parameters");
	return (0);
}
