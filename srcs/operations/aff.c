/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:00 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/10 15:00:09 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

// info incoherentes concernant la modification du carry, a tester.
bool	aff(t_cor *core, t_process *proc);
{
	if (proc->registres[core->arena[proc->PC + 2]] % 256 == 0)
		return (false);
	else
		ft_putchar(proc->registres[core->arena[proc->PC + 2]] % 256);
	return (true);
}
