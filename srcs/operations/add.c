/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:24:58 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/04 14:57:34 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	add(t_cor *core, t_process *proc)
{
	proc->registres[proc->PC + proc->startpos + 4] =
		proc->registres[proc->PC + proc->startpos + 3] +
		proc->registres[proc->PC + proc->startpos + 2];
	return (proc->registres[proc->PC + proc->startpos + 4] != 0);
}
