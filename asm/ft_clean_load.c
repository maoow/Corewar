/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:42:42 by vkim              #+#    #+#             */
/*   Updated: 2017/09/11 11:13:39 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_del_com(t_asm *as)
{
	int			i;
	int			j;
	char		*save;

	i = -1;
	while (as->lines[++i])
	{
		j = -1;
		while (as->lines[i][++j])
		{
			if (as->lines[i][j] == '#')
			{
				save = as->lines[i];
				if (!(as->lines[i] = ft_strsub(as->lines[i], 0, j)))
					return (0);
				j = ft_strlen(as->lines[i]);
				free(save);
				j--;
			}
		}
	}
	return (1);
}

int				ft_del_space(t_asm *as)
{
	int			i;
	int			j;
	int			k;
	char		*save;

	i = -1;
	while (as->lines[++i])
	{
		j = -1;
		while (as->lines[i][++j] == ' ')
			;
		k = ft_strlen(as->lines[i]);
		while (--k >= i && as->lines[i][k] == ' ')
			;
		if (as->lines[i][j] == '\0')
			as->lines[i][0] = '\0';
		else if (j != 0 || k != ft_strlen(as->lines[i]) - 1)
		{
			save = as->lines[i];
			if (!(as->lines[i] = ft_strsub(as->lines[i], j, k - j + 1)))
				return (0);
			free(save);
		}
	}
	return (1);
}

void			ft_del_empty_lines(t_asm *as)
{
	int			i;
	int			j;
	char		*save;

	i = -1;
	while (as->lines[++i])
	{
		if (as->lines[i][0] == '\0')
		{
			j = i;
			while (as->lines[++j])
			{
				save = as->lines[j];
				as->lines[j] = as->lines[j - 1];
				as->lines[j - 1] = save;
			}
			free(as->lines[j - 1]);
			as->lines[j - 1] = NULL;
		}
	}
}
