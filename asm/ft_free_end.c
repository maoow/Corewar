/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:20:58 by vkim              #+#    #+#             */
/*   Updated: 2017/11/22 16:43:50 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_free_end2(t_asm **as)
{
	int			i;

	if ((*as)->lines)
	{
		i = -1;
		while ((*as)->lines[++i])
			free((*as)->lines[i]);
		free((*as)->lines);
	}
	if ((*as)->load)
		free((*as)->load);
	if ((*as)->name)
		free((*as)->name);
	if ((*as)->comment)
		free((*as)->comment);
	if ((*as)->mem)
		free((*as)->mem);
	if ((*as)->output)
		free((*as)->output);
	free(*as);
}

void			ft_free_end(t_asm **as)
{
	int			i;
	int			j;

	if (*as)
	{
		if ((*as)->op)
		{
			i = -1;
			while ((*as)->lines[++i])
			{
				if ((*as)->op[i].label)
					free((*as)->op[i].label);
				j = -1;
				while (++j < 3)
					if ((*as)->op[i].ag_lbl[j])
						free((*as)->op[i].ag_lbl[j]);
			}
			free((*as)->op);
		}
		ft_free_end2(as);
	}
}
