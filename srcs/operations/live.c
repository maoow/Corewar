/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:05:57 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/29 13:09:33 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_live(t_cor *core, t_process *proc)
{
	long int	champ;
	t_champ		*tmp;

	proc->live++;
	champ = -(getram(core, proc->PC + proc->startpos + 1));
	champ %= 4294967296;
	if (champ < 0)
	champ += 4294967296;
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
