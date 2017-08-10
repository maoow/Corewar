/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:09 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/10 14:34:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	lldi(t_cor *core, t_process *proc)
{
	size_t adress;

	adress = getparam(core, proc, 1, 2);
	adress += getparam(core, proc, 2, 2);
	proc->registres[core->arena[getparamplace(core, proc, 3, 2)]] =
	getram(core, proc->startpos + adress));
	return (proc->registres[core->arena[getparamplace(core, proc, 3, 2)]] != 0);
}
