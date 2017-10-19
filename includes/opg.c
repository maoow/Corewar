#include "operations.h"

size_t					g_optime[OPC_NBR] = {
	10,
	5,
	5,
	10,
	10,
	6,
	6,
	6,
	20,
	25,
	25,
	800,
	10,
	50,
	1000,
	2
};
bool					g_opcarry[OPC_NBR] = {
	false,
	true,
	false,
	true,
	true,
	true,
	true,
	true,
	false,
	false,
	false,
	false,
	true,
	true,
	false,
	false,
};
bool					(*g_opctable[OPC_NBR])(t_cor *, t_process *) = {
	&cw_live,
	&cw_ld,
	&cw_st,
	&cw_add,
	&cw_sub,
	&cw_and,
	&cw_or,
	&cw_xor,
	&cw_zjmp,
	&cw_ldi,
	&cw_sti,
	&cw_fork,
	&cw_lld,
	&cw_lldi,
	&cw_lfork,
	&cw_aff
};


size_t					g_opparamnb[OPC_NBR] = {
	1,
	2,
	2,
	3,
	3,
	3,
	3,
	3,
	1,
	3,
	3,
	1,
	2,
	3,
	1,
	1
};
extern bool					g_ocp[OPC_NBR];
extern size_t				g_oplabel[OPC_NBR];
