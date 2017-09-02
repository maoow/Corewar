/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:51:54 by starrit           #+#    #+#             */
/*   Updated: 2017/09/02 15:38:54 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

static int		get_nb_champ(t_champ *list)
{
	int		total;

	total = 0;
	while (list)
	{
		total++;
		list = list->next;
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

/*
**	fonction d'ecriture sous fenetre de droite : menu
*/
void			print_right(WINDOW *right, t_cor *cor)
{
	t_champ *tmp = cor->champs;
//	size_t	cycle_second = 50;
	int	champ = get_nb_champ(cor->champs);
	int NB_CHAMP = champ;

	mvwprintw(right, 2, 3, "** Pause : ESP       Quit : ESC **");
	mvwprintw(right, 4, 3, "Cycles/second limit : max speed");//, cycle_second);
	mvwprintw(right, 7, 3, "Cycles : %d", cor->total_cycle);
	mvwprintw(right, 9, 3, "Processes : %d", get_nb_process_alive(cor));
	while (champ > 0)
	{
		mvwprintw(right, 11 - champ * 4 + NB_CHAMP * 4, 3, "Player %d : %s", tmp->ID, tmp->name);
		mvwprintw(right, 12 - champ * 4 + NB_CHAMP * 4, 3, "  Last live : \t\t%d", tmp->last_live);
		mvwprintw(right, 13 - champ * 4 + NB_CHAMP * 4, 3, "  Lives in current period :  %d", tmp->lives_in_period);
		champ--;
		tmp = tmp->next;
	}
	mvwprintw(right, 11 + NB_CHAMP * 4, 3, "CYCLE_TO_DIE : %d", CYCLE_TO_DIE);
	mvwprintw(right, 11 + NB_CHAMP * 4 + 2, 3, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(right, 11 + NB_CHAMP * 4 + 4, 3, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(right,11 + NB_CHAMP * 4 + 6, 3, "MAX_CHECKS : %d", MAX_CHECKS);
	int lign = LINES - 2;
	while (lign > 1)
	{
		mvwchgat(right, lign, 3, COLS / 5 - 4, A_NORMAL, 10, NULL);
		lign--;
	}
}
