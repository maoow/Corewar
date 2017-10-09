/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/10/09 21:12:42 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_free_end(t_asm **as)
{
	int			i;

	if (*as)
	{
		if ((*as)->op)
		{
			i = -1;
			while((*as)->lines[++i])
			{
				if ((*as)->op[i].label)
					free((*as)->op[i].label);
				if ((*as)->op[i].ag_lbl2[0])
					free((*as)->op[i].ag_lbl2[0]);
				if ((*as)->op[i].ag_lbl2[1])
					free((*as)->op[i].ag_lbl2[1]);
				if ((*as)->op[i].ag_lbl2[2])
					free((*as)->op[i].ag_lbl2[2]);
				if ((*as)->op[i].ag_lbl4[0])
					free((*as)->op[i].ag_lbl4[0]);
				if ((*as)->op[i].ag_lbl4[1])
					free((*as)->op[i].ag_lbl4[1]);
				if ((*as)->op[i].ag_lbl4[2])
					free((*as)->op[i].ag_lbl4[2]);
			}
			free((*as)->op);
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
	(*as)->op = NULL;
	return (1);
}

int				main(int ac, char **av)
{
	t_asm		*as;
	int			i;
	int			j;

	if (!(ft_init_struct_asm(&as)))
		return (1);
	if (!(ft_loading(ac, av, 1, as)))
		return (1);
	/*i = -1;
	while (as->lines[++i])
		printf("<%s>\n", as->lines[i]);
	*/
	if (ft_name_check(as, &as->name, NAME_CMD_STRING) != 0)
	{
		if (!(ft_name_check(as, &as->comment,
			COMMENT_CMD_STRING)))
			return (1);
	}
	if (ft_strlen(as->name) > PROG_NAME_LENGTH
		|| ft_strlen(as->comment) > COMMENT_LENGTH)
		return (1);
	as->lines[0][0] = '\0';
	as->lines[1][0] = '\0';
	ft_del_empty_lines(as);
	/*i = -1;
	printf("\n\n");
	while (as->lines[++i])
		printf("<%s>\n", as->lines[i]);
	exit(0);*/
	//ft_init_struct_ref_1((t_op *)op_tab);
	ft_init_struct_ref_1((t_ref *)as->ref);
	/*i = -1;
	while (as->t_op_list[++i].ref_name)
	{
		printf("{%s, %d, ", as->t_op_list[i].ref_name, as->t_op_list[i].nb_args);
		j = -1;
		while (as->t_op_list[i].ref_enc[++j] && j < 3)
		{
			printf("%d ", as->t_op_list[i].ref_enc[j]);
		}
		printf(", %d, %d}\n", as->t_op_list[i].ref_mdf_c, as->t_op_list[i].ref_lbl_sz);
	}
	*/
	i = -1;
	while (as->lines[++i])
		;
	as->op = (t_instr *)malloc(i * sizeof(t_instr));
	j = -1;
	while (++j < i)
	{
		as->op[j].num = 0;
		as->op[j].opc = 0;
		as->op[j].i2_on[0] = 0;
		as->op[j].i2_on[1] = 0;
		as->op[j].i2_on[2] = 0;
		as->op[j].ag_i2[0] = 0;
		as->op[j].ag_i2[1] = 0;
		as->op[j].ag_i2[2] = 0;
		as->op[j].i4_on[0] = 0;
		as->op[j].i4_on[1] = 0;
		as->op[j].i4_on[2] = 0;
		as->op[j].ag_i4[0] = 0;
		as->op[j].ag_i4[1] = 0;
		as->op[j].ag_i4[2] = 0;
		as->op[j].ag_lbl2[0] = 0;
		as->op[j].ag_lbl2[1] = 0;
		as->op[j].ag_lbl2[2] = 0;
		as->op[j].ag_lbl2[0] = NULL;
		as->op[j].ag_lbl2[1] = NULL;
		as->op[j].ag_lbl2[2] = NULL;
		as->op[j].ag_lbl4[0] = 0;
		as->op[j].ag_lbl4[1] = 0;
		as->op[j].ag_lbl4[2] = 0;
		as->op[j].ag_lbl4[0] = NULL;
		as->op[j].ag_lbl4[1] = NULL;
		as->op[j].ag_lbl4[2] = NULL;
		as->op[j].label = NULL;
	}
	i = -1;
	while (as->lines[++i])
		ft_if_label(as, &i);
	/*printf("\n\n____\n");
	i = -1;
	while (as->lines[++i])
	{
		printf("<%s>\n", as->op_lst[i].label);
	}
	*/
	if (!(ft_del_labels(as)))
		return (1);
	if (!(ft_del_space(as)))
		return (1);

	printf("\n\n--\n");
	i = -1;
	while (as->lines[++i])
		printf("<%s>\n", as->lines[i]);
	
	if (!(ft_instr_check(as)))
		return (1);
	if (!(ft_check_var(as)))
		return (1);

	printf("\n\n----\n");
	i = -1;
	while (as->lines[++i])
	{
		printf("<%s> ", as->op[i].label);
		if (as->op[i].num > 0)
		{
			printf("<%d> ", as->op[i].num);
			printf("<%s> ", as->ref[as->op[i].num - 1].name);
			printf("|| ");
			j = -1;
			while (++j < 3)
			{
				if (as->op[i].i2_on[j] == 1)
					printf("<%hu> ", as->op[i].ag_i2[j]);
				if (as->op[i].i4_on[j] == 1)
						printf("<%u> ", as->op[i].ag_i4[j]);
			}
			printf("|| ");
			j = -3;
			while (++j < 3)
			{
				if (as->op[i].lbl2_on[j] == 1)
					printf("<%s> ", as->op[i].ag_lbl2[j]);
				if (as->op[i].lbl4_on[j] == 1)
					printf("<%s> ", as->op[i].ag_lbl4[j]);
			}
		}
		printf("\n");
	}
	if (!(ft_check_lbl(as)))
		return (1);
	ft_mem_len(as);
	printf("\nLEN MEM : %d\n", as->len_mem);
	ft_free_end(&as);
	return (0);
}
