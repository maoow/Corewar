/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:15:13 by starrit           #+#    #+#             */
/*   Updated: 2017/10/14 14:41:17 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Bool test : sert a savoir si on parse (false) pour modifier la valeur de
**	nb_champ, ou si on teste juste apres le parsing si c'est un champion pour
**	le lancer dans la vm (true) pour ne pas remodifier la valeur de nb_champ
*/

bool			is_champ(char *av, size_t *nb_champ, bool test, int j)
{
	size_t		len_str;
	size_t		len_suffix;
	char const	suffix[] = ".cor";
	size_t		i;

	len_str = ft_strlen(av);
	len_suffix = ft_strlen((char*)suffix);
	i = len_str - len_suffix;
	if (len_str < len_suffix)
		return (false);
	while (i < len_str)
	{
		if (av[i] != suffix[j])
			return (false);
		j++;
		i++;
	}
	if (!test)
		*nb_champ = *nb_champ + 1;
	return (true);
}

static bool	get_option_3(t_cor *cor, char **av, size_t *i, int ac)
{
	if (ft_strcmp(av[*i], "-s") == 0 && ac > *i + 1)
	{
		cor->options->s = true;
		if (ft_atoi(av[*i + 1]) <= 0 || (cor->options->nb_dump =
					ft_atoi(av[*i + 1])) <= 0)
			write_error(3);
		i++;
	}
	else
		return (false);
	return (true);
}
static size_t	get_option_2(t_cor *cor, char **av, size_t i, size_t nb_champ)
{
	if (ft_strcmp(av[i], "-v2") == 0)
		cor->options->v2 = true;
	else if (ft_strcmp(av[i], "-reg") == 0)
		cor->options->reg = true;
	else if (ft_strcmp(av[i], "-v16") == 0)
		cor->options->v16 = true;
	else if (ft_strcmp(av[i], "-v4") == 0)
		cor->options->v4 = true;
	else if (ft_strcmp(av[i], "-fast") == 0)
		cor->options->fast = true;
	else if (ft_strcmp(av[i], "-visu") == 0)
		cor->options->visu = true;
	else if (!is_champ(av[i], &nb_champ, false, 0))
	{
		ft_putstr(av[i]);
		ft_putstr(" : ");
		write_error(3);
	}
	return (nb_champ);
}

/*
**	i = 1;
*/

size_t			get_options(t_cor *cor, int ac, char **av, size_t i)
{
	size_t		nb_champ;

	nb_champ = 0;
	while (i < (size_t)ac)
	{
		if (ft_strcmp(av[i], "-dump") == 0 && ac > i + 1)
		{
			cor->options->dump = true;
			if (ft_atoi(av[i + 1]) <= 0 || (cor->options->nb_dump =
						ft_atoi(av[i + 1])) <= 0)
				write_error(3);
			i++;
		}
		else if (ft_strcmp(av[i], "-n") == 0 && av[i + 1] &&
				ft_atoi(av[i + 1]) != 0)
			i++;
		else if (!get_option_3(cor, av, &i))
			nb_champ = get_option_2(cor, av, i, nb_champ);
		if (nb_champ > MAX_PLAYERS)
			write_error(4);
		i++;
	}
	if (cor->options->dump)
		cor->options->visu = false;
	return (i - nb_champ - 1);
}

void			ft_dump(t_cor *cor)
{
	size_t	i;

	i = 1;
	ft_printf("0x0000 : ");
	while (i <= MEM_SIZE)
	{
		ft_printf("%02x", cor->arena[i - 1]);
		if (i % 64 == 0 && i != MEM_SIZE)
			ft_printf(" \n0x%04x : ", i);
		else
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}
