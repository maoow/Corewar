.name "fork"
.comment "fork"

start:
sti		r1, %:live, %1

live:
live %0
fork	%:live
and		r4, r4, r5
zjmp 	%:live
