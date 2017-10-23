#!/bin/bash

./corewar ressources/zaz_champ/$@.cor -v2 > /tmp/v2me
./ressources/corewar_goinfre ressources/zaz_champ/$@.cor -v 2 > /tmp/v2you
echo $@ :
diff -y --suppress-common-lines /tmp/v2me /tmp/v2you 
