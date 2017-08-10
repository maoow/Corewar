/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:12 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/10 15:00:10 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	sti(t_cor *core, t_process *proc)
{
	size_t		adress;

	adress = getparam(core, proc, 2, 2);
	adress += getparam(core, proc, 3, 2);
	setram(core, adress, proc->registres[core->arena[proc->PC +proc->startpos + 2]]);
	return (true);
}
