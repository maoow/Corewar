/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:37:24 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 12:01:52 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_main_load4(t_asm *as, char **av, int *ind)
{
	if (!(ft_write_in_str(as)))
		return (0);
	if (!(ft_output(as, av, *ind)))
		return (0);
	if (as->opt_a == 1)
		ft_option_a(as);
	else
	{
		if (!(ft_write_output(as)))
			return (0);
		ft_print_output(as);
	}
	return (1);
}

int				ft_main_load3(t_asm *as, int *i)
{
	*i = -1;
	while (as->lines[++(*i)])
		if (ft_if_label(as, *i) <= 0 || ft_syn_a(as, *i) <= 0)
			return (0);
	*i = -1;
	while (as->lines[++(*i)])
		if (ft_syn_op(as, *i) <= 0)
			return (0);
	*i = -1;
	while (as->lines[++(*i)])
		if (ft_syn_args(as, *i) <= 0)
			return (0);
	if (!(ft_del_labels(as)))
		return (0);
	if (!(ft_del_space(as)))
		return (0);
	if (!(ft_instr_check(as)))
		return (0);
	if (!(ft_check_var(as)))
		return (0);
	if (!(ft_check_lbl(as)))
		return (0);
	ft_mem_len(as);
	return (1);
}

int				ft_main_load2(t_asm *as)
{
	int			i;

	i = -1;
	while (as->lines[++i] && as->lines[i][0] == '\0')
		;
	if (!as->lines[i])
		return (ft_put_syntax(as, i, 0));
	if (ft_syn_a(as, i) <= 0)
		return (0);
	if (ft_syn_op(as, i) <= 0)
		return (0);
	if (ft_syn_args(as, i) <= 0)
		return (0);
	if (as->lines[i])
		i++;
	while (as->lines[i])
	{
		ft_check_kills(as, i);
		i++;
	}
	return (ft_main_load3(as, &i));
}

int				ft_main_load(int ac, char **av, t_asm **as, int *ind)
{
	if (!(ft_init_struct_asm(as)))
		return (0);
	ft_init_syn(*as);
	if (!(ft_loading(ac, av, ind, *as)))
		return (0);
	if ((ft_lexical_err(*as, (*as)->lines)) <= 0)
		return (0);
	if ((ft_syn_name_comm(*as)) <= 0)
		return (0);
	if (!(ft_max_len(*as)))
		return (0);
	ft_init_struct_ref_1((*as)->ref);
	if (!(ft_malloc_instr(*as)))
		return (0);
	return (ft_main_load2(*as));
}

int				main(int ac, char **av)
{
	t_asm		*as;
	int			ind;

	ind = 0;
	while (++ind < ac || (ind == 1 && ac == 1))
	{
		if (ft_main_load(ac, av, &as, &ind) > 0)
			ft_main_load4(as, av, &ind);
		ft_free_end(&as);
	}
	return (0);
}
