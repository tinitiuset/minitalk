/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:52:56 by mvalient          #+#    #+#             */
/*   Updated: 2022/11/23 23:12:08 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	target_pid;

	if (argc == 3)
	{
		target_pid = ft_atoi(argv[1]);
	}
	else
		ft_printf("Error: You should input PID and MESSAGE as parameters");
	return (0);
}
