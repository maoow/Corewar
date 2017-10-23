.name "rep"
.comment "oui"

regcopy:
	ld %-114, r2
	ld %-6, r3
	ld %150994953, r4
	ld %-186, r5
	ld %224, r15

memcopy:
	ld %33554431, r16
	sti r16, %:execution, %0
	ld %4278190080, r16
	sti r16, %:execution, %4
	ld %33722368, r16
	sti r16, %:execution, %8
	ld %36864, r16
	sti r16, %:execution, %12
	ld %0, r16
	or r16, r16, r16

execution:
