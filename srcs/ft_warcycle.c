/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_warcycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:17:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/25 13:25:42 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool		ft_checklives(t_cor *core)
{
	t_process	*proc;
	size_t		lives;

	lives = 0;
	proc = core->process;
	while (proc)
	{
		if (proc->live == 0)
			ft_killprocess(core, proc);
		lives = proc->live;
		proc->live = 0;
		proc = proc->next;
	}
	if (core->checks >= MAX_CHECKS || lives > NBR_LIVE)
	{
		core->cycle_to_die -= CYCLE_DELTA;
		core->checks = 0;
	}
	core->checks++;
	core->last_check = core->total_cycle;

}

void		ft_warcycle(t_cor *core)
{
	bool	b_alive;

	b_alive = false;
	while (!b_alive)
	{
		while (core->total_cycle - last_check < core->cycle_to_die)
		{
			// browse / execute processes op
			core->total_cycle++;
		}
		b_alive = ft_checklives(core);
	}

}
