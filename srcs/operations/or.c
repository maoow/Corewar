/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:10 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/06 11:12:11 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_or(t_cor *core, t_process *proc)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = getparam(core, proc, 1, 4);
	b = getparam(core, proc, 2, 4);
	c =core->arena[getparamplace(core, proc, 3, 4) % MEM_SIZE];
	proc->registres[c] = a || b;
	if (core->options->v4)
		ft_printf("P%5d | or %d %d r%d\n",proc->ID, a, b, c);
	return (proc->registres[c] == 0);
}
