/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 19:37:16 by starrit           #+#    #+#             */
/*   Updated: 2017/08/13 15:50:43 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_struct(t_cor *cor)
{
	if (!cor->process)
	{
		if (!(cor->process = (t_process*)malloc(sizeof(*cor->process))))//
			write_error(2);
		cor->process->next_op = NULL;
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
