#!/bin/bash
n=0
step=100
diff=0
FILESIZE=0
while [ $FILESIZE -lt 1 ]
do
./corewar ressources/zaz_champ/fluttershy.cor -v4 -dump $n > me
./corewar ressources/zaz_champ/fluttershy.cor -v4 -fast -dump $n > fme
#./ressources/corewar_goinfre ressources/zaz_champ/fluttershy.cor -v 4 -d $n > you
diff -y --suppress-common-lines me fme > diffss
#FILESIZE=$(stat -c%s "difss")
FILESIZE=$(wc -c < "diffss")
n=$(($n + $step))
done
rm me fme
echo "first diff at cycle " . $n
echo "me											fme"
cat diffss
