/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 10:57:15 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 14:23:30 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_new_line(t_asm *as, int *nb_l, int i, int j)
{
	char		**save;
	int			k;

	save = NULL;
	if (i >= 0)
	{
		(*nb_l)++;
		save = as->lines;
		if (!(as->lines = (char **)malloc((*nb_l + 1) * sizeof(char *))))
			return (0);
		k = -1;
		while (++k < *nb_l - 1)
			as->lines[k] = save[k];
		if (save)
			free(save);
		if (!(as->lines[k] = ft_strsub(as->load, i, j)))
			return (0);
		as->lines[k + 1] = NULL;
	}
	return (1);
}

int				ft_str_gnl(t_asm *as)
{
	int			i;
	int			j;
	int			nb_l;
	int			count;

	nb_l = 0;
	count = 0;
	j = 0;
	i = 0;
	while (as->load[j])
	{
		i = j;
		while ((as->load[j] && as->load[j] != '\n')
				|| (as->load[j] == '\n' && (count % 2) == 1))
		{
			if (as->load[j] == '"')
				count++;
			j++;
		}
		if (!(ft_new_line(as, &nb_l, i, j - i)))
			return (0);
		if (as->load[j] == '\n')
			j++;
	}
	return (1);
}

void			ft_opt_a(t_asm *as, char **av, int *index, int ac)
{
	if (ac > 1 && !ft_strcmp(av[*index], "-a"))
	{
		(*index)++;
		as->opt_a = 1;
	}
}

int				ft_loading(int ac, char **av, int *index, t_asm *as)
{
	int			fd;
	int			ret;
	char		buff[5];
	char		*buff2;

	ft_opt_a(as, av, index, ac);
	fd = -1;
	if (ac < 2 || *index >= ac || (fd = open(av[*index], O_RDWR)) == -1)
		return (ft_err_load(ac, fd, av[*index], av[0]));
	while (((ret = read(fd, buff, 4)) > 0))
	{
		buff[ret] = '\0';
		buff2 = buff;
		if (!(as->load = ft_strjoinfree(&as->load, &buff2, FIRST)))
			return (0);
	}
	return (ft_close_load_fd(as, fd));
}
