/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/09/05 16:59:18 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_free_end(t_asm **as)
{
	int			i;

	if (*as)
	{
		if ((*as)->lines)
		{
			i = -1;
			while ((*as)->lines[++i])
				free((*as)->lines[i]);
			free((*as)->lines);
		}
		if ((*as)->load)
			free((*as)->load);
		if ((*as)->name)
			free((*as)->name);
		if ((*as)->comment)
			free((*as)->comment);
		if ((*as)->enc)
			free((*as)->enc);
		free(*as);
	}
}

int				ft_init_struct_asm(t_asm **as)
{
	if (!(*as = (t_asm *)malloc(sizeof(t_asm))))
		return (0);
	if (!((*as)->load = malloc(sizeof(char))))
		return (0);
	(*as)->lines = NULL;
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
	ft_loading(ac, av, 1, t_var_asm);
	//printf("Load : <%s>\n", t_var_asm->load);

	i = -1;
	ft_putstr("Lines : \n");
	while (t_var_asm->lines[++i])
	{
		ft_putstr("<");
		ft_putstr(t_var_asm->lines[i]);
		ft_putstr(">\n");
	}

	if (ft_name_check(t_var_asm, &t_var_asm->name, NAME_CMD_STRING) != 0)
	{
		ft_putstr("Name : <");
		ft_putstr(t_var_asm->name);
		ft_putstr(">\n");

		if (!(ft_name_check(t_var_asm, &t_var_asm->comment, COMMENT_CMD_STRING)))
			return (1);

		ft_putstr("Comment : <");
		ft_putstr(t_var_asm->comment);
		ft_putstr(">\n");
	}

	ft_free_end(&t_var_asm);
	return (0);
}
