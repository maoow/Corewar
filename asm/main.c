/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/09/28 15:35:43 by vkim             ###   ########.fr       */
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
				if ((*as)->op_lst[i].ag_lbl[0])
					free((*as)->op_lst[i].ag_lbl[0]);
				if ((*as)->op_lst[i].ag_lbl[1])
					free((*as)->op_lst[i].ag_lbl[1]);
				if ((*as)->op_lst[i].ag_lbl[2])
					free((*as)->op_lst[i].ag_lbl[2]);
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
	//CHECK NOM ET COMM TOO LONG
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
	ft_init_struct_ref_1((t_op *)t_var_asm->t_op_list);
	/*i = -1;
	while (t_var_asm->t_op_list[++i].ref_name)
	{
		printf("{%s, %d, ", t_var_asm->t_op_list[i].ref_name, t_var_asm->t_op_list[i].nb_args);
		j = -1;
		while (t_var_asm->t_op_list[i].ref_enc[++j] && j < 3)
		{
			printf("%d ", t_var_asm->t_op_list[i].ref_enc[j]);
		}
		printf(", %d, %d}\n", t_var_asm->t_op_list[i].ref_mdf_c, t_var_asm->t_op_list[i].ref_lbl_sz);
	}
	*/
	i = -1;
	while (t_var_asm->lines[++i])
		;
	t_var_asm->op_lst = (t_instr *)malloc(i * sizeof(t_instr));
	k = -1;
	while (++k < i)
	{
		t_var_asm->op_lst[k].num = 0;
		t_var_asm->op_lst[k].opc = 0;
		t_var_asm->op_lst[k].ag_i[0] = 0;
		t_var_asm->op_lst[k].ag_i[1] = 0;
		t_var_asm->op_lst[k].ag_i[2] = 0;
		t_var_asm->op_lst[k].ag_lbl[0] = NULL;
		t_var_asm->op_lst[k].ag_lbl[1] = NULL;
		t_var_asm->op_lst[k].ag_lbl[2] = NULL;
		t_var_asm->op_lst[k].label = NULL;
	}
	i = -1;
	k = -1;
	while (t_var_asm->lines[++i])
		ft_if_label(t_var_asm, &i);
	/*printf("\n\n____\n");
	i = -1;
	while (t_var_asm->lines[++i])
	{
		printf("<%s>\n", t_var_asm->op_lst[i].label);
	}
	*/
	if (!(ft_del_labels(t_var_asm)))
		return (1);
	//if (!(ft_del_space(t_var_asm)))
	//	return (1);
	i = -1;
	printf("\n\n--\n");
	while (t_var_asm->lines[++i])
		printf("<%s>\n", t_var_asm->lines[i]);
	
	if (!(ft_instr_check(t_var_asm)))
		return (1);
	/*printf("\n\n__\n");
	i = -1;
	while (t_var_asm->lines[++i])
	{
		printf("<%d>\n", t_var_asm->op_lst[i].num);
	}*/
	//if (!(ft_check_var(t_var_asm)))
	//	return (1);
	ft_check_var(t_var_asm);
	printf("\n\n----\n");
	i = -1;
	while (t_var_asm->lines[++i])
	{
		printf("<%s>", t_var_asm->op_lst[i].label);
		printf("<%d>", t_var_asm->op_lst[i].num);
		if (t_var_asm->op_lst[i].num > 0)
		{
			printf("<%s>", t_var_asm->t_op_list[t_var_asm->op_lst[i].num - 1].ref_name);
			printf("||");
			printf("<%d>", t_var_asm->op_lst[i].ag_i[0]);
			printf("<%d>", t_var_asm->op_lst[i].ag_i[1]);
			printf("<%d>", t_var_asm->op_lst[i].ag_i[2]);
			printf("||");
			printf("<%s>", t_var_asm->op_lst[i].ag_lbl[0]);
			printf("<%s>", t_var_asm->op_lst[i].ag_lbl[1]);
			printf("<%s>", t_var_asm->op_lst[i].ag_lbl[2]);
		}
		printf("\n");
	}
	ft_free_end(&t_var_asm);
	return (0);
}
