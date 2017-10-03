/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:48:08 by vkim              #+#    #+#             */
/*   Updated: 2017/10/03 14:48:31 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		ft_save_numval(t_asm *as, char *txt, int *i, t_instr *sv)
{
	if (as->ref[sv->num - 1].lbl_sz == 2)
	{
		sv->i2_on[as->ac - 1] = 1;
		sv->ag_i2[as->ac - 1] = ft_atoi(txt + *i);
	}
	else
	{
		sv->i4_on[as->ac - 1] = 1;
		sv->ag_i4[as->ac - 1] = ft_atoi(txt + *i);
	}
	if (txt[*i] == '-')
		(*i)++;
	while (txt[*i] >= '0' && txt[*i] <= '9')
		(*i)++;
}

int			ft_dir_ind(t_asm *as, char *txt, int *i, t_instr *sv)
{
	int		nb_chrs;

	if (txt[*i] == ':')
	{
		(*i)++;
		nb_chrs = 0;
		while (ft_strchr(LABEL_CHARS, txt[*i]) && txt[*i])
		{
			(*i)++;
			nb_chrs++;
		}
		if (!(sv->ag_lbl[as->ac - 1] = ft_strsub(txt, *i - nb_chrs, nb_chrs)))
			return (0);
	}
	else if (txt[*i] == '-' || (txt[*i] >= '0' && txt[*i] <= '9'))
		ft_save_numval(as, txt, i, sv);
	else
		return (0);
	return (1);
}
