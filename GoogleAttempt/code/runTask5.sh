#!/bin/sh
#
#
#start of runTask5.sh

echo "---running task 5---"


cat runTask5.sh

gcc -o task5Out task5.c rsaFunctions.c -lcrypto -Wall

echo "--Run source file"
./task5Out

python -c 'print("4120746f702073656372657421".decode("hex"))' #change hex to output from task5.c


echo "---end runTask5.sh---"

#end of runTask5.sh
#
#