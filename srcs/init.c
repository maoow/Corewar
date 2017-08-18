/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 19:37:16 by starrit           #+#    #+#             */
/*   Updated: 2017/08/18 04:43:14 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// je referais l'init en plus propre c'est juste pour limiter la casse en attendant

void		init_struct(t_cor *cor)
{
	if (!cor->process)
	{
		if (!(cor->process = (t_process*)malloc(sizeof(*cor->process))))//
			write_error(2);
		cor->process->next_op = NULL;
		cor->process->PC = 0;
		cor->process->next_jump = 0;
		cor->process->startpos = 0; // (non !)
		cor->process->cycles_before_execute = 0;
		cor->process->live = 0;
		cor->process->next = NULL;
	}
}

//a faire : mettre l'ID recue en param si c'est le cas, sinon bien compter quel nombre mettre
void		add_champ(t_cor *cor, char *name, char *comment, int ID)
{
	t_champ	*new;

	if (!cor->champs)
	{
		if (!(cor->champs = (t_champ*)malloc(sizeof(*cor->champs))))//
			write_error(2);
		cor->champs->next = NULL;
		if (ID == - 1)
			cor->champs->ID = 1;
		else
			cor->champs->ID = ID;
	}
	else
	{
		if (!(new = (t_champ*)malloc(sizeof(*new))))//
			write_error(2);
		new->next = cor->champs;
		cor->champs = new;
		if (ID == - 1)
			cor->champs->ID = cor->champs->next->ID + 1;
		else
			cor->champs->ID = ID;
	}
	cor->champs->name = ft_strdup(name);//
	cor->champs->comment = ft_strdup(comment);//
	cor->champs->alive = false;
}
