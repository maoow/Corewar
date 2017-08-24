/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:00 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/24 16:39:22 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_aff(t_cor *core, t_process *proc)
{
	if (proc->registres[core->arena[(proc->PC + 2) % MEM_SIZE]] % 256 == 0)
		return (false);
	else
		ft_putchar(proc->registres[core->arena[(proc->PC + 2) % MEM_SIZE]] % 256);
	return (true);
}
