/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:05:57 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/13 14:23:26 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** LIVE
**
** take the only param and increase the corresponding champ live rate
*/

bool	cw_live(t_cor *core, t_process *proc)
{
	int			champ;
	t_champ		*tmp;

	proc->live++;
	champ = getram(core, proc->PC + proc->startpos + 1);
	tmp = core->champs;
	while (tmp && champ != tmp->ID)
	{
		tmp = tmp->next;
	}
	if (tmp)
	{
		tmp->last_live = core->total_cycle;
		tmp->lives_in_period++;
		core->last_champ_alive = tmp->ID;
	}
	if (core->options->v4)
		ft_printf("P%5d | live %d\n", proc->ID,
				getram(core, proc->PC + proc->startpos + 1));
	return (true);
}
