#!/bin/bash


good=1
for var in "fluttershy" "zork" "bigzork" "turtle" "helltrain"; do
	./corewar ressources/zaz_champ/$var.cor -v4 > /tmp/v4me
	./ressources/corewar_goinfre ressources/zaz_champ/$var.cor -v 4 > /tmp/v4you
	diff -y --suppress-common-lines /tmp/v4me /tmp/v4you > /tmp/diff
	diff=$(wc -l < /tmp/diff)
	if [ $diff != 0 ]
	then
		echo 
		echo $var
		echo $diff
		head -n 50 /tmp/diff
		good=0
		echo 
		exit 1
	else
		head -n 50 /tmp/diff
		echo $var
		echo good
	fi
done
for var in "fluttershy" "zork" "bigzork" "turtle" "helltrain"; do
	for var2 in  "zork" "bigzork" "helltrain" "turtle"; do
		./corewar ressources/zaz_champ/$var2.cor ressources/zaz_champ/$var.cor -v4 > /tmp/v4me
		./ressources/corewar_goinfre ressources/zaz_champ/$var2.cor ressources/zaz_champ/$var.cor -v 4 > /tmp/v4you
		diff -y --suppress-common-lines /tmp/v4me /tmp/v4you > /tmp/diff
		diff=$(wc -l < /tmp/diff)
		if [ $diff != 0 ]
		then
			echo 
			echo $var $var2
			echo $diff
			head -n 50 /tmp/diff
			good=0
			echo 
			#exit 1
		else
			head -n 50 /tmp/diff
			echo $var $var2
			echo good
		fi
	done
done
for var in "fluttershy" "zork" "bigzork" "turtle" "helltrain"; do
	./corewar ressources/zaz_champ/$var.cor -v16 > /tmp/v16me
	./ressources/corewar_goinfre ressources/zaz_champ/$var.cor -v 16 > /tmp/v16you
	diff /tmp/v16me /tmp/v16you > /tmp/diff
	diff=$(wc -l < /tmp/diff)
	if [ $diff != 0 ]
	then
		echo 
		echo $var
		echo $diff
		cat /tmp/diff
		good=0
		echo 
		#exit 1
	else
		head -n 50 /tmp/diff
		echo $var
		echo good
	fi
done
for var in "fluttershy" "zork" "bigzork" "turtle" "helltrain"; do
	for var2 in  "zork" "bigzork" "helltrain" "turtle"; do
		./corewar ressources/zaz_champ/$var2.cor ressources/zaz_champ/$var.cor -v16 > /tmp/v16me
		./ressources/corewar_goinfre ressources/zaz_champ/$var2.cor ressources/zaz_champ/$var.cor -v 16 > /tmp/v16you
		diff -y --suppress-common-lines /tmp/v16me /tmp/v16you > /tmp/diff
		diff=$(wc -l < /tmp/diff)
		if [ $diff != 0 ]
		then
			echo 
			echo $var $var2
			echo $diff
			cat /tmp/diff
			good=0
			echo 
			#exit 1
		else
			head -n 50 /tmp/diff
			echo $var $var2

			echo good
		fi
	done
done
if [ $good != 0 ]
then
	echo "wp!"
fi
exit 0
