/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:10:18 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/10 13:52:32 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t	getram(t_cor *core, size_t address)
{
	size_t	value;

	value = core->arena[(address) % MEM_SIZE];
	value *= 256;
	value = core->arena[(address + 1) % MEM_SIZE];
	value *= 256;
	value = core->arena[(address + 2) % MEM_SIZE];
	value *= 256;
	value = core->arena[(address + 3) % MEM_SIZE];
	return (value);
}
void		setram(t_cor *core, size_t address, size_t value)
{
	core->arena[(address + 3) % MEM_SIZE] = value % 256;
	value /= 256;
	core->arena[(address + 2) % MEM_SIZE] = value % 256;
	value /= 256;
	core->arena[(address + 1) % MEM_SIZE] = value % 256;
	value /= 256;
	core->arena[address % MEM_SIZE] = value;
}
