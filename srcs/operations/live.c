/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:05:57 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/14 16:56:16 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_live(t_cor *core, t_process *proc)
{
	size_t		champ;
	int			i;
	t_champ		*tmp;

	proc->live++;
	champ = -(getram(core, proc->PC + proc->startpos + 1) % 4294967295);
	tmp = core->champs;
	i = 1;
	while (tmp && champ != tmp->ID)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp)
	{
		tmp->last_live = core->total_cycle;
		tmp->lives_in_period++;
		core->last_champ_alive = tmp->name;
	}
		if (core->options->v4)
			ft_printf("P%5d | live %d\n", proc->ID,
					getram(core, proc->PC + proc->startpos + 1));
	return (true);
}
