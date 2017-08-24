/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:15:13 by starrit           #+#    #+#             */
/*   Updated: 2017/08/24 16:26:27 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static bool		is_champ(char *av, size_t *nb_champ)
{
	size_t	len_str;
	size_t	len_suffix;
	char	suffix[] = ".cor";
	size_t	i;
	size_t	j;

	len_str = ft_strlen(av);
	len_suffix = ft_strlen(suffix);
	i = len_str - len_suffix;
	j = 0;
	while (i < len_str)
	{
		if (av[i] != suffix[j])
			return (false);
		i++;
		j++;
	}
	*nb_champ = *nb_champ + 1;
	return (true);
}

void			get_options(t_cor *cor, int ac, char **av)
{
	size_t		i;
	size_t		nb_champ;

	i = 1;
	nb_champ = 0;
	while (i < (size_t)ac)
	{
		if (ft_strcmp(av[i], "-dump") == 0)
		{
			cor->options->dump = true;
			if ((cor->options->nb_dump = ft_atoi(av[i + 1]) == -1))
					write_error(3);
					i++;
		}
		else if (ft_strcmp(av[i], "-v4") == 0)
			cor->options->v4 = true;
		else if (ft_strcmp(av[i], "-visu") == 0)
			cor->options->visu = true;
		else if (!is_champ(av[i], &nb_champ))
			write_error(3);
		if (nb_champ > MAX_PLAYERS)
			write_error(4);
		i++;
	}
	if (cor->options->dump)
		cor->options->visu = false;
}
