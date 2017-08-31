/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:10:18 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/31 14:59:09 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	getram(t_cor *core, size_t address)
{
	int	value;

	value = core->arena[(address) % MEM_SIZE];
	value *= 256;
	value += core->arena[(address + 1) % MEM_SIZE];
	value *= 256;
	value += core->arena[(address + 2) % MEM_SIZE];
	value *= 256;
	value += core->arena[(address + 3) % MEM_SIZE];
	return (value);
}
void		setram(t_cor *core, size_t address, size_t value, int color)
{
	value %= 4294967296;
	core->arena[(address + 3) % MEM_SIZE] = value % 256;
	core->arena_color[(address + 3) % MEM_SIZE] = color;
	core->arena_update[(address + 3) % MEM_SIZE] = true;
	value /= 256;
	core->arena[(address + 2) % MEM_SIZE] = value % 256;
	core->arena_color[(address + 2) % MEM_SIZE] = color;
	core->arena_update[(address + 2) % MEM_SIZE] = true;
	value /= 256;
	core->arena[(address + 1) % MEM_SIZE] = value % 256;
	core->arena_color[(address + 1) % MEM_SIZE] = color;
	core->arena_update[(address + 1) % MEM_SIZE] = true;
	value /= 256;
	core->arena[address % MEM_SIZE] = value;
	core->arena_update[address % MEM_SIZE] = true;
	core->arena_color[address % MEM_SIZE] = color;
}
