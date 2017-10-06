/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champ_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 19:37:16 by starrit           #+#    #+#             */
/*   Updated: 2017/10/06 13:54:57 by cbinet           ###   ########.fr       */
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

static void	add_special_champ_id(t_cor *cor, t_champ *champ, int id)
{
	t_opt_number	*id_list;

	id_list = cor->id_list;
	if (!id_list)
	{
		id_list = (t_opt_number*)malloc(sizeof(*id_list));//
		id_list->num = id;
		champ->ID = id;
		id_list->champ = champ->ID;
		id_list->next = NULL;
		cor->id_list = id_list;
		return ;
	}
	while (id_list)
	{
		if (id_list->num == id)
		{
			ft_putendl("Champion ID_number already used");
			exit(0);
		}
		if (id_list->next)
			id_list = id_list->next;
		else
			break ;
	}
	id_list->next = (t_opt_number*)malloc(sizeof(*id_list));//
	id_list->next->num = id;
	champ->ID = id;
	id_list->next->champ = champ->ID;
	id_list->next->next = NULL;
}

void		add_champ(t_cor *cor, char *name, char *comment, int id)
{
	t_champ		*new;
	static int	id_fix = 1;

	if (!cor->champs)
	{
		if (!(cor->champs = (t_champ*)malloc(sizeof(*cor->champs))))//
			write_error(2);
		cor->champs->next = NULL;
		if (id == 1)
		{
			cor->champs->ID = id_fix;
			id_fix++;
		}
		else
			add_special_champ_id(cor, cor->champs, id);
	}
	else
	{
		if (!(new = (t_champ*)malloc(sizeof(*new))))//
			write_error(2);
		new->next = cor->champs;
		cor->champs = new;
		if (id == 1)
		{
			cor->champs->ID = id_fix;
			id_fix++;
		}
		else
			add_special_champ_id(cor, cor->champs, id);
	}
	cor->champs->name = ft_strdup(name);//
	cor->champs->comment = ft_strdup(comment);//
	cor->champs->last_live = 0;
	cor->champs->lives_in_period = 0;
	if (!cor->last_champ_alive)
		cor->last_champ_alive = cor->champs->name;
	ft_printf("%s\n", name);
	add_champ_color(cor);
}
