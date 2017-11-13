/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regmanage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:04:09 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/13 13:45:26 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dispreg(t_process *proc)
{
	size_t	i;

	i = 0;
	ft_printf("\n");
	ft_printf("carry : %B\n", proc->carry);
	while (i < REG_NUMBER)
	{
		ft_printf("r%d = %d(10) %X(16)\n", i + 1, proc->registres[i],
				proc->registres[i]);
		i++;
	}
	ft_printf("\n");
}
