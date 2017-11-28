/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:00 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/28 12:53:54 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** AFF
**
** store in a buffer the value of the reg given in params,
** print the buffer if the reg is equal to zero
*/

void			print_procbuff(t_process *proc)
{
	size_t	i;

	i = 0;
	while (i < proc->buffc && i < 128)
	{
		ft_putchar(proc->buff[i]);
		i++;
	}
	proc->buffc = 0;
}

bool			cw_aff(t_cor *core, t_process *proc)
{
	int		pos;

	pos = (proc->pc + 2) % MEM_SIZE;
	if (proc->registres[mod(core->arena[pos] - 1, 16)] % 256 == 0)
	{
		if (!core->options->visu)
			print_procbuff(proc);
		return (false);
	}
	else
	{
		if (!core->options->visu && proc->buffc >= 127)
			print_procbuff(proc);
		proc->buff[proc->buffc] =
			proc->registres[mod(core->arena[pos] - 1, 16)] % 256;
		proc->buffc++;
	}
	return (true);
}
