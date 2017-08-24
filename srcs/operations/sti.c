/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:12 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/24 15:40:32 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_sti(t_cor *core, t_process *proc)
{
	size_t		adress;
	size_t		adress2;

	adress = getparam(core, proc, 2, 2);
	adress2 = getparam(core, proc, 3, 2);
	adress += adress2;
	setram(core, adress, proc->registres[core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] - 1], proc->color);
	if (core->verbose)
		ft_printf("sti | r%d %d %d\n", core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] - 1, adress, adress2);
	return (true);
}
