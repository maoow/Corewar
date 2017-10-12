/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/10/12 09:31:07 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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
	(*as)->ac = 0;
	(*as)->n_ln = 0;
	(*as)->n_chr = 0;
	(*as)->strt_mem = 0;
	(*as)->op = NULL;
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
	int			i;
	int			j;
	int			k;
	int			count;

	if (!(ft_init_struct_asm(&as)))
		return (1);
	if (!(ft_loading(ac, av, 1, as)))
		return (1);
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
	ft_init_struct_ref_1((t_ref *)as->ref);
	if (!(ft_malloc_instr(as)))
		return (1);
	i = -1;
	while (as->lines[++i])
		ft_if_label(as, &i);
	if (!(ft_del_labels(as)))
		return (1);
	if (!(ft_del_space(as)))
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
	if (!(ft_instr_check(as)))
		return (1);
	if (!(ft_check_var(as)))
		return (1);
	if (!(ft_check_lbl(as)))
		return (1);
	ft_mem_len(as);

	printf("\n\n----\n");
	count = 0;
	i = -1;
	while (as->lines[++i])
	{
		ft_putstr("<");ft_putstr(as->op[i].label);ft_putstr("> ");
		//printf("<%s> ", as->op[i].label);
		ft_putstr("MEM : <");ft_putnbr(as->op[i].mem_num);ft_putstr("> ");
		//printf("MEM : <%d> ", as->op[i].mem_num);
		if (as->op[i].num > 0)
		{
			printf("<%d> ", as->op[i].num);
			count++;
			if (as->op[i].opc)
				count++;
			printf("<%s> ", as->ref[as->op[i].num - 1].name);
			printf("|| ");
			j = -1;
			while (++j < 3)
			{
				if (as->op[i].i_lbl_sz[0][j] == 2)
				{
					count += 2;
					printf("<%hu> ", as->op[i].ag_i2[j]);
				}
				if (as->op[i].i_lbl_sz[0][j] == 4)
				{
					count += 4;
					printf("<%u> ", as->op[i].ag_i4[j]);
				}
				if (as->op[i].reg[j] > -1)
				{
					count++;
					printf("<%u> ", as->op[i].reg[j]);
				}
				if (as->op[i].ag_lbl[j] != NULL)
				{
					count += as->op[i].i_lbl_sz[1][j];
					ft_putstr("<");ft_putstr(as->op[i].ag_lbl[j]);ft_putstr(">//");
					//printf("<%s>//", as->op[i].ag_lbl[j]);
					if (as->op[i].i_lbl_sz[1][j] == 2)
						printf("<%hu> ", as->op[i].ag_i2[j]);
					if (as->op[i].i_lbl_sz[1][j] == 4)
						printf("<%u> ", as->op[i].ag_i4[j]);
				}
			}
		}
		printf("\n");
	}
	printf("count : %d\n", count);
	printf("\n\n>>>>\n");
	count = 0;
	i = -1;
	while (as->lines[++i])
	{
		if (as->op[i].num > 0)
		{
			printf("%02x ", as->op[i].num);
			count++;
			if (count % 8 == 0)
				printf("  ");
			if (count % 16 == 0)
				printf("\n");
			if (as->op[i].opc > 0)
			{
				printf("%02x ", as->op[i].opc);
				count++;
				if (count % 8 == 0)
					printf("  ");
				if (count % 16 == 0)
					printf("\n");
			}
			j = -1;
			while (++j < 3)
			{
				k = 0;
				if (as->op[i].reg[j] > -1)
					k = 1;
				if (as->op[i].i_lbl_sz[0][j])
					k = as->op[i].i_lbl_sz[0][j];
				if (as->op[i].i_lbl_sz[1][j])
					k = as->op[i].i_lbl_sz[1][j];
				while (--k >= 0)
				{
					if (as->op[i].reg[j] > -1)
						printf("%02hhx ", as->op[i].reg[j]);
					if (as->op[i].i_lbl_sz[0][j] == 2)
						printf("%02hhx ", ((char *)&as->op[i].ag_i2[j])[k]);
					if (as->op[i].i_lbl_sz[0][j] == 4)
						printf("%02hhx ", ((char *)&as->op[i].ag_i4[j])[k]);
					if (as->op[i].i_lbl_sz[1][j] == 2)
						printf("%02hhx ", ((char *)&as->op[i].ag_i2[j])[k]);
					if (as->op[i].i_lbl_sz[1][j] == 4)
						printf("%02hhx ", ((char *)&as->op[i].ag_i4[j])[k]);
					count++;
					if (count % 8 == 0)
						printf("  ");
					if (count % 16 == 0)
						printf("\n");
				}
			}
		}
	}
	printf("\n");
	printf("\nLEN MEM : %d\nLEN REF : 2304\n", as->len_mem);
	ft_free_end(&as);
	return (0);
}
