/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:11:26 by starrit           #+#    #+#             */
/*   Updated: 2017/10/11 15:18:22 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		add_process(t_cor *cor, size_t startpos, size_t nb_champ)
{
	t_process	*new;

	if (!cor->process)
	{
		if (!(cor->process = (t_process*)malloc(sizeof(*cor->process))))
			write_error(2);
		cor->process->next = NULL;
		cor->process->ID = 1;
	}
	else
	{
		if (!(new = (t_process*)malloc(sizeof(*new))))
			write_error(2);
		new->ID = cor->process->ID + 1;
		new->next = cor->process;
		cor->process = new;
	}
	cor->process->next_op = NULL;
	cor->process->PC = 0;
	cor->process->next_jump = 0;
	cor->process->startpos = startpos;
	cor->process->cycles_before_execute = 0;
	cor->process->live = 0;
	cor->process->buffc = 0;
	cor->process->registres[0] = (0 - (int)nb_champ);
}
