#!/bin/bash
rm tests/diffs*
n=2500
diff=0
FILESIZE=0
while [ $FILESIZE -lt 1 ]
do
./corewar ressources/zaz_champ/fluttershy.cor -dump $n > me
./ressources/corewar_goinfre ressources/zaz_champ/fluttershy.cor -d $n > you
diff me you  > tests/diffs
FILESIZE=$(wc -c < "tests/diffs")
echo $n
n=$(($n + 1))
done
