.name "and"
.comment "and"

res:
and		r2, r3, r2		#add r2 + r3 et stock le res dans r2
zjmp	%:res			#jump a la valeur de res
