.name "snuggles"
.comment "FAT ! HEAVY AS A BRICKAAA !"

start:
sti		r1, %:retrosecure, %7
sti		r1, %:live, %1
sti		r1, %:prelive, %1
sti		r1, %:cpy, %1
sti		r1, %:cp, %1
sti		r1, %:init, %1
xor		r9, r9, r9

init:
live %0
ld		%2, r2 		# count for cpy and retro
ld		%128, r8	# stop	for cpy
ld		%960, r13	# stop	for icpy
ld		%32, r11	# stop	for prepost
ld		%251662080, r12 # 0f 0f 0f 0f
live %0
fork	%:feed

#ld		%2, r3

prepostinit:
live %2290649224
ld		%-6, r15
add		r2, r2, r2
add		r15, r2, r15
sub		r2, r11, r7
zjmp	%:postinit
fork	%:prepostinit
postinit:
ld		%442, r16


retrosecure:
sti		r12, %-490 , r16
live	%2290649224
sub		r16, r2, r16
xor		r15, r16, r14
zjmp	%:postinit
xor		r9, r9, r9
zjmp	%:retrosecure

feed:
live %0
fork	%:cp
fork	%:feed
live %0
fork	%:andfeed
fork	%:autofeed

andfeed:
live %0
fork	%:prepostinit
live %0
fork	%:prepostinit
zjmp	%:andfeed

autofeed:
live %0
fork	%:autofeed
live %0
fork	%:andfeed
zjmp	%:autofeed

cp:
live %0
fork	%:preprelive

icpy:
add		r2, r2, r2
sub		r6, r13, r16
zjmp		%:init3

cpy:
live %0
ldi		%:cp, r6, r3
sti		r3, %:andthen, r6
add		r6, r2, r6
xor		r8, r6, r10
zjmp	%:init2
xor		r9, r9, r9
zjmp	%:cpy

preprelive:
xor		r9, r9, r9

prelive:
live %0
fork	%:prelive

live:
live %0
zjmp	%:live

init2:
add		r8, r8, r8
fork	%:icpy
live 	%0
add		r2, r6, r6
fork	%:icpy
init3:
live 	%0
ld		%0, r6
ld		%128, r8
ld		%2, r2

andthen:
