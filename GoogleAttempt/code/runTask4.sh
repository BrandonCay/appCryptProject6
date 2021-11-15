#!/bin/sh
#
#
#start of runTask4.sh

echo "---running task 4---"


cat runTask4.sh

gcc -o task4Out task4.c rsaFunctions.c -lcrypto -Wall

echo "--Run source file"
./task4Out

python -c 'print("4120746f702073656372657421".decode("hex"))' #change hex to output from task4.c


echo "---end runTask4.sh---"

#end of runTask4.sh
#
#
