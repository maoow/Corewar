/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:14 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/31 14:54:59 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_zjmp(t_cor *core, t_process *proc)
{
	int jump;
	jump = ind(core, proc, proc->PC + 1) % MEM_SIZE;
	if (jump > MEM_SIZE / 2)
		jump -= MEM_SIZE;
	if (core->options->v4)
		ft_printf("P%5d | zjmp %d ",proc->ID, jump);
	if (proc->carry)
	{
	if (core->options->v4)
		ft_printf("OK\n");
		proc->PC += jump;
	}
	else if (core->options->v4)
		ft_printf("\n");
	return (true);
}
