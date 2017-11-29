/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclemanage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:12:08 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/29 11:05:21 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			get_next_ic(t_cor *core)
{
	t_process	*tmp;
	size_t		min;

	min = core->cycle_to_die - core->tmp_cycle_to_die;
	if (core->options->dump && core->options->nb_dump - core->total_cycle < min)
		min = core->options->nb_dump - core->total_cycle - 1;
	if (core->cycle_to_die <= 1)
		min = 0;
	tmp = core->process;
	while (tmp)
	{
		if (tmp->cycles_before_execute < min)
			min = tmp->cycles_before_execute;
		tmp = tmp->next;
	}
	tmp = core->process;
	while (tmp)
	{
		tmp->cycles_before_execute -= min;
		tmp = tmp->next;
	}
	core->total_cycle += min + 1;
	core->tmp_cycle_to_die += min + 1;
}

void				ft_increase_cycle(t_cor *core)
{
	if (!core->options->fast)
	{
		core->total_cycle++;
		if (core->total_cycle > 0)
			core->tmp_cycle_to_die++;
	}
	else
		get_next_ic(core);
	if (core->options->v2 && core->total_cycle > 0)
		ft_printf("It is now cycle %d\n", core->total_cycle);
}
