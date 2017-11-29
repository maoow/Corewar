/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ref.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:08:38 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 16:53:36 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_init_struct_ref_5(t_ref *ref)
{
	ref[11].mdf_c = 0;
	ref[12].mdf_c = 1;
	ref[13].mdf_c = 1;
	ref[14].mdf_c = 0;
	ref[15].mdf_c = 1;
	ref[0].lbl_sz = 4;
	ref[1].lbl_sz = 4;
	ref[2].lbl_sz = 0;
	ref[3].lbl_sz = 0;
	ref[4].lbl_sz = 0;
	ref[5].lbl_sz = 4;
	ref[6].lbl_sz = 4;
	ref[7].lbl_sz = 4;
	ref[8].lbl_sz = 2;
	ref[9].lbl_sz = 2;
	ref[10].lbl_sz = 2;
	ref[11].lbl_sz = 2;
	ref[12].lbl_sz = 4;
	ref[13].lbl_sz = 2;
	ref[14].lbl_sz = 2;
	ref[15].lbl_sz = 0;
	ref[16].lbl_sz = 0;
}

void			ft_init_struct_ref_4(t_ref *ref)
{
	ref[14].tvar[0] = T_DIR;
	ref[14].tvar[1] = 0;
	ref[14].tvar[2] = 0;
	ref[15].tvar[0] = T_REG;
	ref[15].tvar[1] = 0;
	ref[15].tvar[2] = 0;
	ref[16].tvar[0] = 0;
	ref[16].tvar[1] = 0;
	ref[16].tvar[2] = 0;
	ref[0].mdf_c = 0;
	ref[1].mdf_c = 1;
	ref[2].mdf_c = 1;
	ref[3].mdf_c = 1;
	ref[4].mdf_c = 1;
	ref[5].mdf_c = 1;
	ref[6].mdf_c = 1;
	ref[7].mdf_c = 1;
	ref[8].mdf_c = 0;
	ref[9].mdf_c = 1;
	ref[10].mdf_c = 1;
	ft_init_struct_ref_5(ref);
}

void			ft_init_struct_ref_3(t_ref *ref)
{
	ref[6].tvar[0] = T_REG | T_IND | T_DIR;
	ref[6].tvar[1] = T_REG | T_IND | T_DIR;
	ref[6].tvar[2] = T_REG;
	ref[7].tvar[0] = T_REG | T_IND | T_DIR;
	ref[7].tvar[1] = T_REG | T_IND | T_DIR;
	ref[7].tvar[2] = T_REG;
	ref[8].tvar[0] = T_DIR;
	ref[8].tvar[1] = 0;
	ref[8].tvar[2] = 0;
	ref[9].tvar[0] = T_REG | T_DIR | T_IND;
	ref[9].tvar[1] = T_DIR | T_REG;
	ref[9].tvar[2] = T_REG;
	ref[10].tvar[0] = T_REG;
	ref[10].tvar[1] = T_REG | T_DIR | T_IND;
	ref[10].tvar[2] = T_DIR | T_REG;
	ref[11].tvar[0] = T_DIR;
	ref[11].tvar[1] = 0;
	ref[11].tvar[2] = 0;
	ref[12].tvar[0] = T_DIR | T_IND;
	ref[12].tvar[1] = T_REG;
	ref[12].tvar[2] = 0;
	ref[13].tvar[0] = T_REG | T_DIR | T_IND;
	ref[13].tvar[1] = T_DIR | T_REG;
	ref[13].tvar[2] = T_REG;
	ft_init_struct_ref_4(ref);
}

void			ft_init_struct_ref_2(t_ref *ref)
{
	ref[7].ac = 3;
	ref[8].ac = 1;
	ref[9].ac = 3;
	ref[10].ac = 3;
	ref[11].ac = 1;
	ref[12].ac = 2;
	ref[13].ac = 3;
	ref[14].ac = 1;
	ref[15].ac = 1;
	ref[16].ac = 0;
	ref[0].tvar[0] = T_DIR;
	ref[1].tvar[0] = T_DIR | T_IND;
	ref[1].tvar[1] = T_REG;
	ref[2].tvar[0] = T_REG;
	ref[2].tvar[1] = T_IND | T_REG;
	ref[3].tvar[0] = T_REG;
	ref[3].tvar[1] = T_REG;
	ref[3].tvar[2] = T_REG;
	ref[4].tvar[0] = T_REG;
	ref[4].tvar[1] = T_REG;
	ref[4].tvar[2] = T_REG;
	ref[5].tvar[0] = T_REG | T_DIR | T_IND;
	ref[5].tvar[1] = T_REG | T_IND | T_DIR;
	ref[5].tvar[2] = T_REG;
	ft_init_struct_ref_3(ref);
}

void			ft_init_struct_ref_1(t_ref *ref)
{
	ref[0].name = "live";
	ref[1].name = "ld";
	ref[2].name = "st";
	ref[3].name = "add";
	ref[4].name = "sub";
	ref[5].name = "and";
	ref[6].name = "or";
	ref[7].name = "xor";
	ref[8].name = "zjmp";
	ref[9].name = "ldi";
	ref[10].name = "sti";
	ref[11].name = "fork";
	ref[12].name = "lld";
	ref[13].name = "lldi";
	ref[14].name = "lfork";
	ref[15].name = "aff";
	ref[16].name = 0;
	ref[0].ac = 1;
	ref[1].ac = 2;
	ref[2].ac = 2;
	ref[3].ac = 3;
	ref[4].ac = 3;
	ref[5].ac = 3;
	ref[6].ac = 3;
	ft_init_struct_ref_2(ref);
}
