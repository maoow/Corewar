/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:20:27 by starrit           #+#    #+#             */
/*   Updated: 2017/08/03 15:39:46 by starrit          ###   ########.fr       */

/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#define C COLOR_PAIR
void parse(char **s);

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
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	return (stdscr);
}

void	print_left(WINDOW *left)
{
	(void)left;
}

#define nb_champ 2
#define DCYCLE_TO_DIE 1500
#define DCYCLE_DELTA 50
#define DNBR_LIVE 20
#define DMAX_CHECKS 10
#define NB_CHAMP 2

/*
**	fonction d'ecriture sous fenetre de droite : menu
*/
void	print_right(WINDOW *right)
{
	char	sP[] = "PAUSED";
	char	sR[] = "RUNNING";
	size_t	cycle_second = 50;
	size_t	total_cycles = 9000;
	size_t	nb_process_alive = 2;
	int CYCLE_TO_DIE = DCYCLE_TO_DIE;
	int CYCLE_DELTA = DCYCLE_DELTA;
	int NBR_LIVE = DNBR_LIVE;
	int MAX_CHECKS = DMAX_CHECKS;
	int	champ = NB_CHAMP;
	int champ_nb1 = 1;
	int champ_nb2 = 2;
	int champ_last_live = 0;
	int champ_current_live = 0;
	char champ_name[] = "champion name";

	mvwprintw(right, 2, 3, "** %s **", sP);
	mvwprintw(right, 4, 3, "Cycles/second limit : %d", cycle_second);
	mvwprintw(right, 7, 3, "Cycles : %d", total_cycles);
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
}

/*
**	creer les bordures et appelles les fonctions d'ecriture
*/
void	manage_box(WINDOW *left, WINDOW *right)
{
	init_color(COLOR_WHITE, 460, 460, 460);
	attron(COLOR_PAIR(1));
	wborder(left, 0 | C(1), 0 | C(2), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1));
	wborder(right, 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1), 0 | C(1));
	attroff(COLOR_PAIR(1));
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	print_right(right);
}

int		main(int ac, char **av)
{
	WINDOW	*left;
	WINDOW	*right;
	int		touche;

	(void)ac;
	parse(av);
	return (0);


	if (init() == NULL)
		return (0);
	while (1)
	{
		left = subwin(stdscr, LINES, COLS - COLS / 5, 0, 0);
		right = subwin(stdscr, LINES, COLS / 5, 0, COLS - COLS / 5);
		manage_box(left, right);
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
	return (0);
}
