#!/bin/sh
#
#
#start of runTask3.sh

echo "---running task 3---"


cat runTask3.sh

gcc -o task3Out task3.c rsaFunctions.c -lcrypto -Wall

echo "--Run source file"
./task3Out

python -c 'print("4120746f702073656372657421".decode("hex"))' #change hex to output from task3.c


echo "---end runTask3.sh---"

#end of runTask3.sh
#
#


