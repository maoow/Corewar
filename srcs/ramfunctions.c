size_t	getram(t_cor *core, size_t address)
{
	size_t	value;

	value = core->arena[address];
	value *= 256;
	value = core->arena[address + 1];
	value *= 256;
	value = core->arena[address + 2];
	value *= 256;
	value = core->arena[address + 3];
	return (value);
}
void		setram(t_cor *core, size_t address, size_t value)
