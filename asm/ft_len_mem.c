/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:31:22 by vkim              #+#    #+#             */
/*   Updated: 2017/09/11 15:28:26 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

	// Si % 8 == 0 ajustement = 8 pour faire 8 - 8
	len_name = 4 + PROG_NAME_LENGTH + 8 - ((PROG_NAME_LENGTH + 4) % 8)
		= 4 + 128 + 4 = 136 (17 oct / 8.5 lignes)
	len_comment = 3 + COMMENT_LENGHT + 8 - ((COMMENT_LENGTH + 3) % 8)
	= 3 + 2048 + 8 - (2051 % 8) = 2051 + 8 - 3 = 2056 (257 Oct / 128.5 L)
	+ operations
	op : opcode - octet encodage si existe
	(pas long fork OPC 15 size 2,fork OPC 12 size 2, jump OPC 9 size 2, live OPC 1 size 2),
	params * taille label.

	R => encode sur size 1
	IND => encode sur size 2
	DIR => encode sur label_size

int				ft_mem_op(t_asm *as, t_op *ref)
{
	int			i;
	int			count;

	i = 1;
	while (as->lines[++i])
	{
		
	}
}

int				ft_init_lst_op(t_asm *as)
{
	int			i;

	i = 1;
	while (as->lines[++i])
		;
	if (!(as->op_lst = (t_instr *)malloc((i - 1) * sizeof(t_instr))))
		return (0);
	free(as->op_lst[i - 2]);
	as->op_lst[i - 2] = NULL;

}

void			ft_mem_len(t_asm *as, t_op *ref)
{
	int			mod1;
	int			mod2;

	mod1 = (PROG_NAME_LENGTH + 4) % 8;
	if (mod1 == 0)
		mod1 = 8;
	mod2 = (COMMENT_LENGHT+ 3) % 8;
	if (mod2 == 0)
		mod2 = 8;
	as->len_mem = 4 + PROG_NAME_LENGTH + 8 - mod1 + 3 + COMMENT_LENGHT + 8 - mod2;
	ft_init_lst_op(as);
	ft_mem_op(as, ref);

}
