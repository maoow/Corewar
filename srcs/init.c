/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 19:37:16 by starrit           #+#    #+#             */
/*   Updated: 2017/09/01 16:07:19 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		add_process(t_cor *cor, size_t startpos, size_t nb_champ)
{
	t_process	*new;

	if (!cor->process)
	{
		if (!(cor->process = (t_process*)malloc(sizeof(*cor->process))))//
			write_error(2);
		cor->process->next = NULL;
		cor->process->ID = 1;
	}
	else
	{
		if (!(new = (t_process*)malloc(sizeof(*new))))//
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
	cor->process->registres[0] = nb_champ;

}

static void	add_champ_color(t_cor *cor)
{
	size_t		nb_champ;
	t_champ		*tmp;

	nb_champ = 1;
	tmp = cor->champs;
	while (tmp->next)
	{
		tmp = tmp->next;
		nb_champ++;
	}
	cor->champs->color = nb_champ + 3;
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
	add_champ_color(cor);
}
