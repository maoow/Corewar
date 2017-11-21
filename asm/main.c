/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/11/21 19:04:18 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_print_mem(t_asm *as)
{
	int			i;
	int			count;

	count = 0;
	i = 0;
	while (i < as->len_mem)
	{
		if (i % 16 == 0 && ((int *)as->mem)[(i / 16 * 4) + 0] == 0
		&& ((int *)as->mem)[(i / 16 * 4) + 1] == 0
		&& ((int *)as->mem)[(i / 16 * 4) + 2] == 0
		&& ((int *)as->mem)[(i / 16 * 4) + 3] == 0
		&& (i / 16 * 4) >= 4
		&& ((int *)as->mem)[(i / 16 * 4) - 4] == 0
		&& ((int *)as->mem)[(i / 16 * 4) - 3] == 0
		&& ((int *)as->mem)[(i / 16 * 4) - 2] == 0
		&& ((int *)as->mem)[(i / 16 * 4) - 1] == 0)
		{
			i += 16;
			count += 16;
			printf("*\n");
			while (i < as->len_mem && i % 16 == 0
			&& ((int *)as->mem)[(i / 16 * 4) + 0] == 0
			&& ((int *)as->mem)[(i / 16 * 4) + 1] == 0
			&& ((int *)as->mem)[(i / 16 * 4) + 2] == 0
			&& ((int *)as->mem)[(i / 16 * 4) + 3] == 0)
			{
				i += 16;
				count += 16;
			}
		}
		else
		{
			if (count % 16 == 0)
				printf("%08x  ", count);
			printf("%02hhx ", as->mem[i]);
			i++;
			if (i % 8 == 0)
				printf("  ");
			if (i % 16 == 0)
				printf("\n");
			count++;
		}
	}
	if (i % 16 != 0)
		printf("\n");
	printf("%08x\n", count);
}

void			ft_free_end(t_asm **as)
{
	int			i;
	int			j;

	if (*as)
	{
		if ((*as)->op)
		{
			i = -1;
			while ((*as)->lines[++i])
			{
				if ((*as)->op[i].label)
					free((*as)->op[i].label);
				j = -1;
				while (++j < 3)
					if ((*as)->op[i].ag_lbl[j])
						free((*as)->op[i].ag_lbl[j]);
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
		if ((*as)->mem)
			free((*as)->mem);
		free(*as);
	}
}

void			ft_init_syn(t_asm *as)
{

	as->syn[1] = "ENDLINE\n";
	as->syn[2] = "STRING";
	as->syn[3] = "DIRECT_LABEL";
	as->syn[4] = "DIRECT";
	as->syn[5] = "INDIRECT_LABEL";
	as->syn[6] = "SEPARATOR";
	as->syn[7] = "COMMAND_COMMENT";
	as->syn[8] = "COMMAND_NAME";
	as->syn[9] = "INDIRECT";
	as->syn[10] = "REGISTER";
	as->syn[11] = "LABEL";
	as->syn[12] = "INSTRUCTION";
	as->syn[13] = "END \"(null)\"\n";
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
	(*as)->ac = 0;
	(*as)->n_ln = 0;
	(*as)->n_chr = 0;
	(*as)->strt_mem = 0;
	(*as)->op = NULL;
	(*as)->mem = NULL;
	(*as)->opt_a = 0;
	(*as)->output = NULL;
	return (1);
}

int				ft_malloc_instr(t_asm *as)
{
	int			i;
	int			j;

	i = -1;
	while (as->lines[++i])
		;
	if (!(as->op = (t_instr *)malloc(i * sizeof(t_instr))))
		return (0);
	j = -1;
	while (++j < i)
	{
		as->op[j].mem_num = -1;
		as->op[j].num = 0;
		as->op[j].opc = 0;
		as->op[j].reg[0] = -1;
		as->op[j].reg[1] = -1;
		as->op[j].reg[2] = -1;
		as->op[j].i_lbl_sz[0][0] = 0;
		as->op[j].i_lbl_sz[0][1] = 0;
		as->op[j].i_lbl_sz[0][2] = 0;
		as->op[j].i_lbl_sz[1][0] = 0;
		as->op[j].i_lbl_sz[1][1] = 0;
		as->op[j].i_lbl_sz[1][2] = 0;
		as->op[j].ag_i2[0] = 0;
		as->op[j].ag_i2[1] = 0;
		as->op[j].ag_i2[2] = 0;
		as->op[j].ag_i4[0] = 0;
		as->op[j].ag_i4[1] = 0;
		as->op[j].ag_i4[2] = 0;
		as->op[j].ag_lbl[0] = NULL;
		as->op[j].ag_lbl[1] = NULL;
		as->op[j].ag_lbl[2] = NULL;
		as->op[j].label = NULL;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_asm		*as;
	int			ind;
	int			i;
	int			j;
	int			k;
	int			count;

	(void)count;
	(void)k;
	(void)j;

	ind = 1;
	while (ind < ac)
	{
		if (!(ft_init_struct_asm(&as)))
			return (1);
		ft_init_syn(as);
		if (!(ft_loading(ac, av, &ind, as)))
			return (1);

//	printf("\nLOAD OK\n");

		if (!(ft_lexical_err(as, as->lines)))
			return (1);
//	printf("LEXICAL ALL OK\n");

		if (!(ft_syn_name_comm(as)))
				return (1);
//	printf("SYN NAME COMMENT OK\n");

		if (!(ft_max_len(as)))
			return (1);

		ft_init_struct_ref_1((t_ref *)as->ref);
		if (!(ft_malloc_instr(as)))
			return (1);
/*
	printf("\n\n--\n");
	i = -1;
	while (as->lines[++i])
	{
		ft_putstr("<");ft_putstr(as->lines[i]);ft_putstr(">\n");
		//printf("<%s>\n", as->lines[i]);
	}
*/
		i = -1;
		while (as->lines[++i] && as->lines[i][0] == '\0')
			;
		if (!as->lines[i])
		{
			ft_put_syntax(as, i, 0);
			return (1);
		}
		if (ft_syn_A(as, i) <= 0)
			return (1);
		if (ft_syn_op(as, i) <= 0)
			return (1);
		if (ft_syn_args(as, i) <= 0)
		return (1);
	//ft_putstr("PREM LIGNE OK\n");
		if (as->lines[i])
			i++;
		while (as->lines[i])
		{
			ft_check_kills(as, i);
			i++;
		}

/*
	printf("\n\n-AFTER KILLS-\n");
	i = -1;
	while (as->lines[++i])
	{
		ft_putstr("<");ft_putstr(as->lines[i]);ft_putstr(">\n");
		//printf("<%s>\n", as->lines[i]);
	}
*/

		i = -1;
		while (as->lines[++i])
			ft_if_label(as, &i);

		i = -1;
		while (as->lines[++i])
		{
			if (ft_syn_A(as, i) <= 0)
			return (1);
		}
//	printf("ALL SYN A OK\n");
		i = -1;
		while (as->lines[++i])
		{
			if (ft_syn_op(as, i) <= 0)
			return (1);
		}
//	printf("ALL SYN OP OK\n");
		i = -1;
		while (as->lines[++i])
		{
			if (ft_syn_args(as, i) <= 0)
			return (1);
		}
//	printf("ALL SYN OK\n");

		if (!(ft_del_labels(as)))
			return (1);
		if (!(ft_del_space(as)))
			return (1);
		if (!(ft_instr_check(as)))
			return (1);

//	ft_putstr("INSTR CHECK OK\n");

		if (!(ft_check_var(as)))
			return (1);

//	ft_putstr("VAR CHECK OK\n");


		if (!(ft_check_lbl(as)))
			return (1);

//	ft_putstr("LBL CHECK OK\n");

		ft_mem_len(as);

/*
	printf("\n\n----\n");
	count = 0;
	i = -1;
	while (as->lines[++i])
	{
		ft_putstr("label:<");ft_putstr(as->op[i].label);ft_putstr("> ");
		//printf("<%s> ", as->op[i].label);
		ft_putstr("MEM_num : <");ft_putnbr(as->op[i].mem_num);ft_putstr("> ");
		//printf("MEM : <%d> ", as->op[i].mem_num);
		if (as->op[i].num > 0)
		{
			printf("op_num:<%d> ", as->op[i].num);
			count++;
			if (as->op[i].opc)
				count++;
			printf("nom_op:<%s> ", as->ref[as->op[i].num - 1].name);
			printf("|| ");
			j = -1;
			while (++j < 3)
			{
				if (as->op[i].i_lbl_sz[0][j] == 2)
				{
					count += 2;
					printf("ag_i2:<%hu> ", as->op[i].ag_i2[j]);
				}
				if (as->op[i].i_lbl_sz[0][j] == 4)
				{
					count += 4;
					printf("ag_i4<%u> ", as->op[i].ag_i4[j]);
				}
				if (as->op[i].reg[j] > -1)
				{
					count++;
					printf("reg:<%u> ", as->op[i].reg[j]);
				}
				if (as->op[i].ag_lbl[j] != NULL)
				{
					count += as->op[i].i_lbl_sz[1][j];
					ft_putstr("label_arg:<");ft_putstr(as->op[i].ag_lbl[j]);ft_putstr(">//");
					//printf("<%s>//", as->op[i].ag_lbl[j]);
					if (as->op[i].i_lbl_sz[1][j] == 2)
						printf("ag_i2:<%hu> ", as->op[i].ag_i2[j]);
					if (as->op[i].i_lbl_sz[1][j] == 4)
						printf("ag_i4:<%u> ", as->op[i].ag_i4[j]);
				}
			}
		}
		printf("\n");
	}
	printf("count : %d\n", count);
*/

		ft_write_in_str(as);
//	printf("PRINT MEM : \n");
//		ft_print_mem(as);

	//printf("\nLEN MEM : %d\nLEN REF : 2224\n", as->len_mem);
		if (!(ft_output(as, av, ind)))
			return (1);
		if (as->opt_a == 1)
			ft_option_a(as);
		else
		{
			if (!(ft_write_output(as)))
				return (1);
			ft_print_output(as);
		}
		ft_free_end(&as);
		ind++;
	}
	return (0);
}
