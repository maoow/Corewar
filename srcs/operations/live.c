/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:05:57 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/30 16:04:23 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"operations.h"

bool	cw_live(t_cor *core, t_process *proc)
{
	
	proc->live++;
	core->champs[getram(core, proc->PC + proc->startpos + 1)].alive = true;
	if (core->verbose)
		ft_printf("P%5d | live %d\n",proc->ID, getram(core, proc->PC + proc->startpos + 1));
	return (true);
}
