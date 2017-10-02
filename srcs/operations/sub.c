/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:13 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/02 14:11:48 by starrit          ###   ########.fr       */
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
	if (res == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (core->options->v4)
		ft_printf("P%5d | sub %d %d\n", proc->ID, 0,0);
	return (proc->registres[proc->PC + proc->startpos + 4] != 0);
	core = NULL;
	//
}
