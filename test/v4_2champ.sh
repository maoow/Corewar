#!/bin/bash

i=0

step=1000
while [ $step -gt 0 ]
do
	diff=0
	while [ $diff -lt 1 ]
	do
		echo $i
		i=$(($i + $step))
		./corewar ressources/zaz_champ/fluttershy.cor ressources/zaz_champ/fluttershy.cor -v4 -v2 -dump $i > /tmp/me
		./ressources/corewar_goinfre ressources/zaz_champ/fluttershy.cor ressources/zaz_champ/fluttershy.cor -v 4 -v 2 -d $i > /tmp/you
		diff /tmp/me /tmp/you > /tmp/diff
		diff=$(wc -l < /tmp/diff)
	done
	i=$(($i - $step))
	echo $i
	step=$(($step / 10))
done
cat /tmp/diff

