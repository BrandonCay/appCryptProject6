currFileName="runStep2"

openssl x509 -in c1.pem -noout -modulus > ${currFileName}_out.txt

openssl x509 -in c1.pem -text -noout > ${currFileName}_out_2.txt

chmod +x getExponent.py

exponentFileName="exp.txt"

python getExponent.py > ${exponentFileName}
 

