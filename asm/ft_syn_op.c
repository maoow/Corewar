/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syn_B.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:58:56 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 16:53:38 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					ft_put_bad_op(t_asm *as, int i, int j, char *tmp)
{
	int				k;

	if (ft_real_ln_chr(as, &i, &j) == -1)
		return (-1);
	if (as->lines[i] && i > 0)
		ft_while_space(as->lines[i], &j);
	ft_putstr("Invalid instruction at");
	ft_putstr_token_num(i, j);
	k = -1;
	while (as->lines[++k])
		;
	i = (i > k) ? k : i;
	ft_putstr("INSTRUCTION \"");
	ft_putstr(tmp);
	ft_putstr("\"\n");
	return (0);
}

int					ft_syn_op(t_asm *as, int i)
{
	int				j;
	int				k;
	char			*tmp;

	j = 0;
	if (!ft_jmp_lbl(as, i, &j, &k))
		return (1);
	if ((as->num_syn = ft_watzis(as->lines[i], j)) != 12
		&& as->num_syn != 1)
		return (0);
	if (as->num_syn == 1)
		return (1);
	k = j;
	while (ft_is_lblchr(as->lines[i][k]))
		k++;
	if (!(tmp = ft_strsub(as->lines[i], j, k - j)))
		return (-1);
	if (ft_if_op_ok(as, tmp) == -1)
	{
		j = ft_put_bad_op(as, i, j, tmp);
		ft_strdel(&tmp);
		return (j);
	}
	ft_strdel(&tmp);
	return (1);
}
