/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/07/27 17:27:32 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <stdio.h>

//GERER ESPACES
int				ft_name_comment_check(char *str, char **name)
{
	int			i;
	char		s_name[] = ".name\"";
	//char		s_comment[] = ".comment\"";
	char		*tmp;
	char		**tmp2;

	if (!str)
		return (0);
	if (!(tmp = malloc(sizeof(char))))
			return (0);
	if (!(tmp2 = malloc(sizeof(char *))))
	{
		free(tmp);
		return (0);
	}
	i = -1;
	while (str[++i] && i < 6)
		if (str[i] != s_name[i])
		{
			printf("str : <%s>\nname : <%s>\n", str, s_name);
			free(tmp);
			free(tmp2);
			return (0);
		}
	*tmp2 = str + i;
	*name = ft_strjoinfree(name, tmp2, FIRST);
	i = -1;
	while ((*name)[++i] && (*name)[i] != '\"')
		;
	if ((*name)[i] == '\0')
	{
		free(tmp2);
		return (0);
	}
	(*name)[i] = '\0';
	//*name = ft_strjoinfree(&tmp, name, ALL);
	//free(tmp2);
	//free(tmp);
	return (1);
}

int				main(int ac, char **av)
{
	char		*load;
	char		*name;
	char		*comment;

	(void)ac;
	(void)av;
	(void)load;
	(void)name;
	(void)comment;
	if (!(load = malloc(2 * sizeof(char))) || !(name = malloc(sizeof(char)))
		|| !(comment = malloc(sizeof(char))))
		return (1);
	load[0] = '\0';
	name[0] = '\0';
	comment[0] = '\0';
	ft_loading(ac, av, 1, &load);
	//printf("load : <%s>\n", load);
	ft_name_comment_check(load, &name);
	//printf("name : <%s>\n", name);
	free(load);
	free(name);
	free(comment);
	return (0);
}
