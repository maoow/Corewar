/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/08/03 17:41:40 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <stdio.h>

//GERER ESPACES
int				ft_name_check(char *str, char **name, char *s_name)
{
	int			i;
	char		*tmp;

	printf("str : <%s>\n", str);
	if (!str)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\"')
	{
		if ((i < ft_strlen(s_name) && str[i] != s_name[i])
				|| (i >= ft_strlen(s_name) && str[i] != ' '))
			return (0);
	}
	tmp = str + i + 1;
	i = -1;
	while (tmp[++i] && tmp[i] != '\"')
		;
	if (tmp[i] == '\0')
		return (0);
	*name = ft_strsub(tmp, 0, i);
	(*name)[i] = '\0';
	return (1);
}

int				main(int ac, char **av)
{
	char		*load;
	char		*name;
	char		*comment;
	int			i;

	(void)ac;
	(void)av;
	//(void)load;
	//(void)name;
	//(void)comment;
	name = NULL;
	comment = NULL;
	if (!(load = malloc(1 * sizeof(char))))
		return (1);
	load[0] = '\0';
	ft_loading(ac, av, 1, &load);
	//printf("load : <%s>\n", load);
	if (ft_name_check(load, &name, ".name") != 0)
	{
		i = -1;
		while (load[++i] != '\"')
			;
		i++;
		while (load[++i] != '\"')
			;
		i += 2;
		ft_name_check(load + i, &comment, ".comment");
		printf("name : <%s>, comment : <%s>\n", name, comment);
	}
	if (load)
		free(load);
	if (name)
		free(name);
	if (comment)
		free(comment);
	//while(1);
	return (0);
}
