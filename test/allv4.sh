#!/bin/bash
for var in "fluttershy" "zork" "bigzork" "turtle" "helltrain"; do
	./corewar ressources/zaz_champ/$var.cor -v4 > /tmp/v4me
	./ressources/corewar_goinfre ressources/zaz_champ/$var.cor -v 4 > /tmp/v4you
	diff /tmp/v4me /tmp/v4you > /tmp/diff
	diff=$(wc -l < /tmp/diff)
	if [ $diff != 0 ]
	then
		exit 1
	fi
done
for var in "fluttershy" "zork" "bigzork" "turtle" "helltrain"; do
	./corewar ressources/zaz_champ/$var.cor ressources/zaz_champ/$var.cor -v4 > /tmp/v4me
	./ressources/corewar_goinfre ressources/zaz_champ/$var.cor ressources/zaz_champ/$var.cor -v 4 > /tmp/v4you
	diff /tmp/v4me /tmp/v4you > /tmp/diff
	diff=$(wc -l < /tmp/diff)
	if [ $diff != 0 ]
	then
		exit 1
	fi
done
for var in "fluttershy" "zork" "bigzork" "turtle" "helltrain"; do
	for var2 in "fluttershy" "zork" "bigzork" "turtle" "helltrain"; do
		./corewar ressources/zaz_champ/$var2.cor ressources/zaz_champ/$var.cor -v4 > /tmp/v4me
		./ressources/corewar_goinfre ressources/zaz_champ/$var2.cor ressources/zaz_champ/$var.cor -v 4 > /tmp/v4you
		diff /tmp/v4me /tmp/v4you > /tmp/diff
		diff=$(wc -l < /tmp/diff)
		if [ $diff != 0 ]
		then
			exit 1
		fi
	done
done
exit 0
