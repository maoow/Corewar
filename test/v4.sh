#!/bin/bash

./corewar ressources/zaz_champ/$@.cor -v4 > /tmp/me
./ressources/corewar_goinfre ressources/zaz_champ/$@.cor -v 4 > /tmp/you
echo $@ :
diff -y --suppress-common-lines /tmp/me /tmp/you | head
