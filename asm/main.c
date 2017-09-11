/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/09/11 12:52:02 by vkim             ###   ########.fr       */
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
	(*as)->op_lst = NULL;
	return (1);
}

int				main(int ac, char **av)
{
	t_asm		*t_var_asm;
	int			i;
	int			j;
	t_op		op_tab[17];

	(void)i;
	(void)j;
	if (!(ft_init_struct_asm(&t_var_asm)))
		return (1);
	if (!(ft_loading(ac, av, 1, t_var_asm)))
		return (1);
	i = -1;
	while (t_var_asm->lines[++i])
		printf("<%s>\n", t_var_asm->lines[i]);
	if (ft_name_check(t_var_asm, &t_var_asm->name, NAME_CMD_STRING) != 0)
	{
		if (!(ft_name_check(t_var_asm, &t_var_asm->comment,
			COMMENT_CMD_STRING)))
			return (1);
	}
	ft_init_struct_ref_1((t_op *)op_tab);
	i = -1;
	/*while (op_tab[++i].ref_name)
	{
		printf("{%s, %d, ", op_tab[i].ref_name, op_tab[i].nb_args);
		j = -1;
		while (op_tab[i].ref_enc[++j] && j < 3)
		{
			printf("%d ", op_tab[i].ref_enc[j]);
		}
		printf(", %d, %d}\n", op_tab[i].ref_mdf_c, op_tab[i].ref_lbl_sz);
	}*/
	ft_free_end(&t_var_asm);
	return (0);
}
