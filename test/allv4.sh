#!/bin/bash
for var in "fluttershy" "zork" "bigzork" "turtle" "helltrain"; do
./corewar ressources/zaz_champ/$var.cor -v4 > /tmp/v4me
./ressources/corewar_goinfre ressources/zaz_champ/$var.cor -v 4 > /tmp/v4you
echo $var :
diff -y --suppress-common-lines /tmp/v4me /tmp/v4you | head -n 40
done
