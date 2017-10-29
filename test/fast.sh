#!/bin/bash

i=0

step=1000
while [ $step -gt 0 ]
do
	diff=0
	while [ $diff -lt 1 ]
	do
		i=$(($i + $step))
		./corewar ressources/zaz_champ/$@.cor -v4 -dump $i > /tmp/me
		./corewar ressources/zaz_champ/$@.cor -v4 -dump $i -fast > /tmp/you
		diff /tmp/me /tmp/you > /tmp/diff
		diff=$(wc -l < /tmp/diff)
	done
	i=$(($i - $step))
	echo $i
	step=$(($step / 10))
done
cat /tmp/diff

