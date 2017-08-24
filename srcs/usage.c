/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:40:42 by starrit           #+#    #+#             */
/*   Updated: 2017/08/24 16:34:43 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*void		usage(void)
{
	ft_printf("Usage: ./corewar [-dump N -n N -s N] <champion1.cor> <...>\n");
	ft_printf("\t-dunmp N\t\t: dump memory after N cycles then exits\n");
	ft_printf("\t-n N    \t\t: set player number\n");
	ft_printf("\t-s N    \t\t:runs n cycles, dumps memory, pauses, then repeats");
}*/

void		write_error(int nb)
{
	if (nb == 2)
		exit(ft_printf("Malloc error\n"));
	if (nb == 3)
		exit(ft_printf("Input error\n"));
	if (nb == 4)
		exit(ft_printf("Too many players\n"));
}
