/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:48:08 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 12:01:17 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		ft_save_numval(t_asm *as, char *txt, int ind, t_instr *sv)
{
	if (as->ref[sv->num - 1].lbl_sz == 2 || ind == 1)
	{
		sv->i_lbl_sz[0][as->ac - 1] = 2;
		sv->ag_i2[as->ac - 1] = ft_atoi(txt + as->n_chr);
	}
	else
	{
		sv->i_lbl_sz[0][as->ac - 1] = 4;
		sv->ag_i4[as->ac - 1] = ft_atoi(txt + as->n_chr);
	}
	if (txt[as->n_chr] == '-')
		(as->n_chr)++;
	while (txt[as->n_chr] >= '0' && txt[as->n_chr] <= '9')
		(as->n_chr)++;
}

int			ft_save_strval(t_asm *as, char *txt, int ind, t_instr *sv)
{
	int		nb;

	nb = 0;
	while (ft_strchr(LABEL_CHARS, txt[as->n_chr + nb]) && txt[as->n_chr + nb])
		nb++;
	as->n_chr += nb;
	if (as->ref[sv->num - 1].lbl_sz == 2 || ind == 1)
	{
		sv->i_lbl_sz[1][as->ac - 1] = 2;
		if (!(sv->ag_lbl[as->ac - 1] = ft_strsub(txt, as->n_chr - nb, nb)))
			return (0);
	}
	else
	{
		sv->i_lbl_sz[1][as->ac - 1] = 4;
		if (!(sv->ag_lbl[as->ac - 1] = ft_strsub(txt, as->n_chr - nb, nb)))
			return (0);
	}
	return (1);
}

int			ft_dir_ind(t_asm *as, char *txt, int *i, t_instr *sv)
{
	int		ind;

	ind = 1;
	if (txt[*i] == '%')
	{
		if (as->ref[sv->num - 1].mdf_c)
			sv->opc |= (DIR_CODE << (6 - (as->ac - 1) * 2));
		(*i)++;
		ind = 0;
	}
	else if (as->ref[sv->num - 1].mdf_c)
		sv->opc |= (IND_CODE << (6 - (as->ac - 1) * 2));
	if (txt[*i] == ':')
	{
		(*i)++;
		if (!(ft_save_strval(as, txt, ind, sv)))
			return (0);
	}
	else if (txt[*i] == '-' || (txt[*i] >= '0' && txt[*i] <= '9'))
		ft_save_numval(as, txt, ind, sv);
	else
		return (0);
	return (1);
}
