/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:07:38 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/25 14:38:04 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_parse(t_cor *core, int ac, char **av)
{
	// TO DO
}

static void		ft_init(t_cor *core)
{
	core->cycle_to_die = CYCLE_TO_DIE;
	core->tmp_cycle_to_die = 0;
	core->checks = 0;
	core->total_cycle = 0;
	core->champs = NULL;
	core->process = NULL;
	core->last_champ_alive = NULL;
}

static void		ft_clean(t_cor *core)
{
	// TO DO
}

int				main(int ac, char **av)
{
	t_cor	core;

	ft_init(&core);
	ft_parse(&core, ac, av);
	ft_warcycle(&core);
	ft_clean(&core);
}
