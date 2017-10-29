#!/bin/bash

i=23700

step=1
diff=0
while [ $diff -lt 1 ]
do
	i=$(($i + $step))
	./corewar ressources/zaz_champ/$@.cor -v4 -dump $i > /tmp/me
	./ressources/corewar_goinfre ressources/zaz_champ/$@.cor -v 4 -d $i > /tmp/you
	diff /tmp/me /tmp/you > /tmp/diff
	diff=$(wc -l < /tmp/diff)
	echo $i
done
cat /tmp/diff


i=0

step=10
diff=0
while [ $diff -lt 1 ]
do
	i=$(($i + $step))
	./corewar ressources/zaz_champ/$@.cor -v16 -dump $i > /tmp/me
	./ressources/corewar_goinfre ressources/zaz_champ/$@.cor -v 16 -d $i > /tmp/you
	diff /tmp/me /tmp/you > /tmp/diff
	diff=$(wc -l < /tmp/diff)
done
cat /tmp/diff

