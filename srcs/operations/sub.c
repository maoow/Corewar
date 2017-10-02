/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:13 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/02 16:19:58 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_sub(t_cor *core, t_process *proc)
{
	int		res;

	res = 
		proc->registres[proc->PC + proc->startpos + 2] -
		proc->registres[proc->PC + proc->startpos + 3];
	proc->registres[proc->PC + proc->startpos + 4] = res;
	if (core->options->v4)
		ft_printf("P%5d | sub r%d r%d r%d\n",
			proc->ID,core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE],
			core->arena[(proc->PC + proc->startpos + 3) % MEM_SIZE],
			core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE]);
	if (res == 0)
		proc->carry = true;
	else
		proc->carry = false;
	return (proc->carry);
}
