.name "sti"
.comment "sti"

loop:
sti r1, r2, r3
and	r1, r1
zjmp %:loop
