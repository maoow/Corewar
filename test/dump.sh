#!/bin/bash
rm tests/diffs*
n=8880
diff=0
FILESIZE=0
while [ $FILESIZE -lt 1 ]
do
./corewar ressources/zaz_champ/helltrain.cor -dump $n > me
./ressources/corewar_goinfre ressources/zaz_champ/helltrain.cor -d $n > you
diff me you  > tests/diffs
FILESIZE=$(wc -c < "tests/diffs")
echo $n
n=$(($n + 10))
done
cat tests/diffs
rm you me
