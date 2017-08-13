/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:51:54 by starrit           #+#    #+#             */
/*   Updated: 2017/08/13 16:07:03 by starrit          ###   ########.fr       */
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

/*
**	fonction d'ecriture sous fenetre de droite : menu
*/
void			print_right(WINDOW *right, t_cor *cor)
{
	t_champ *tmp = cor->champs;
	char	sP[] = "PAUSED";
	char	sR[] = "RUNNING";
	(void)sR;
	size_t	cycle_second = 50;
	size_t	nb_process_alive = 2;
	int	champ = get_nb_champ(cor->champs);
	int NB_CHAMP = champ;
	int champ_last_live = 0;
	int champ_current_live = 0;

	mvwprintw(right, 2, 3, "** %s **", sP);
	mvwprintw(right, 4, 3, "Cycles/second limit : %d", cycle_second);
	mvwprintw(right, 7, 3, "Cycles : %d", cor->total_cycle);
	mvwprintw(right, 9, 3, "Processes : %d", nb_process_alive);
	while (champ > 0)
	{
		mvwprintw(right, 11 - champ * 4 + NB_CHAMP * 4, 3, "Player -%d : %s", tmp->ID, tmp->name);
		mvwprintw(right, 12 - champ * 4 + NB_CHAMP * 4, 3, "  Last live : \t\t%d", champ_last_live);
		mvwprintw(right, 13 - champ * 4 + NB_CHAMP * 4, 3, "  Lives in current period :  %d", champ_current_live);
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
