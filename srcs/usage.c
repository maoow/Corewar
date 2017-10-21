/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:40:42 by starrit           #+#    #+#             */
/*   Updated: 2017/10/21 15:03:42 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		usage(int ac, char **av)
{
	if (ac == 2 && ft_strcmp(av[1], "--help") == 0)
	{
		ft_printf("Usage: ./corewar [-dump N -n N -s N -v2 -v4 -v16 -reg");
		ft_printf(" -visu -fast -follow N -aff N] ");
		ft_printf("<champion1.cor> <...>\n");
		ft_printf("\t-dunmp N \t: dump memory after N cycles then exits\n");
		ft_printf("\t-n N     \t: set player number\n");
		ft_printf("\t-s N     \t: runs N cycles, dumps memory, ");
		ft_printf("pauses, then repeats\n");
		ft_printf("\t-v2      \t: show cycles\n");
		ft_printf("\t-v4      \t: show operations\n");
		ft_printf("\t-v16     \t: show PC movements (Except for jumps)\n");
		ft_printf("\t-reg     \t: show registers after new operation\n");
		ft_printf("\t-visu    \t: launch ncurse mode\n");
		ft_printf("\t-fast    \t: go faster in ncurse mode\n");
		ft_printf("\t-follow N\t: follow only process N in ncurse mode\n");
		ft_printf("\t-aff N   \t: If -visu, start ncurse mod on N\n");
		exit(0);
	}
}

void		write_error(int nb)
{
	if (nb == 2)
		exit(ft_printf("Malloc error\n"));
	if (nb == 3)
		exit(ft_printf("Input error. See ./corewar --help\n"));
	if (nb == 4)
		exit(ft_printf("Too many players\n"));
}

void		intro(t_champ *champs)
{
	t_champ	*tmp;
	size_t	i;

	i = 1;
	tmp = champs;
	ft_printf("Introducing contestants...\n");
	while (tmp)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i,
				tmp->weight, tmp->name, tmp->comment);
		tmp = tmp->next;
		i++;
	}
}
