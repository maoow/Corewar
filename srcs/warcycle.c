/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warcycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:17:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/09/01 13:53:47 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h" 

static bool		ft_checklives(t_cor *core)
{
	t_process	*proc;
	size_t		lives;

	lives = 0;
	proc = core->process;
	while (proc)
	{
		if (proc->live == 0)
			ft_delprocess(core, &proc);
		else
		{
		lives = proc->live;
		proc->live = 0;
		proc = proc->next;
		}
	}
	if (!lives)
		return (false);
	if (core->checks >= MAX_CHECKS || lives > NBR_LIVE)
	{
		core->cycle_to_die -= CYCLE_DELTA;
		core->checks = 0;
	}
	core->checks++;
	return (true);
}

static void		initproccolor(t_cor *core)
{
	t_process	*tmp;
	int			i;

	i = 14;
	tmp = core->process;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = core->process;
	while (tmp)
	{
		i--;
		tmp->color = i;
		tmp = tmp->next;
	}

}

static void		ft_decrease_arena_update(t_cor *cor)
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

void			ft_warcycle(t_cor *core)
{
	bool	b_alive;

	initproccolor(core);
	b_alive = true;
	while (b_alive)
	{
		while (core->tmp_cycle_to_die < core->cycle_to_die)
		{
			if (core->options->dump && core->total_cycle == core->options->nb_dump)
			{
				ft_dump(core);
				exit(0);
			}
			if (core->options->visu)
				visu(core);
			ft_browseprocess(core);
			core->total_cycle++;
			core->tmp_cycle_to_die++;
			ft_decrease_arena_update(core);
			if (core->options->v2)
			ft_printf("It is now cycle %d\n",core->total_cycle);
		}
		core->tmp_cycle_to_die = 0;
		b_alive = ft_checklives(core);
	}
	// core->last_champ_alive Won !
}
