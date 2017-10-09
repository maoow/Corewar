.name "ldi"
.comment "ldi"

res:
ldi		r2, %3, r2		#ldi r2 + r3 et stock le res dans r2
zjmp	%:res			#jump a la valeur de res
