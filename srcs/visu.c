/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:20:27 by starrit           #+#    #+#             */
/*   Updated: 2017/11/29 16:05:06 by starrit          ###   ########.fr       */
/*                                                                            */
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
**				FOREGREOUND		BACKGROUND
**					  |			  |
** COLOR_PAIR	1	white		white	=> bordure
**				2	black		black	=> bordure
**				3	H white		black	=> highlight white
**
** for champ
**				4	green		black		400, 1000, 400
**				5	blue		black		0, 400, 1000
**				6	red			black		1000, 0, 400
**				7	cyan		black		0, 1000, 1000
**				8	yellow		black		1000, 1000, 400
**				9	magenta		black		1000, 400, 1000
*/

/*
**	init_pair 	4 a 9 : couleur champion
**				14 a 19 : couleur processus en cours
**				24 a 29 : couleur ecriture processus
*/

static void		init_my_pairs(void)
{
	init_pair(10, 35, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
	init_pair(9, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(14, 35, COLOR_GREEN);
	init_pair(15, 35, COLOR_BLUE);
	init_pair(16, 35, COLOR_RED);
	init_pair(17, 35, COLOR_CYAN);
	init_pair(18, 35, COLOR_YELLOW);
	init_pair(19, 35, COLOR_MAGENTA);
	init_pair(24, 44, COLOR_BLACK);
	init_pair(25, 45, COLOR_BLACK);
	init_pair(26, 46, COLOR_BLACK);
	init_pair(27, 47, COLOR_BLACK);
	init_pair(28, 48, COLOR_BLACK);
	init_pair(29, 49, COLOR_BLACK);
}

WINDOW			*init(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	if (has_colors() == FALSE)
	{
		endwin();
		ft_printf("Terminal does not support color\n");
		return (NULL);
	}
	start_color();
	init_color(COLOR_WHITE, 460, 460, 460);
	init_color(35, 1000, 1000, 1000);
	init_color(44, 400, 1000, 400);
	init_color(45, 0, 400, 1000);
	init_color(46, 1000, 0, 400);
	init_color(47, 0, 1000, 1000);
	init_color(48, 1000, 1000, 400);
	init_color(49, 1000, 400, 1000);
	init_my_pairs();
	return (stdscr);
}

/*
**	creer les bordures des fenetres et appelle les fonctions d'ecriture
*/

static void		manage_box(WINDOW *left, WINDOW *right, t_cor *cor)
{
	wborder(left, 0 | C(1), 0 | C(2), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1),
			0 | C(1), 0 | C(1));
	wborder(right, 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1),
			0 | C(1), 0 | C(1));
	print_right(right, cor, 1, cor->champs);
	print_left(left, cor, 4, 2);
}

static void		wait_for_start(void)
{
	static bool		start = true;
	int				touche;

	while (start)
	{
		touche = getch();
		if (touche == 27)
			exit(0);
		else if (touche == 32)
			start = false;
	}
}

/*
**	lance le mode et les options ncurse (init() ),
**	creer les fenetres gauche/droite
*/

void			visu(t_cor *cor)
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
	wait_for_start();
	if ((touche = getch()) == 27)
		exit(0);
	else if (touche == 32)
	{
		while ((touche = getch()) != 32)
		{
			if (touche == 27)
				exit(0);
			sleep(1);
		}
	}
}
