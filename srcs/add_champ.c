/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 19:37:16 by starrit           #+#    #+#             */
/*   Updated: 2017/10/11 15:19:12 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		add_champ_color(t_cor *cor)
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

static void		new_id_list(t_cor *cor, t_champ *champ, int id,
		t_opt_number *id_list)
{
	if (!(id_list = (t_opt_number*)malloc(sizeof(*id_list))))
		write_error(2);
	id_list->num = id;
	champ->ID = id;
	id_list->champ = champ->ID;
	id_list->next = NULL;
	cor->id_list = id_list;
}

static void		add_special_champ_id(t_cor *cor, t_champ *champ, int id,
		t_opt_number *id_list)
{
	id_list = cor->id_list;
	if (!id_list)
	{
		new_id_list(cor, champ, id, id_list);
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
	if (!(id_list->next = (t_opt_number*)malloc(sizeof(*id_list))))
		write_error(2);
	id_list->next->num = id;
	champ->ID = id;
	id_list->next->champ = champ->ID;
	id_list->next->next = NULL;
}

static void		fulfill_champ(t_cor *cor, char *name, char *comment, int id)
{
	static int	id_fix = 1;

	if (id == 1)
	{
		cor->champs->ID = id_fix;
		id_fix++;
	}
	else
		add_special_champ_id(cor, cor->champs, id, NULL);
	if (!(cor->champs->name = ft_strdup(name)))
		write_error(2);
	if (!(cor->champs->comment = ft_strdup(comment)))
		write_error(2);
	cor->champs->last_live = 0;
	cor->champs->lives_in_period = 0;
	if (!cor->last_champ_alive)
		cor->last_champ_alive = cor->champs->name;
	add_champ_color(cor);
}

void			add_champ(t_cor *cor, char *name, char *comment, int id)
{
	t_champ		*new;

	if (!cor->champs)
	{
		if (!(cor->champs = (t_champ*)malloc(sizeof(*cor->champs))))
			write_error(2);
		cor->champs->next = NULL;
	}
	else
	{
		if (!(new = (t_champ*)malloc(sizeof(*new))))
			write_error(2);
		new->next = cor->champs;
		cor->champs = new;
	}
	fulfill_champ(cor, name, comment, id);
}
