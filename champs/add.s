.name "add"
.comment "add"

res:
add		r2, r3, r2		#add r2 + r3 et stock le res dans r2
zjmp	%:res			#jump a la valeur de res
