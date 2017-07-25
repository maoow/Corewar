/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:07:38 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/25 13:20:48 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_parse(t_cor *core, int ac, char **av)
{

}

static void		ft_init(t_cor *core)
{
	core->cycle_to_die = CYCLE_TO_DIE;
	core->checks = 0;
	core->last_check = 0;
	core->total_cycle = 0;
}

static void		ft_clean(t_cor *core)
{

}

int				main(int ac, char **av)
{
	t_cor	core;

	ft_init(&core);
	ft_parse(&core, ac, av);
	ft_warcycle(&core);
	ft_clean(&core);
}
