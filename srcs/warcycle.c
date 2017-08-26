/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warcycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:17:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/26 16:06:27 by starrit          ###   ########.fr       */
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
			//	visu(core);
				ft_dump(core);
			//	ft_printf("%d",core->arena_color[7]);
			}
			if (core->options->visu)
				visu(core);
			ft_browseprocess(core);
			core->total_cycle++;
			core->tmp_cycle_to_die++;
		}
		core->tmp_cycle_to_die = 0;
		b_alive = ft_checklives(core);
	}
	// core->last_champ_alive Won !
}
