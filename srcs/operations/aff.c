/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:00 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/27 16:41:45 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

// info incoherentes concernant la modification du carry, a tester.
bool	aff(t_cor *core, t_process *proc);
{
	if (core->arena[proc->PC + 2] % 256 == 0)
	{
		proc->carry = false;
	}
	else
	{
		ft_putchar(core->arena[proc->PC + 2] % 256);
		proc->carry = true;
	}
	return (true);
}
