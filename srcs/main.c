/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:52:19 by starrit           #+#    #+#             */
/*   Updated: 2017/11/01 10:50:49 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Permet de recuperer le numero de champion donne en ligne de commande s'il
**	existe en verifiant qu'il est bien negatif
**	Retourne 1 s'il n'existe pas pour gestion ulterieure de l'incrementation
**	de l'index positif
*/

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
				exit(0);
			}
		}
	}
	return (1);
}

/*
**	Check si le champion a bien un code a executer et si celui ci n'est pas
**	trop gros.
*/

static void		check_champ(int **champ)
{
	int		i;
	bool	code_exists;

	i = 0;
	code_exists = false;
	if (champ[0][0] > CHAMP_MAX_SIZE)
	{
		ft_putendl("Champion too big");
		exit(0);
	}
	while (i < champ[0][0])
	{
		if (champ[1][i] != 0)
			code_exists = true;
		i++;
	}
	if (!code_exists)
	{
		ft_putendl("A champion has no code");
		exit(0);
	}
}

/*
**	color_arena : attribution de la couleur dans l'arene.
**		moove_champ = espacement entre chaque champion
**		decal = decalage de chaque champion, commence a zero puis augmente de
**			moove_champ pour chaque incrementation
*/

static size_t	color_arena(t_cor *cor, int ac, char **av, size_t moove_champ)
{
	static size_t		nb_champ = 1;
	static int			**champ = NULL;
	size_t				i;
	static size_t		decal = 0;

	if (is_champ(av[ac], 0, true, 0))
	{
		i = 0;
		champ = parse(cor, av[ac], get_optionnal_id(ac, av));
		check_champ(champ);
		add_process(cor, decal, get_optionnal_id(ac, av));
		while (i + decal < champ[0][0] + decal)
		{
			cor->arena[i + decal] = champ[1][i];
			cor->arena_color[i + decal] = nb_champ + 3;
			i++;
		}
		decal = decal + moove_champ;
		nb_champ++;
		free(champ[0]);
		free(champ[1]);
		free(champ);
		champ = NULL;
	}
	return (nb_champ);
}

/*
**	parse() : recupere le code hexa du champion
**	nb_champ + 3 pour la couleur car les COLOR_PAIR de champ commencent a 4
**	champ[0][0] = size du champion,	champ[1] = int* du code du champion
**
**	while : attribution de la couleur dans l'arene.
**		moove_champ = espacement entre chaque champion
*/

void			launch_parse(t_cor *cor, int ac, char **av, size_t nb_options)
{
	size_t		nb_champ;
	size_t		moove_champ;
	size_t		i;

	moove_champ = 0;
	i = 0;
	if (ac > 1 && ac - 1 - nb_options != 0)
		moove_champ = MEM_SIZE / (ac - 1 - nb_options);
	while (i < (size_t)ac)
	{
		nb_champ = color_arena(cor, i, av, moove_champ);
		i++;
	}
	cor->nb_champs = nb_champ - 1;
}

int				main(int ac, char **av)
{
	t_cor	core;
	size_t	nb_options;

	if (ac < 2)
		write_error(3);
	usage(ac, av);
	ft_init(&core);
	nb_options = get_options(&core, ac, av, 1);
	if (core.options->dump)
		core.options->visu = false;
	launch_parse(&core, ac, av, nb_options);
	intro(core.champs);
	ft_warcycle(&core, true);
	ft_clean(&core);
	endwin();
}
