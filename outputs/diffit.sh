#!/bin/bash

#make
#./corewar ressources/zaz_champ/zork.cor -v4 > outputs/our/zork.cor
#./ressources/corewar_goinfre ressources/zaz_champ/zork.cor -v 4 > outputs/official/zork.cor
diff -y outputs/our/zork.cor outputs/official/zork.cor > outputs/diff/zork.cor
diff outputs/our/zork.cor outputs/official/zork.cor > outputs/diff/lzork.cor
echo zork

#./corewar ressources/zaz_champ/helltrain.cor -v4 > outputs/our/helltrain.cor
#./ressources/corewar_goinfre ressources/zaz_champ/helltrain.cor -v 4 > outputs/official/helltrain.cor
diff -y outputs/our/helltrain.cor outputs/official/helltrain.cor > outputs/diff/helltrain.cor
diff outputs/our/helltrain.cor outputs/official/helltrain.cor > outputs/diff/lhelltrain.cor
echo helltrain


#./corewar ressources/zaz_champ/turtle.cor -v4 > outputs/our/turtle.cor
#./ressources/corewar_goinfre ressources/zaz_champ/turtle.cor -v 4 > outputs/official/turtle.cor
diff -y outputs/our/turtle.cor outputs/official/turtle.cor > outputs/diff/turtle.cor
diff outputs/our/turtle.cor outputs/official/turtle.cor > outputs/diff/lturtle.cor
echo turtle

#./corewar ressources/zaz_champ/bigzork.cor -v4 > outputs/our/bigzork.cor
#./ressources/corewar_goinfre ressources/zaz_champ/bigzork.cor -v 4 > outputs/official/bigzork.cor
diff -y outputs/our/bigzork.cor outputs/official/bigzork.cor > outputs/diff/bigzork.cor
diff outputs/our/bigzork.cor outputs/official/bigzork.cor > outputs/diff/lbigzork.cor
echo bigzork

#./corewar ressources/zaz_champ/bee_gees.cor -v4 > outputs/our/bee_gees.cor
#./ressources/corewar_goinfre ressources/zaz_champ/bee_gees.cor -v 4 > outputs/official/bee_gees.cor
diff -y outputs/our/bee_gees.cor outputs/official/bee_gees.cor > outputs/diff/bee_gees.cor
diff outputs/our/bee_gees.cor outputs/official/bee_gees.cor > outputs/diff/lbee_gees.cor
echo bee_gees
