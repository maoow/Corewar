/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:05:57 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/28 12:53:54 by cbinet           ###   ########.fr       */
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
	champ = getram(core, proc->pc + proc->startpos + 1);
	tmp = core->champs;
	while (tmp && champ != tmp->id)
	{
		tmp = tmp->next;
	}
	if (tmp)
	{
		tmp->last_live = core->total_cycle;
		tmp->lives_in_period++;
		core->last_champ_alive = tmp->id;
	}
	if (core->options->v4)
		ft_printf("P %4d | live %d\n", proc->id,
				getram(core, proc->pc + proc->startpos + 1));
	return (true);
}
