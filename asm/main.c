/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/09/16 16:07:53 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_free_end(t_asm **as)
{
	int			i;

	if (*as)
	{
		if ((*as)->op_lst)
		{
			i = -1;
			while((*as)->lines[++i])
			{
				if ((*as)->op_lst[i].label)
					free((*as)->op_lst[i].label);
			}
			free((*as)->op_lst);
		}
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
	int			k;
	t_op		op_tab[17];

	(void)i;
	(void)j;
	if (!(ft_init_struct_asm(&t_var_asm)))
		return (1);
	if (!(ft_loading(ac, av, 1, t_var_asm)))
		return (1);
	/*i = -1;
	while (t_var_asm->lines[++i])
		printf("<%s>\n", t_var_asm->lines[i]);
	*/
	if (ft_name_check(t_var_asm, &t_var_asm->name, NAME_CMD_STRING) != 0)
	{
		if (!(ft_name_check(t_var_asm, &t_var_asm->comment,
			COMMENT_CMD_STRING)))
			return (1);
	}
	t_var_asm->lines[0][0] = '\0';
	t_var_asm->lines[1][0] = '\0';
	ft_del_empty_lines(t_var_asm);
	/*i = -1;
	printf("\n\n");
	while (t_var_asm->lines[++i])
		printf("<%s>\n", t_var_asm->lines[i]);
	exit(0);*/
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
	i = -1;
	while (t_var_asm->lines[++i])
		;
	t_var_asm->op_lst = (t_instr *)malloc(i * sizeof(t_instr));
	k = -1;
	while (++k < i)
	{
		t_var_asm->op_lst[k].num = 0;
		t_var_asm->op_lst[k].opc = 0;
		t_var_asm->op_lst[k].arg1 = 0;
		t_var_asm->op_lst[k].arg2 = 0;
		t_var_asm->op_lst[k].arg3 = 0;
		t_var_asm->op_lst[k].label = NULL;
	}
	i = -1;
	k = -1;
	while (t_var_asm->lines[++i])
		ft_if_label(t_var_asm, &i);
	printf("\n\n____\n");
	i = -1;
	while (t_var_asm->lines[++i])
	{
		printf("<%s>\n", t_var_asm->op_lst[i].label);
	}
	ft_del_labels(t_var_asm);
	i = -1;
	printf("\n\n--\n");
	while (t_var_asm->lines[++i])
		printf("<%s>\n", t_var_asm->lines[i]);
	
	ft_free_end(&t_var_asm);
	return (0);
}
