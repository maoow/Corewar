#!/bin/bash
rm tests/diffs*
n=2300
diff=0
while [ $n -lt 2500 ]
do
./corewar ressources/zaz_champ/fluttershy.cor -v4 -dump $n > me
./ressources/corewar_goinfre ressources/zaz_champ/fluttershy.cor -v 4 -d $n > you
diff me you > tests/diffs$n
n=$(($n + 25))
done
