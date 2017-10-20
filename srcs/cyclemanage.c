/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyclemanage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:12:08 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/20 14:52:14 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			ft_decrease_arena_update(t_cor *cor)
{
	size_t		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (cor->arena_update[i] > 0)
			cor->arena_update[i]--;
		i++;
	}
}

static void			get_next_ic(t_cor *core)
{
	t_process	*tmp;
	size_t		min;

	min = core->cycle_to_die - core->tmp_cycle_to_die;
	if (core->options->dump && core->options->nb_dump - core->total_cycle < min)
		min = core->options->nb_dump - core->total_cycle - 1;
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
	ft_decrease_arena_update(core);
	if (core->options->v2 && core->total_cycle > 0)
		ft_printf("It is now cycle %d\n", core->total_cycle);
}
