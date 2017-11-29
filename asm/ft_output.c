/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:38:06 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 16:53:36 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					ft_write_output(t_asm *as)
{
	int				fd;
	int				ret;

	fd = -1;
	ret = -1;
	if ((fd = open(as->output, O_CREAT | O_WRONLY | O_TRUNC, 00600)) == -1)
		return (0);
	if ((ret = write(fd, as->mem, as->len_mem)) == -1)
		return (0);
	close(fd);
	return (1);
}

void				ft_print_output(t_asm *as)
{
	ft_putstr("Writing ouput program to ");
	ft_putstr(as->output);
	ft_putstr("\n");
}

int					ft_output(t_asm *as, char **av, int i)
{
	int				len;
	int				j;

	len = ft_strlen(av[i]) + 3;
	if (!(as->output = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	as->output[len] = '\0';
	j = -1;
	while (++j < len)
	{
		if (j < ft_strlen(av[i]))
			as->output[j] = av[i][j];
		else
			as->output[j] = '\0';
	}
	j -= 3;
	if (j > 2 && av[i][j - 1] == 's' && av[i][j - 2] == '.')
		j -= 2;
	as->output[j++] = '.';
	as->output[j++] = 'c';
	as->output[j++] = 'o';
	as->output[j++] = 'r';
	as->output[j] = '\0';
	return (1);
}
