#!/bin/bash

i=0

step=10000
while [ $step -gt 0 ]
do
	diff=0
	while [ $diff -lt 1 ]
	do
		i=$(($i + $step))
		./corewar ressources/zaz_champ/$@.cor -v2 -dump $i > /tmp/me
		./ressources/corewar_goinfre ressources/zaz_champ/$@.cor -v 2 -d $i > /tmp/you
		diff -y --suppress-common-lines /tmp/me /tmp/you > /tmp/diff
		echo $i
		diff=$(wc -l < /tmp/diff)
	done
	i=$(($i - $step))
	step=$(($step / 10))
done
cat /tmp/diff

