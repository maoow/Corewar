/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:51:54 by starrit           #+#    #+#             */
/*   Updated: 2017/10/18 17:04:07 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

static int		get_nb_champ(t_champ *list)
{
	int		total;
	t_champ *tmp;

	total = 0;
	tmp = list;
	while (tmp)
	{
		total++;
		tmp = tmp->next;
	}
	return (total);
}

static int		get_nb_process_alive(t_cor *cor)
{
	t_process	*tmp;
	int			count;

	tmp = cor->process;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static void		print_top(WINDOW *right, t_cor *cor)
{
	mvwprintw(right, 2, 3, "** Pause : ESP       Quit : ESC **");
	mvwprintw(right, 4, 3, "Cycles/second limit : max speed");
	mvwprintw(right, 7, 3, "Cycles : %d", cor->total_cycle);
	mvwprintw(right, 9, 3, "Processes : %d", get_nb_process_alive(cor));
}

static void		print_bot(WINDOW *right, t_cor *cor, int lign, int nb_champ)
{
	mvwprintw(right, 11 + nb_champ * 4, 3, "CYCLE_TO_DIE : %d",
			cor->cycle_to_die);
	mvwprintw(right, 11 + nb_champ * 4 + 2, 3, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(right, 11 + nb_champ * 4 + 4, 3, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(right, 11 + nb_champ * 4 + 6, 3, "MAX_CHECKS : %d", MAX_CHECKS);
	while (lign > 1)
	{
		mvwchgat(right, lign, 3, COLS / 5 - 4, A_NORMAL, 10, NULL);
		lign--;
	}
}

/*
**	fonction d'ecriture sous fenetre de droite : menu
**	i initialise a i = 1;
**	tmp initialise a tmp = cor->champs;
*/

void			print_right(WINDOW *right, t_cor *cor, int i, t_champ *tmp)
{
	int			champ;
	int			nb_champ;
	int			colorlign;
	char		name_tmp[25];

	champ = get_nb_champ(cor->champs);
	nb_champ = champ;
	print_top(right, cor);
	while (champ > 0)
	{
		ft_strncpy(name_tmp, tmp->name, 24);
		name_tmp[24] = '\0';
		colorlign = 11 - i * 4 + nb_champ * 4;
		mvwprintw(right, 11 - i * 4 + nb_champ * 4, 3, "Player %d : %s",
				tmp->ID, name_tmp);
		mvwchgat(right, colorlign, 1, 2, A_NORMAL, 13 + nb_champ - i + 1, NULL);
		mvwprintw(right, 12 - i * 4 + nb_champ * 4, 3, "  Last live : \t\t%d",
				tmp->last_live);
		mvwprintw(right, 13 - i * 4 + nb_champ * 4, 3,
				"  Lives in current period :  %d", tmp->lives_in_period);
		champ--;
		i++;
		tmp = tmp->next;
	}
	print_bot(right, cor, LINES - 2, nb_champ);
}
