/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warcycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:17:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/09 12:12:06 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h" 

static bool		ft_checklives(t_cor *core)
{
	t_process	*proc;
	t_process	*tproc;
	size_t		lives;

	lives = 0;
	proc = core->process;
	while (proc) // not any kill :/
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
			if (core->options->dump && core->total_cycle == core->options->nb_dump)
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
		b_alive = ft_checklives(core);
	}
	 ft_printf("%s Won !\n", core->last_champ_alive );
}
