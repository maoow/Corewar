/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:12 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/02 19:05:06 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_sti(t_cor *core, t_process *proc)
{
	size_t		adress;
	size_t		adress2;
	size_t		total;

	// + 4 et + 2 dans le cas sans reg
	// a faire : un truc generique
	adress = core->arena[proc->PC + 4 + proc->startpos];
	adress2 = core->arena[proc->PC + 2 + proc->startpos];
	total = adress + adress2;
	//a finir + 2 - 2 en verifiant sur d'autres sti
	setram(core, proc->PC + total, core->arena[proc->PC + 2 + proc->startpos] - 2, proc->color);
	if (core->options->v4)
		ft_printf("P%5d | sti r%d %d %d\n", proc->ID,core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE], adress, adress2);
	return (true);
}

/*

TON STI ICI

bool	cw_sti(t_cor *core, t_process *proc)
{
	size_t		adress;
	size_t		adress2;

	adress = getparam(core, proc, 2, 2);
	adress2 = getparam(core, proc, 3, 2);
	adress += adress2;
	setram(core, adress, proc->registres[core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] - 1], proc->color);
	if (core->options->v4)
		ft_printf("P%5d | sti r%d %d %d\n", proc->ID,core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] - 1, adress - adress2, adress2);
	return (true);
}*/
