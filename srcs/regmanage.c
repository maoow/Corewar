/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regmanage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:04:09 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/11 16:53:35 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dispreg(t_process *proc)
{
	size_t	i;

	i = 0;
	ft_printf("\n");
	while (i < REG_NUMBER)
	{
		ft_printf("r%d = %d(10) %X(16)\n", i + 1, proc->registres[i],
				proc->registres[i]);
		i++;
	}
	ft_printf("\n");
}
