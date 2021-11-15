currFileName="runTask3"

openssl x509 -in c0.pem -text -noout > ${currFileName}_out.txt

cat signature | tr -d ’[:space:]:’ > ${currFileName}_out_2.txt

