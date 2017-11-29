/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:49:00 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 16:53:36 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_complete_int_space(int nbr, int nb_esp)
{
	int			nb_dgts;
	int			j;

	ft_putnbr(nbr);
	nb_dgts = 1;
	if (nbr < 0)
		nb_dgts++;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		nb_dgts++;
	}
	j = -1;
	while (++j < nb_esp - nb_dgts)
		ft_putstr(" ");
}

void			ft_complete_str_space(char *str, int nb_esp)
{
	int			i;

	ft_putstr(str);
	i = -1;
	while (++i < nb_esp - ft_strlen(str))
		ft_putstr(" ");
}

void			ft_complete_len_space(int len, int nb_esp)
{
	int			i;

	i = -1;
	while (++i < nb_esp - len)
		ft_putstr(" ");
}

void			ft_put_args(t_asm *as, int i)
{
	int			j;
	int			k;
	int			len;

	j = 0;
	ft_jmp_lbl(as, i, &j, &len);
	ft_run_types(as->lines[i], &j);
	ft_while_space(as->lines[i], &j);
	k = -1;
	while (++k < 3)
	{
		len = j;
		while (as->lines[i][j] && !ft_is_sep(as->lines[i][j]))
			ft_putchar(as->lines[i][j++]);
		if (k < 2)
			ft_complete_len_space(j - len, 18);
		ft_while_space(as->lines[i], &j);
		if (as->lines[i][j] == ',')
			j++;
		ft_while_space(as->lines[i], &j);
	}
}

void			ft_put_num_opc(t_asm *as, int i, int *count)
{
	ft_putstr("                    ");
	ft_complete_int_space(as->op[i].num, 4);
	*count = as->op[i].mem_num + as->strt_mem + 1;
	if (as->op[i].opc)
	{
		(*count)++;
		ft_complete_int_space(as->op[i].opc, 6);
	}
	else
		ft_putstr("      ");
}
