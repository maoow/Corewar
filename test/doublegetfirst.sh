#!/bin/bash
make

i=0

step=10000
while [ $step -gt 0 ]
do
	diff=0
	while [ $diff -lt 1 ]
	do
		i=$(($i + $step))
		./corewar -n -1 ressources/zaz_champ/$@.cor -n -2 ressources/zaz_champ/$@.cor -v4 -dump $i > /tmp/2me
		./ressources/corewar_goinfre ressources/zaz_champ/$@.cor ressources/zaz_champ/$@.cor -v 4 -d $i > /tmp/2you
		diff /tmp/2me /tmp/2you > /tmp/2diff
		diff=$(wc -l < /tmp/2diff)
	done
	i=$(($i - $step))
		echo $i
	step=$(($step / 10))
done
cat /tmp/2diff

i=0

step=10000
while [ $step -gt 0 ]
do
	diff=0
	while [ $diff -lt 1 ]
	do
		i=$(($i + $step))
		./corewar -n -1 ressources/zaz_champ/$@.cor -n -2 ressources/zaz_champ/$@.cor -v16 -dump $i > /tmp/2me
		./ressources/corewar_goinfre ressources/zaz_champ/$@.cor ressources/zaz_champ/$@.cor -v 16 -d $i > /tmp/2you
		diff /tmp/2me /tmp/2you > /tmp/2diff
		diff=$(wc -l < /tmp/2diff)
	done
	i=$(($i - $step))
		echo $i
	step=$(($step / 10))
done
cat /tmp/2diff

