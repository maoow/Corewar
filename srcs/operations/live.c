/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:05:57 by cbinet            #+#    #+#             */
/*   Updated: 2017/09/02 15:22:23 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"operations.h"

bool	cw_live(t_cor *core, t_process *proc)
{
	
	proc->live++;
	core->champs[getram(core, proc->PC + proc->startpos + 1)].last_live = core->total_cycle;
	core->champs[getram(core, proc->PC + proc->startpos + 1)].lives_in_period++;
	if (core->options->v4)
		ft_printf("P%5d | live %d\n",proc->ID, getram(core, proc->PC + proc->startpos + 1));
	return (true);
}
