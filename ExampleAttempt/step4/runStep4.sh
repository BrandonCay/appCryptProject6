currFileName="runStep4"

openssl asn1parse -i -in c0.pem > ${currFileName}_out.txt

openssl asn1parse -i -in c0.pem -strparse 4 -out c0_body.bin -noout

sha256sum c0_body.bin > ${currFileName}_sha_out.txt
