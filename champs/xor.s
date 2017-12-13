.name "xor"
.comment "xor"

ld		%1, r3
ld		%1, r2
res:
add		r3, r3, r3
xor		r2, r3, r2		#add r2 + r3 et stock le res dans r2
zjmp	%:res			#jump a la valeur de res
xor		r4, r4, r2		#add r2 + r3 et stock le res dans r2
zjmp	%:res			#jump a la valeur de res
