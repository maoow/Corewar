/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:05:57 by cbinet            #+#    #+#             */
/*   Updated: 2017/09/26 12:30:56 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"operations.h"

bool	cw_live(t_cor *core, t_process *proc)
{
	int champ;
	proc->live++;
	champ = (0 - getram(core, proc->PC + proc->startpos + 1)) % 4294967295;
	core->champs[champ].last_live = core->total_cycle;
	core->champs[champ].lives_in_period++;
	if (core->options->v4)
		ft_printf("P%5d | live %d\n",proc->ID, getram(core, proc->PC + proc->startpos + 1));
	return (true);
}
