/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:20:27 by starrit           #+#    #+#             */
/*   Updated: 2017/08/20 14:03:39 by starrit          ###   ########.fr       */

/* ************************************************************************** */

#include <math.h>
#include "corewar.h"
#include <time.h>
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
**	fonction d'ecriture sous fenetre de gauche : arena
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
	left = subwin(stdscr, LINES, COLS - COLS / 5, 0, 0);
	right = subwin(stdscr, LINES, COLS / 5, 0, COLS - COLS / 5);
	manage_box(left, right, cor);
	wrefresh(left);
	wrefresh(right);
	nodelay(stdscr, true);
	if ((touche = getch()) == 27)
		exit (0);
	else if (touche == 32)
	{
		while ((touche = getch()) != 32)
		{
			if ((touche = getch()) == 27)
				exit (0);
			sleep(1);
		}
	}
	usleep(100000);
	clear();
	endwin();
	delwin(left);
	delwin(right);
}
