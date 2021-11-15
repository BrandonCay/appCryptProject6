#include <openssl/bn.h>

void calcN(BIGNUM *, BIGNUM *, BIGNUM *);

void calcOslashed(BIGNUM *, BIGNUM * , BIGNUM *);

void calcD(BIGNUM *, BIGNUM *, BIGNUM *);


void rsaEncrypt(BIGNUM * , BIGNUM *, BIGNUM *, BIGNUM *);

void rsaDecrypt(BIGNUM * , BIGNUM *, BIGNUM *, BIGNUM *);

void unsignSignature(BIGNUM * , BIGNUM *, BIGNUM *, BIGNUM *);
