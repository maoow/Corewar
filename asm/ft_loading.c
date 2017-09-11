/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 10:57:15 by vkim              #+#    #+#             */
/*   Updated: 2017/09/07 11:57:26 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_new_line(t_asm *as, int *nb_l, int i)
{
	char		**save;
	int			k;

	save = NULL;
	if (i > 0)
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
		if (!(as->lines[k] = ft_strsub(as->load, 0, i)))
			return (0);
		as->lines[k + 1] = NULL;
	}
	return (1);
}

int				ft_str_gnl(t_asm *as)
{
	char		*str_save;
	int			i;
	int			nb_l;
	int			count;

	nb_l = 0;
	count = 0;
	while (ft_strlen(as->load) > 0)
	{
		i = -1;
		while ((as->load[++i] && as->load[i] != '\n')
				|| (as->load[i] == '\n' && (count % 2) == 1))
			if (as->load[i] == '\"')
				count++;
		if (!(ft_new_line(as, &nb_l, i)))
			return (0);
		if (as->load[i] == '\n')
			i++;
		if (!(str_save = ft_strsub(as->load, i, ft_strlen(as->load) - i)))
			return (0);
		free(as->load);
		as->load = str_save;
		str_save = NULL;
	}
	return (1);
}

int				ft_loading(int ac, char **av, int index, t_asm *as)
{
	int			fd;
	int			ret;
	char		buff[5];
	char		*buff2;

	if (ac < 2 || index >= ac || (fd = open(av[index], O_RDWR)) == -1)
		return (0);
	while (((ret = read(fd, buff, 4)) > 0))
	{
		buff[ret] = '\0';
		buff2 = buff;
		if (!(as->load = ft_strjoinfree(&as->load, &buff2, FIRST)))
			return (0);
	}
	if (!(ft_str_gnl(as)))
		return (0);
	if (!(ft_del_com(as)))
		return (0);
	if (!(ft_del_space(as)))
		return (0);
	ft_del_empty_lines(as);
	return (1);
}
