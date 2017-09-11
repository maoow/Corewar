/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ref.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:08:38 by vkim              #+#    #+#             */
/*   Updated: 2017/09/11 10:27:47 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_init_struct_ref_5(t_op *op_tab)
{
	op_tab[11].ref_mdf_c = 0;
	op_tab[12].ref_mdf_c = 1;
	op_tab[13].ref_mdf_c = 1;
	op_tab[14].ref_mdf_c = 0;
	op_tab[15].ref_mdf_c = 1;
	op_tab[0].ref_lbl_sz = 4;
	op_tab[1].ref_lbl_sz = 4;
	op_tab[2].ref_lbl_sz = 0;
	op_tab[3].ref_lbl_sz = 0;
	op_tab[4].ref_lbl_sz = 0;
	op_tab[5].ref_lbl_sz = 4;
	op_tab[6].ref_lbl_sz = 4;
	op_tab[7].ref_lbl_sz = 4;
	op_tab[8].ref_lbl_sz = 2;
	op_tab[9].ref_lbl_sz = 2;
	op_tab[10].ref_lbl_sz = 2;
	op_tab[11].ref_lbl_sz = 2;
	op_tab[12].ref_lbl_sz = 4;
	op_tab[13].ref_lbl_sz = 2;
	op_tab[14].ref_lbl_sz = 2;
	op_tab[15].ref_lbl_sz = 0;
	op_tab[16].ref_lbl_sz = 0;
}

void			ft_init_struct_ref_4(t_op *op_tab)
{
	op_tab[14].ref_enc[0] = T_DIR;
	op_tab[14].ref_enc[1] = 0;
	op_tab[14].ref_enc[2] = 0;
	op_tab[15].ref_enc[0] = T_REG;
	op_tab[15].ref_enc[1] = 0;
	op_tab[15].ref_enc[2] = 0;
	op_tab[16].ref_enc[0] = 0;
	op_tab[16].ref_enc[1] = 0;
	op_tab[16].ref_enc[2] = 0;
	op_tab[0].ref_mdf_c = 0;
	op_tab[1].ref_mdf_c = 1;
	op_tab[2].ref_mdf_c = 1;
	op_tab[3].ref_mdf_c = 1;
	op_tab[4].ref_mdf_c = 1;
	op_tab[5].ref_mdf_c = 1;
	op_tab[6].ref_mdf_c = 1;
	op_tab[7].ref_mdf_c = 1;
	op_tab[8].ref_mdf_c = 0;
	op_tab[9].ref_mdf_c = 1;
	op_tab[10].ref_mdf_c = 1;
	ft_init_struct_ref_5(op_tab);
}

void			ft_init_struct_ref_3(t_op *op_tab)
{
	op_tab[6].ref_enc[0] = T_REG | T_IND | T_DIR;
	op_tab[6].ref_enc[1] = T_REG | T_IND | T_DIR;
	op_tab[6].ref_enc[2] = T_REG;
	op_tab[7].ref_enc[0] = T_REG | T_IND | T_DIR;
	op_tab[7].ref_enc[1] = T_REG | T_IND | T_DIR;
	op_tab[7].ref_enc[2] = T_REG;
	op_tab[8].ref_enc[0] = T_DIR;
	op_tab[8].ref_enc[1] = 0;
	op_tab[8].ref_enc[2] = 0;
	op_tab[9].ref_enc[0] = T_REG | T_DIR | T_IND;
	op_tab[9].ref_enc[1] = T_DIR | T_REG;
	op_tab[9].ref_enc[2] = T_REG;
	op_tab[10].ref_enc[0] = T_REG;
	op_tab[10].ref_enc[1] = T_REG | T_DIR | T_IND;
	op_tab[10].ref_enc[2] = T_DIR | T_REG;
	op_tab[11].ref_enc[0] = T_DIR;
	op_tab[11].ref_enc[1] = 0;
	op_tab[11].ref_enc[2] = 0;
	op_tab[12].ref_enc[0] = T_DIR | T_IND;
	op_tab[12].ref_enc[1] = T_REG;
	op_tab[12].ref_enc[2] = 0;
	op_tab[13].ref_enc[0] = T_REG | T_DIR | T_IND;
	op_tab[13].ref_enc[1] = T_DIR | T_REG;
	op_tab[13].ref_enc[2] = T_REG;
	ft_init_struct_ref_4(op_tab);
}

void			ft_init_struct_ref_2(t_op *op_tab)
{
	op_tab[7].nb_args = 3;
	op_tab[8].nb_args = 1;
	op_tab[9].nb_args = 3;
	op_tab[10].nb_args = 3;
	op_tab[11].nb_args = 1;
	op_tab[12].nb_args = 2;
	op_tab[13].nb_args = 3;
	op_tab[14].nb_args = 1;
	op_tab[15].nb_args = 1;
	op_tab[16].nb_args = 0;
	op_tab[0].ref_enc[0] = T_DIR;
	op_tab[1].ref_enc[0] = T_DIR | T_IND;
	op_tab[1].ref_enc[1] = T_REG;
	op_tab[2].ref_enc[0] = T_REG;
	op_tab[2].ref_enc[1] = T_IND | T_REG;
	op_tab[3].ref_enc[0] = T_REG;
	op_tab[3].ref_enc[1] = T_REG;
	op_tab[3].ref_enc[2] = T_REG;
	op_tab[4].ref_enc[0] = T_REG;
	op_tab[4].ref_enc[1] = T_REG;
	op_tab[4].ref_enc[2] = T_REG;
	op_tab[5].ref_enc[0] = T_REG | T_DIR | T_IND;
	op_tab[5].ref_enc[1] = T_REG | T_IND | T_DIR;
	op_tab[5].ref_enc[2] = T_REG;
	ft_init_struct_ref_3(op_tab);
}

void			ft_init_struct_ref_1(t_op *op_tab)
{
	op_tab[0].ref_name = "live";
	op_tab[1].ref_name = "ld";
	op_tab[2].ref_name = "st";
	op_tab[3].ref_name = "add";
	op_tab[4].ref_name = "sub";
	op_tab[5].ref_name = "and";
	op_tab[6].ref_name = "or";
	op_tab[7].ref_name = "xor";
	op_tab[8].ref_name = "zjmp";
	op_tab[9].ref_name = "ldi";
	op_tab[10].ref_name = "sti";
	op_tab[11].ref_name = "fork";
	op_tab[12].ref_name = "lld";
	op_tab[13].ref_name = "lldi";
	op_tab[14].ref_name = "lfork";
	op_tab[15].ref_name = "aff";
	op_tab[16].ref_name = 0;
	op_tab[0].nb_args = 1;
	op_tab[1].nb_args = 2;
	op_tab[2].nb_args = 2;
	op_tab[3].nb_args = 3;
	op_tab[4].nb_args = 3;
	op_tab[5].nb_args = 3;
	op_tab[6].nb_args = 3;
	ft_init_struct_ref_2(op_tab);
}
