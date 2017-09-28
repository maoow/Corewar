/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:52:19 by starrit           #+#    #+#             */
/*   Updated: 2017/09/27 16:27:01 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


static void	init_options(t_options *opt)
{
	opt->dump = false;
	opt->nb_dump = 0;
	opt->v4 = false;
	opt->v2 = false;
	opt->visu = false;
}

static void		ft_init(t_cor *core)
{
	size_t		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		core->arena[i] = 0;
		core->arena_color[i] = 3;
		core->arena_update[i] = true;
		i++;
	}
	core->cycle_to_die = CYCLE_TO_DIE;
	core->tmp_cycle_to_die = 0;
	core->checks = 0;
	core->total_cycle = 0;
	core->verbose = false;
	core->champs = NULL;
	core->process = NULL;
	core->options = NULL;
	core->id_list = NULL;
	core->options = (t_options*)malloc(sizeof(*core->options));//
	init_options(core->options);
	core->options->num_champ = NULL;
	core->last_champ_alive = NULL;
}


static int		get_optionnal_id(int ac, char **av)
{
	if (ac > 2)
	{
		if (ft_strcmp("-n", av[ac - 2]) == 0)
		{
			if (ft_atoi(av[ac - 1]) < 0)
				return (ft_atoi(av[ac - 1]));
			else
			{
				ft_putendl("Champions selected ID_number must be < 0");
				exit (0);
			}
		}
	}
	return (1);
}

/*
**	parse() : recupere le code hexa du champion
**	nb_champ + 3 pour la couleur car les COLOR_PAIR de champ commencent a 4
**	champ[0][0] = size du champion,	champ[1] = int* du code du champion
**
**	while : attribution de la couleur dans l'arene.
**		moove_champ = espacement entre chaque champion
**		decal = decalage de chaque champion, commence a zero puis augmente de
**			moove_champ pour chaque incrementation
*/
void			launch_parse(t_cor *cor, int ac, char **av, size_t nb_options)
{
	size_t		nb_champ;
	int			**champ;
	size_t		moove_champ;
	size_t		i;
	size_t		decal = 0;
	size_t		real_champ;

	nb_champ = 1;
	real_champ = 1;
	if (ac > 1 && ac - 1 - nb_options != 0)
		moove_champ = MEM_SIZE /  (ac - 1 - nb_options);
	i = 0;
	ac--;
	while (ac > 0)
	{
		if (is_champ(av[ac], 0, true))
		{
			champ = parse(cor, av[ac], get_optionnal_id(ac, av));
			add_process(cor, decal, real_champ);
			while (i + decal < champ[0][0] + decal)
			{
				cor->arena[i + decal] = champ[1][i];
				cor->arena_color[i + decal] = nb_champ + 3;
				i++;
			}
			i = 0;
			decal = decal + moove_champ;
			real_champ++;
			nb_champ++;
		}
		ac--;
	}
	cor->nb_champs = nb_champ - nb_options;
}

static void		ft_clean(t_cor *core)
{
	(void)core;
	// TO DO
}

int				main(int ac, char **av)
{
	t_cor	core;
	size_t	nb_options;

	if (ac < 2)
		write_error(3);
	ft_init(&core);
	nb_options = get_options(&core, ac, av);
	launch_parse(&core, ac, av, nb_options);
	ft_warcycle(&core);
	ft_clean(&core);
	endwin();
}
