/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:10 by cbinet            #+#    #+#             */
/*   Updated: 2017/09/29 18:12:57 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_or(t_cor *core, t_process *proc)
{
	size_t	a;
	size_t	b;

	a = getparam(core, proc, 1, 4);
	b = getparam(core, proc, 2, 4);
	if (core->options->v4)
		ft_printf("P%5d | or %d %d\n", proc->ID, a, b);
	proc->registres[core->arena[(getparamplace(core, proc, 3, 4)) % MEM_SIZE]] = a || b;
	return (proc->registres[core->arena[(getparamplace(core, proc, 3, 4)) % MEM_SIZE]] != 0);
}
