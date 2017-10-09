.name "maoow"
.comment "meoow"

start:
sti		r1, %:live, %1
sti		r1, %:live2, %1

live:
live %0
fork	%:live
and		r4, r4, r5
zjmp 	%:live2

live2:
live %0
and		r4, r4, r5
fork	%:test
fork 	%:live

test:
