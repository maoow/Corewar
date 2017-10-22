#!/bin/bash

./corewar ressources/zaz_champ/$@.cor -v4 > /tmp/v4me
./ressources/corewar_goinfre ressources/zaz_champ/$@.cor -v 4 > /tmp/v4you
echo $@ :
diff -y --suppress-common-lines /tmp/v4me /tmp/v4you 
