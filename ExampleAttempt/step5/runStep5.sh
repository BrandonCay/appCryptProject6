issuer_pub="c0"
stackexchange_signature="a72a10305cb86b7a1bf86638f6e9a00ad5138282f8658957a5b8eb13291d846cecfbe30511d71e315e0ee2c000e56d0648be3d556fbab71135b6eac4cf84f1304cbb339e11172bc9d2194b2cd0ad5f172384e1df17a23ba87f69297c48a6615f263f75e23b5ba336b31ccde30457301ffcc9fa4b8e488058279ca2c7c326dc1702fae66cea81015c928fd3180817707ac2a34b6c3afae3cff6fe7ec956e5a54e1b144fa9989d79b11ec3abb10d1585a946b6e5c258e85afec814286890c6b8c8947fe10f89faa7d60937a162b70027b5bef1b15e452806b35415e6c3c8ac8201ce86e22be17ae4bd4ccb9c5ed062c261bd8b5a62b67630bc460fe34523c0645f"
cert_body="c0_body"

openssl dgst -sha256 -verify ${issuer_pub}.pem -signature ${stackexchange_signature}.bin ${cert_body}.bin > output.txt

cFileName="task6Step4"

gcc ${cFileName}.c rsaFunctions.c -o ${cFileName}.out -lcrypto

./${cFileName}.out &> verificationResults.txt 

