/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 19:37:16 by starrit           #+#    #+#             */
/*   Updated: 2017/09/26 15:05:45 by starrit          ###   ########.fr       */
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
	cor->process->registres[0] = (0 - (int)nb_champ);

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

void		add_champ(t_cor *cor, char *name, char *comment, int ID)
{
	t_champ	*new;
	static int	ID_fix = 1;

	if (!cor->champs)
	{
		if (!(cor->champs = (t_champ*)malloc(sizeof(*cor->champs))))//
			write_error(2);
		cor->champs->next = NULL;
		if (ID == - 1)
		{
			cor->champs->ID = ID_fix;
			ID_fix++;
		}
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
		{
			cor->champs->ID = ID_fix;
			ID_fix++;
		}
		else
			cor->champs->ID = ID;//verifier que l'id est negatif et n'existe pas deja
	}
	cor->champs->name = ft_strdup(name);//
	cor->champs->comment = ft_strdup(comment);//
	cor->champs->last_live = 0;
	cor->champs->lives_in_period = 0;
	add_champ_color(cor);
}
