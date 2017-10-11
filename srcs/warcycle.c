/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warcycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:17:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/11 13:38:24 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static bool		check_delta(t_cor *core, size_t lives)
{
	if (core->checks >= MAX_CHECKS || lives > NBR_LIVE)
	{
		if (core->cycle_to_die <= CYCLE_DELTA)
			return (false);
		core->cycle_to_die -= CYCLE_DELTA;
		if (core->options->v2)
			ft_printf("Cycle to die is now %d\n", core->cycle_to_die);
		core->checks = 0;
	}
	core->checks++;
	return (core->process);
}

/*
**	proc et tproc initialises a NULL;
**	lives initialise a 0;
*/

static bool		ft_checklives(t_cor *core, t_process *proc, t_process *tproc,
		size_t lives)
{
	proc = core->process;
	while (proc)
	{
		if (proc->live == 0)
		{
			tproc = proc->next;
			ft_delprocess(core, &proc);
			proc = tproc;
		}
		else
		{
			lives += proc->live;
			proc->live = 0;
			proc = proc->next;
		}
	}
	if (!lives)
		return (false);
	core->checks++;
	return (check_delta(core, lives));
}

static void		initproccolor(t_cor *core)
{
	t_process	*tmp;
	int			i;

	i = 24;
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
			if (core->options->dump &&
					core->total_cycle == core->options->nb_dump)
			{
				if (!core->options->v4)
					ft_dump(core);
				exit(0);
			}
			if (core->options->visu)
				visu(core);
			ft_browseprocess(core);
			ft_increase_cycle(core);
		}
		core->tmp_cycle_to_die = 0;
		b_alive = ft_checklives(core, NULL, NULL, 0);
	}
	ft_printf("%s Won !\n", core->last_champ_alive);
}
