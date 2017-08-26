/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:15:13 by starrit           #+#    #+#             */
/*   Updated: 2017/08/26 15:55:03 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Bool test : sert a savoir si on parse (false) pour modifier la valeur de
**	nb_champ, ou si on teste juste apres le parsing si c'est un champion pour
**	le lancer dans la vm (true) pour ne pas remodifier la valeur de nb_champ
*/

bool			is_champ(char *av, size_t *nb_champ, bool test)
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
	if (len_str < len_suffix)
		return (false);
	while (i < len_str)
	{
		if (av[i] != suffix[j])
			return (false);
		i++;
		j++;
	}
	if (!test)
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
		else if (!is_champ(av[i], &nb_champ, false))
			write_error(3);
		if (nb_champ > MAX_PLAYERS)
			write_error(4);
		i++;
	}
	if (cor->options->dump)
		cor->options->visu = false;
}

void			ft_dump(t_cor *cor)
{
	size_t	i;

	i = 1;
	while (i <= MEM_SIZE)
	{
		ft_printf("%02x", cor->arena[i - 1]);
		if (i % 64 == 0)
			ft_printf("\n");
		else
			ft_printf(" ");
		i++;
	}

}
