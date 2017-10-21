/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:00 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/21 14:45:02 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void		print_procbuff(t_process *proc)
{
	size_t	i;

	i = 0;
	while (i < proc->buffc && i < 128)
	{
		//ft_putchar(proc->buff[i]);
		i++;
	}
	proc->buffc = 0;
}

bool			cw_aff(t_cor *core, t_process *proc)
{
	/*
	if (proc->registres[mod(core->arena[(proc->PC + 2) % MEM_SIZE] - 1, 16)] % 256 == 0)
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
			proc->registres[mod(core->arena[(proc->PC + 2) % MEM_SIZE] - 1, 16)] % 256;
		proc->buffc++;
	}
	*/
	return (true);
	(void)proc;
	(void)core;
}
