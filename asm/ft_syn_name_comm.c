/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syn_name_comm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:56:17 by vkim              #+#    #+#             */
/*   Updated: 2017/11/17 12:47:09 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					ft_syn_name_o_comm(t_asm *as, int i)
{
	(void)as;
	(void)i;
	return (1);
}

int					ft_syn_name_comm(t_asm *as)
{
	int				i;
	int				j;
	int				start;
	int				count;

	count = -1;
	i = -1;
	while (++count < 2)
	{
		while (as->lines[++i] && as->lines[i][0] == '\0')
			;
		if (!as->lines[i])
			return (ft_put_syntax(as, i, 0));
		if (ft_watzis(as->lines[i], 0) != 7 && ft_watzis(as->lines[i], 0) != 8)
		{
			printf("ERR2\n");
			return (ft_put_syntax(as, i, 0));
		}
		j = 0;
		if (ft_watzis(as->lines[i], 0) == 7)
			j += ft_strlen(COMMENT_CMD_STRING);
		else if (ft_watzis(as->lines[i], 0) == 8)
			j += ft_strlen(NAME_CMD_STRING);
		ft_while_space(as->lines[i], &j);
		if (ft_watzis(as->lines[i], j) != 2)
		{
			printf("ERR3\n");
			return (ft_put_syntax(as, i, j));
		}
		j++;
		start = j;
		while (as->lines[i] && as->lines[i][j] && as->lines[i][j] != '"')
			j++;
		if (!as->lines[i] || as->lines[i][j] != '"')
		{
			printf("ERR4 I : %d, J : %d\n", i, j);
			return (ft_put_syntax(as, i, j));
		}
		if (ft_watzis(as->lines[i], 0) == 7)
			if (!(as->comment = ft_strsub(as->lines[i], start, j - start)))
				return (0);
		if (ft_watzis(as->lines[i], 0) == 8)
			if (!(as->name = ft_strsub(as->lines[i], start, j - start)))
				return (0);
	}
	return (1);
}
