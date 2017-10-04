#!/bin/bash
rm tests/diffs*
n=2450
diff=0
while [ $diff -lt 2 ]
do
./corewar ressources/zaz_champ/fluttershy.cor -dump $n > me
./ressources/corewar_goinfre ressources/zaz_champ/fluttershy.cor -d $n > you
diff me you > tests/diffs$n
n=$(($n + 10))
done
