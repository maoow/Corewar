/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:56:10 by vkim              #+#    #+#             */
/*   Updated: 2017/11/20 15:15:21 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void				ft_putchar_until(t_asm *as, int i, int j, char c)
{
	ft_putchar(as->lines[i][j++]);
	if (as->lines[i][j] == c)
		ft_putchar(as->lines[i][j]);
	while (as->lines[i] && as->lines[i][j] != c)
	{
		while (as->lines[i] && as->lines[i][j] && as->lines[i][j] != c)
		{
			ft_putchar(as->lines[i][j]);
			j++;
		}
		if (as->lines[i][j] == c)
			ft_putchar(as->lines[i][j]);
		i++;
		j = 0;
	}
}

void				ft_put_lblbchr_while(t_asm *as, int i, int *j, int count)
{
	while (--count >= 0)
		ft_putchar(as->lines[i][(*j)++]);
	(*j)--;
	while (ft_is_lblchr(as->lines[i][++(*j)]))
		ft_putchar(as->lines[i][*j]);
}

void				ft_put_simples(t_asm *as, int i, int j)
{
	if (as->num_syn == 6)
		ft_putstr(",");
	else if (as->num_syn == 7)
		ft_putstr(COMMENT_CMD_STRING);
	else if (as->num_syn == 8)
		ft_putstr(NAME_CMD_STRING);
	else if (as->num_syn == 2)
		ft_putchar_until(as, i, j, '"');
	else if (as->num_syn == 3)
		ft_put_lblbchr_while(as, i, &j, 2);
}

void				ft_search_syntax(t_asm *as, int i, int j)
{
	if (as->num_syn == 1)
		return ;
	ft_putstr(" \"");
	ft_put_simples(as, i, j);
	if (as->num_syn == 4)
	{
		ft_putchar(as->lines[i][j]);
		if (as->lines[i][j + 1] == '-')
			ft_putchar(as->lines[i][++j]);
		while (ft_isdigit(as->lines[i][++j]))
			ft_putchar(as->lines[i][j]);
	}
	else if (as->num_syn == 5)
		ft_put_lblbchr_while(as, i, &j, 1);
	else if (as->num_syn == 9)
	{
		if (as->lines[i][j] == '-')
			ft_putchar(as->lines[i][j++]);
		while (ft_isdigit(as->lines[i][j]))
			ft_putchar(as->lines[i][j++]);
	}
	else if (as->num_syn == 10)
		ft_put_lblbchr_while(as, i, &j, 2);
	else if (as->num_syn == 12)
		ft_put_lblbchr_while(as, i, &j, 0);
	else if (as->num_syn == 11)
	{
		ft_put_lblbchr_while(as, i, &j, 0);
		ft_putchar(as->lines[i][j]);
	}
	ft_putstr("\"\n");
}
