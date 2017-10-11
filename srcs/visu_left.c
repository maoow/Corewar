/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:05:12 by starrit           #+#    #+#             */
/*   Updated: 2017/10/11 16:08:27 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		check_process_to_color(t_process *tmp, size_t col, size_t lign,
		size_t i)
{
	while (tmp)
	{
		if (i == (tmp->PC + tmp->startpos) % MEM_SIZE)
			mvchgat(lign, col, 2, A_NORMAL, tmp->color - 10, NULL);
		tmp = tmp->next;
	}
}

/*
**	fonction d'ecriture sous fenetre de gauche : arena
**
**	while (tmp) : check si c'est un process et si oui le met en surlignance
**	while = check_process_to_color
*/

void			print_left(WINDOW *left, t_cor *cor, size_t col, size_t lign)
{
	size_t		max;
	size_t		i;
	t_process	*tmp;

	i = 0;
	max = sqrt((double)MEM_SIZE);
	while (lign <= max + 1)
	{
		while (col <= max * 3 + 2)
		{
			mvwprintw(left, lign, col, "%02x", cor->arena[i]);
			mvchgat(lign, col, 2, A_NORMAL, cor->arena_color[i], NULL);
			tmp = cor->process;
			check_process_to_color(tmp, col, lign, i);
			check_process_to_color(tmp, col, lign, i);
			i++;
			col = col + 2;
			mvwprintw(left, lign, col, " ");
			col++;
		}
		mvwprintw(left, lign, col, "\n");
		col = 4;
		lign++;
	}
}
