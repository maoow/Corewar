/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_syn_lbl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:17:37 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 16:53:36 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_put_lbl(t_asm *as, int *i, int j, int *k)
{
	int		tok;

	tok = 0;
	if (ft_real_ln_chr(as, i, k) == -1)
		return (-1);
	if (as->lines[*i] && *i > 0)
		ft_while_space(as->lines[*i], k);
	ft_jmp_lbl(as, *i, k, &tok);
	tok = 0;
	ft_run_types(as->lines[*i], k);
	ft_while_space(as->lines[*i], k);
	while (tok < j)
	{
		ft_run_types(as->lines[*i], k);
		ft_while_space(as->lines[*i], k);
		(*k)++;
		ft_while_space(as->lines[*i], k);
		tok++;
	}
	ft_putstr_token_num(*i, *k);
	as->num_syn = ft_watzis(as->lines[*i], *k);
	return (1);
}

int			ft_put_syn_lbl(t_asm *as, int i, int j)
{
	int		k;

	k = 0;
	ft_putstr("No such label ");
	ft_putstr(as->op[i].ag_lbl[j]);
	ft_putstr(" while attempting to dereference");
	if (ft_put_lbl(as, &i, j, &k) <= 0)
		return (-1);
	if (ft_watzis(as->lines[i], k) == 3)
		ft_putstr("DIRECT_LABEL");
	else
		ft_putstr("INDIRECT_LABEL");
	ft_search_syntax(as, i, k);
	return (0);
}
