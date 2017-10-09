#!/bin/bash
n=0
step=100
diff=0
FILESIZE=0
./corewar ressources/zaz_champ/fluttershy.cor -v4 > me
./ressources/corewar_goinfre ressources/zaz_champ/fluttershy.cor -v 4 > fme
while [ $FILESIZE -lt 1 ]
do
head -n $n me > me1
head -n $n fme > fme1
diff -y --suppress-common-lines me1 fme1 > diffss
FILESIZE=$(wc -c < "diffss")
n=$(($n + $step))
done
rm me fme
echo "first diff at line " . $n
echo "me											you"
cat diffss
