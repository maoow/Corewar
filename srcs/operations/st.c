/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:11 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/28 10:53:50 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static size_t	get_reg(t_cor *core, t_process *proc, int *pos)
{
	size_t		reg;

	*pos = proc->PC + proc->startpos;
	reg = core->arena[(*pos + 2) % MEM_SIZE] - 1;
	return (reg);
}

/*
** ST
**
** store the second param reg in the second param (ind or dir)(%IDX)
*/

bool			cw_st(t_cor *core, t_process *proc)
{
	size_t		reg;
	long int	adress;
	int			pos;

	if ((reg = get_reg(core, proc, &pos)) >= REG_NUMBER)
		return (proc->carry);
	adress = ind(core, proc, proc->PC + 3);
	if (adress > 65536 / 2)
		adress -= 65536;
	if (core->options->v4)
		ft_printf("P %4d | st r%d %d\n", proc->ID, reg + 1, adress);
	adress %= IDX_MOD;
	setram(core, adress + pos, proc->registres[reg], proc->color);
	return (proc->registres[reg] != 0);
}
