/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:40:42 by starrit           #+#    #+#             */
/*   Updated: 2017/07/21 13:20:56 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		usage(void)
{
	ft_printf("Usage: ./corewar [-dump N -n N -s N] <champion1.cor> <...>\n");
	ft_printf("\t-dunmp N\t\t: dump memory after N cycles then exits\n");
	ft_printf("\t-n N    \t\t: set player number\n");
	ft_printf("\t-s N    \t\t:runs n cycles, dumps memory, pauses, then repeats");
}
