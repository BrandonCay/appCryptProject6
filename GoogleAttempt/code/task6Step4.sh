echo "---running task 6---"


cat runTask6.sh

gcc -o task6Step4Out task6.c rsaFunctions.c -lcrypto -Wall

echo "--Run source file"
./task6Step4Out


echo "---end runTask6.sh---"

#e
#
#