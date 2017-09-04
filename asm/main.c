/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/09/04 16:50:47 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_name_check(char *str, char **name, char *s_name)
{
	int			i;
	int			j;
	char		*tmp;

	if (!str)
		return (0);
	i = -1;
	while (str[++i] && str[i] == ' ')
		;
	i--;
	j = i + 1;
	while (str[++i] && str[i] != '\"')
	{
		if (((i - j) < ft_strlen(s_name) && str[i] != s_name[i - j])
				|| ((i - j) >= ft_strlen(s_name) && str[i] != ' '))
			return (0);
	}
	//tmp = str + i + 1;
	//i = -1;
	//while (tmp[++i] && tmp[i] != '\"')
	//	;
	if (str[i] == '\0')
		return (0);
	j = i;
	*name = ft_strsub(tmp, 0, i);
	(*name)[i] = '\0';
	return (1);
}

void			ft_free_end(t_asm **as)
{
	if ((*as)->load)
		free((*as)->load);
	if ((*as)->name)
		free((*as)->name);
	if ((*as)->comment)
		free((*as)->comment);
	if ((*as)->enc)
		free((*as)->enc);
}

int				ft_init_struct_asm(t_asm **as)
{
	if (!(*as = (t_asm *)malloc(sizeof(t_asm))))
		return (0);
	if (!((*as)->load = malloc(sizeof(char))))
		return (0);
	(*as)->load[0] = '\0';
	(*as)->name = NULL;
	(*as)->comment = NULL;
	(*as)->len_mem = 0;
	(*as)->enc = NULL;
	(*as)->t_lab_list = NULL;
	(*as)->t_instr_list = NULL;
	return (1);
}

int				main(int ac, char **av)
{
	t_asm		*t_var_asm;
	int			i;

	if (!(ft_init_struct_asm(&t_var_asm)))
		return (1);
	ft_loading(ac, av, 1, &t_var_asm->load);
	if (ft_name_check(t_var_asm->load, &t_var_asm->name, NAME_CMD_STRING) != 0)
	{
		i = -1;
		while (t_var_asm->load[++i] != '\"')
			;
		i++;
		while (t_var_asm->load[++i] != '\"')
			;
		if (t_var_asm->load[i + 1] != '\n')
			return (1);
		i += 2;
		ft_name_check(t_var_asm->load + i, &t_var_asm->comment, COMMENT_CMD_STRING);
	}
	printf("Name : <%s>\nComment : <%s>\nLoad : <%s>\n", t_var_asm->name, t_var_asm->comment, t_var_asm->load);
	ft_free_end(&t_var_asm);
	return (0);
}
