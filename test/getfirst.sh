#!/bin/bash

i=0

step=10000
while [ $step -gt 0 ]
do
	diff=0
	while [ $diff -lt 1 ]
	do
	echo $i
		i=$(($i + $step))
		./corewar -n -1 ressources/zaz_champ/$@.cor -v4 -dump $i > /tmp/me
		./ressources/corewar_goinfre ressources/zaz_champ/$@.cor -v 4 -d $i > /tmp/you
		diff /tmp/me /tmp/you > /tmp/diff
		diff=$(wc -l < /tmp/diff)
	done
	i=$(($i - $step))
	echo $i
	step=$(($step / 10))
done
cat /tmp/diff


i=0

step=10000
while [ $step -gt 0 ]
do
	diff=0
	while [ $diff -lt 1 ]
	do
		i=$(($i + $step))
		./corewar -n -1 ressources/zaz_champ/$@.cor -v16 -dump $i > /tmp/me
		./ressources/corewar_goinfre ressources/zaz_champ/$@.cor -v 16 -d $i > /tmp/you
		diff /tmp/me /tmp/you > /tmp/diff
		diff=$(wc -l < /tmp/diff)
	done
	i=$(($i - $step))
	echo $i
	step=$(($step / 10))
done
cat /tmp/diff

