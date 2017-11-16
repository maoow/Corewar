/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warcycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:17:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/16 08:08:06 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** 	check_delat() :
**
**  decrease cycle_to_die if executed lives since last check is superior to
**	NBR_LIVE or if the function has been called MAX_CHEKS time with no
**	cycle_to_die decrease
*/

static bool		check_delta(t_cor *core, size_t lives)
{
	if (core->checks >= MAX_CHECKS || lives >= NBR_LIVE)
	{
		core->cycle_to_die -= CYCLE_DELTA;
		if (core->options->v2)
			ft_printf("Cycle to die is now %d\n", core->cycle_to_die);
		if (core->cycle_to_die <= 0)
			core->cycle_to_die = 1;
		core->checks = 0;
	}
	return (core->process);
}

/*
**	ft_checklives() :
**
**	count every lives executed since last check, if none, end the game,
**	else, call check_delta to see if cycle to die need to be decreased
**
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

static void		initprocchamp(t_cor *core)
{
	t_process	*tmp;
	t_champ		*ctmp;
	int			i;

	i = 24;
	tmp = core->process;
	ctmp = core->champs;
	while (tmp && ctmp)
	{
		tmp->registres[0] = ctmp->ID;
		tmp = tmp->next;
		ctmp = ctmp->next;
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

/*
** dispwinner() :
**
** search for the last alive-declared champ and print its informations
*/

void			dispwinner(t_cor *core)
{
	t_champ		*tmp;
	size_t		contestant;

	tmp = core->champs;
	contestant = core->nb_champs;
	while (tmp->ID != core->last_champ_alive)
	{
		tmp = tmp->next;
		contestant--;
	}
	ft_printf("Contestant %d, \"", contestant);
	ft_printf("%s\", has won !\n", tmp->name);
}

/*
** ft_warcycle() :
**
**	browse process/increase cycle/call visu/check lives...
**	until every process died
**
**	b_alive initialise a true;
*/

void			ft_warcycle(t_cor *core, bool b_alive)
{
	initprocchamp(core);
	while (b_alive)
	{
		core->tmp_cycle_to_die = 0;
		while (core->tmp_cycle_to_die < core->cycle_to_die)
		{
			if (((core->options->dump && core->total_cycle > 0) ||
						core->options->s)
					&& core->total_cycle % core->options->nb_dump == 0)
			{
				ft_dump(core);
				if (core->options->dump)
					exit(0);
			}
			if (core->options->visu &&
					core->total_cycle > core->options->aff_visu)
				visu(core);
			ft_browseprocess(core);
			ft_increase_cycle(core);
		}
		b_alive = ft_checklives(core, NULL, NULL, 0);
	}
	ft_browseprocess(core);
	ft_increase_cycle(core);
	dispwinner(core);
}
