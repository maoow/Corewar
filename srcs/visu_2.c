/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:51:54 by starrit           #+#    #+#             */
/*   Updated: 2017/10/03 22:37:57 by cbinet           ###   ########.fr       */
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

/*
**	fonction d'ecriture sous fenetre de droite : menu
*/
void			print_right(WINDOW *right, t_cor *cor)
{
	t_champ *tmp = cor->champs;
	int	champ = get_nb_champ(cor->champs);
	int NB_CHAMP = champ;
	int	i = 1;
	int color_lign;

	mvwprintw(right, 2, 3, "** Pause : ESP       Quit : ESC **");
//	mvwchgat(right, 1, 15, -1, A_NORMAL, 14, NULL);
	mvwprintw(right, 4, 3, "Cycles/second limit : max speed");//, cycle_second);
	mvwprintw(right, 7, 3, "Cycles : %d", cor->total_cycle);
	mvwprintw(right, 9, 3, "Processes : %d", get_nb_process_alive(cor));
	while (champ > 0)
	{
		color_lign = 11 -  i * 4 + NB_CHAMP * 4;
		mvwprintw(right, 11 - i * 4 + NB_CHAMP * 4, 3, "Player %d : %s", tmp->ID, tmp->name);
		mvwchgat(right, color_lign, 1, 2, A_NORMAL, 13 + NB_CHAMP - i + 1, NULL);
		//voir si on peut mettre la couleur correctement
		mvwprintw(right, 12 - i * 4 + NB_CHAMP * 4, 3, "  Last live : \t\t%d", tmp->last_live);
		mvwprintw(right, 13 - i * 4 + NB_CHAMP * 4, 3, "  Lives in current period :  %d", tmp->lives_in_period);
		champ--;
		i++;
		tmp = tmp->next;
	}
	//mvwprintw(right, 11 + NB_CHAMP * 4, 3, "CYCLE_TO_DIE : %d", CYCLE_TO_DIE);
	mvwprintw(right, 11 + NB_CHAMP * 4, 3, "CYCLE_TO_DIE : %d", cor->cycle_to_die);
	mvwprintw(right, 11 + NB_CHAMP * 4 + 2, 3, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(right, 11 + NB_CHAMP * 4 + 4, 3, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(right, 11 + NB_CHAMP * 4 + 6, 3, "MAX_CHECKS : %d", MAX_CHECKS);
	int lign = LINES - 2;
	while (lign > 1)
	{
		mvwchgat(right, lign, 3, COLS / 5 - 4, A_NORMAL, 10, NULL);
		lign--;
	}
}
