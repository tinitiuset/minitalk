/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:48:42 by mvalient          #+#    #+#             */
/*   Updated: 2022/11/24 11:16:46 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle_false(void)
{
	ft_printf("0");
}

void	ft_handle_true(void)
{
	ft_printf("1");
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(TRUE, ft_handle_true);
	signal(FALSE, ft_handle_false);
	while (1)
		pause();
	return (0);
}
