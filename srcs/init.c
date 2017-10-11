/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:44:48 by starrit           #+#    #+#             */
/*   Updated: 2017/10/11 13:05:24 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		init_options(t_options *opt)
{
	opt->dump = false;
	opt->nb_dump = 0;
	opt->v4 = false;
	opt->v16 = false;
	opt->v2 = false;
	opt->visu = false;
	opt->fast = false;
	opt->reg = false;
}

void			ft_init(t_cor *core)
{
	size_t		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		core->arena[i] = 0;
		core->arena_color[i] = 3;
		core->arena_update[i] = true;
		i++;
	}
	core->cycle_to_die = CYCLE_TO_DIE;
	core->tmp_cycle_to_die = 0;
	core->checks = 0;
	core->total_cycle = -1;
	core->verbose = false;
	core->champs = NULL;
	core->process = NULL;
	core->options = NULL;
	core->id_list = NULL;
	if (!(core->options = (t_options*)malloc(sizeof(*core->options))))
		write_error(2);
	init_options(core->options);
	core->options->num_champ = NULL;
	core->last_champ_alive = NULL;
}
