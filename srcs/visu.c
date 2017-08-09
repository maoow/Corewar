/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:20:27 by starrit           #+#    #+#             */
/*   Updated: 2017/08/09 18:26:00 by starrit          ###   ########.fr       */

/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include "corewar.h"
#define C COLOR_PAIR

/*
 **	initscr() initialise le mode plein ecran
 **	move(ligne, colonne) deplace virtuellement le curseur
 **
 ** fonctions suivantes : coordonnes : y,x et non x,y
 **	addch(char) ecrit un caractere la ou est le curseur
 **	addstr(char*) ecrit une chaine de caractere la ou est le curseur
 ** printw() similaire a printf
 ** attron() attroff() : mise en forme (voir man)
 **
 **	refresh() equivalent de mlx_put_img_to_window
 **
 **		 /!\/!\ NE PAS OUBLIER /!\/!\
 **
 **	endwin() free(?) et quitte le mode ncurse
 **		==> oubli = crash shell
 */

/*
** LINES : nombre de ligne
** COLS : nombre de colonnes
** fonction mv'function' : moove+fonction (ex : mvaddch, mvprintw)
*/

/*
** w devant une fonction : on precise la WINDOW* d'application
**
** raw() : pas besoin de presser "enter" quand on appuie sur une touche
** keypad = true : autorise la lecture de touches
**
** getyx(win, y, x) : get y and x in win. dont pass address
** curs_set(0 | 1 | 2) : cursor invisible or normal or very visible
** init_color(couleur deja definie, R, G, B)
*/

/*
** COLOR_PAIR	1	white		white	=> bordure
**				2	black		black	=> bordure
**				3	H white		black	=> highlight white
**
** for champ
**				4	green		black		0, 215, 135
**				5	blue		black		95, 135, 255
**				6	red			black		1000, 0, 0
**				7	cyan		black		175, 255, 255
**				8	yellow		black		215, 255, 135
**				9	magenta		black		255, 135, 255
*/

WINDOW		*init(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Terminal does not support color\n");
		return (NULL);
	}
	start_color();
	init_color(COLOR_WHITE, 460, 460, 460);
	init_color(15, 1000, 1000, 1000);
	init_pair(10, 15, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
	init_pair(9, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(14, COLOR_BLACK, COLOR_GREEN);
	init_pair(15, COLOR_BLACK, COLOR_BLUE);
	init_pair(16, COLOR_BLACK, COLOR_RED);
	init_pair(17, COLOR_BLACK, COLOR_CYAN);
	init_pair(18, COLOR_BLACK, COLOR_YELLOW);
	init_pair(19, COLOR_BLACK, COLOR_MAGENTA);
	return (stdscr);
}

/*
**	fonction d'ecriture sous fenetre de gauche : arena vide
*/

void	print_left(WINDOW *left, t_cor *cor)
{
	size_t	col;
	size_t	lign;
	size_t	max;
	size_t	i;

	col = 4;
	lign = 2;
	i = 0;
	max = sqrt((double)MEM_SIZE);
	while (lign <= max + 1)
	{
		while (col <= max * 3 + 2)
		{
			mvwprintw(left, lign, col, "%02x", cor->arena[i]);
			mvchgat(lign, col, 2, A_NORMAL, cor->arena_color[i], NULL);
			i++;
			col++;
			col++;
			mvwprintw(left, lign, col, " ");
			col++;
		}
		mvwprintw(left, lign, col, "\n");
		col = 4;
		//mvchgat(lign, col, max * 3 - 1, A_NORMAL, 4, NULL);
		lign++;
	}
}

#define NB_CHAMP 2

/*
**	fonction d'ecriture sous fenetre de droite : menu
*/
void	print_right(WINDOW *right, t_cor *cor)
{
	char	sP[] = "PAUSED";
	char	sR[] = "RUNNING";
	size_t	cycle_second = 50;
	size_t	nb_process_alive = 2;
	int	champ = NB_CHAMP;
	int champ_nb1 = 1;
	int champ_nb2 = 2;
	int champ_last_live = 0;
	int champ_current_live = 0;
	char champ_name[] = "champion name";

	mvwprintw(right, 2, 3, "** %s **", sP);
	mvwprintw(right, 4, 3, "Cycles/second limit : %d", cycle_second);
	mvwprintw(right, 7, 3, "Cycles : %d", cor->total_cycle);
	mvwprintw(right, 9, 3, "Processes : %d", nb_process_alive);
	while (champ > 0)
	{
		mvwprintw(right, 11 - champ * 4 + NB_CHAMP * 4, 3, "Player -%d : %s", champ_nb1, champ_name);
champ_nb1 = champ_nb2;
		mvwprintw(right, 12 - champ * 4 + NB_CHAMP * 4, 3, "  Last live : \t\t%d", champ_last_live);
		mvwprintw(right, 13 - champ * 4 + NB_CHAMP * 4, 3, "  Lives in current period :  %d", champ_current_live);
		champ--;
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

/*
**	creer les bordures des fenetres et appelle les fonctions d'ecriture
*/
void	manage_box(WINDOW *left, WINDOW *right, t_cor *cor)
{
	wborder(left, 0 | C(1), 0 | C(2), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1));
	wborder(right, 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1));
	print_right(right, cor);
	print_left(left, cor);
}

/*
** lance le mode et les options ncurse (init() ), creer les fenetres gauche/droite
*/
void		visu(t_cor *cor)
{
	WINDOW	*left;
	WINDOW	*right;
	int		touche;

	if (init() == NULL)
		return ;
	while (1)
	{
		left = subwin(stdscr, LINES, COLS - COLS / 5, 0, 0);
		right = subwin(stdscr, LINES, COLS / 5, 0, COLS - COLS / 5);
		manage_box(left, right, cor);
		wrefresh(left);
		wrefresh(right);
		if ((touche = getch()) == 27)
			break;
		else
			clear();
	}
	endwin();
	delwin(left);
	delwin(right);
}
