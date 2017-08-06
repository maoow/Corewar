/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsmanage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:23:04 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/04 14:41:22 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t	ind(t_cor *core, t_process *proc, size_t PC)
{
	size_t value;

	value = core->arena[proc->startpos + PC];
	value *= 256;
	value += core->arena[proc->startpos + PC + 1];
	return (value);
}

