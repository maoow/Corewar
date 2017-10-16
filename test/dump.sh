#!/bin/bash
rm test/diffs*
n=1
diff=0
FILESIZE=0
while [ $FILESIZE -lt 1 ]
do
./corewar ressources/zaz_champ/helltrain.cor -dump $n > test/me
./ressources/corewar_goinfre ressources/zaz_champ/helltrain.cor -d $n > test/you
diff test/me test/you  > test/diffs
FILESIZE=$(wc -c < "test/diffs")
n=$(($n + 1))
done
echo "helltrain :"
echo $(($n - 1))
cat test/diffs
rm you me
n=1
diff=0
FILESIZE=0
while [ $FILESIZE -lt 1 ]
do
./corewar ressources/zaz_champ/bee_gees.cor -dump $n > test/me
./ressources/corewar_goinfre ressources/zaz_champ/bee_gees.cor -d $n > test/you
diff test/me test/you  > test/diffs
FILESIZE=$(wc -c < "test/diffs")
n=$(($n + 1))
done
echo "bee_gees :"
echo $(($n - 1))
cat test/diffs
rm you me
n=1
diff=0
FILESIZE=0
while [ $FILESIZE -lt 1 ]
do
./corewar ressources/zaz_champ/bigzork.cor -dump $n > test/me
./ressources/corewar_goinfre ressources/zaz_champ/bigzork.cor -d $n > test/you
diff test/me test/you  > test/diffs
FILESIZE=$(wc -c < "test/diffs")
n=$(($n + 1))
done
echo "bigzork :"
echo $(($n - 1))
cat test/diffs
rm you me
n=1
diff=0
FILESIZE=0
while [ $FILESIZE -lt 1 ]
do
./corewar ressources/zaz_champ/turtle.cor -dump $n > test/me
./ressources/corewar_goinfre ressources/zaz_champ/turtle.cor -d $n > test/you
diff test/me test/you  > test/diffs
FILESIZE=$(wc -c < "test/diffs")
n=$(($n + 1))
done
echo "turtle :"
echo $(($n - 1))
cat test/diffs
rm you me
n=1
diff=0
FILESIZE=0
while [ $FILESIZE -lt 1 ]
do
./corewar ressources/zaz_champ/zork.cor -dump $n > test/me
./ressources/corewar_goinfre ressources/zaz_champ/zork.cor -d $n > test/you
diff test/me test/you  > test/diffs
FILESIZE=$(wc -c < "test/diffs")
n=$(($n + 1))
done
echo "zork :"
echo $(($n - 1))
cat test/diffs
rm you me
n=1
diff=0
FILESIZE=0
while [ $FILESIZE -lt 1 ]
do
./corewar ressources/zaz_champ/fluttershy.cor -dump $n > test/me
./ressources/corewar_goinfre ressources/zaz_champ/fluttershy.cor -d $n > test/you
diff test/me test/you  > test/diffs
FILESIZE=$(wc -c < "test/diffs")
n=$(($n + 1))
done
echo "fluttershy :"
echo ($n - 1)
cat test/diffs
rm you me
