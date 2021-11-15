#include "rsaFunctions.h"

#include <stdio.h>
#include <openssl/bn.h>

void calcN(BIGNUM *n, BIGNUM *p, BIGNUM *q){
	BN_CTX *ctx = BN_CTX_new(); 
	BN_mul(n, p, q, ctx);
}

void calcOslashed(BIGNUM *oSlashed, BIGNUM * p , BIGNUM * q){
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *subResFromP = BN_new();
	BIGNUM *subResFromQ = BN_new();
	BIGNUM *one = BN_new();

	BN_dec2bn(&one, "1");
	
	BN_sub(subResFromP, p , one);
	BN_sub(subResFromQ, q, one);

	BN_mul(oSlashed, subResFromP, subResFromQ, ctx);
}

void calcD(BIGNUM *d, BIGNUM *e, BIGNUM *oSlashed){
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *exponent = BN_new();

	BN_dec2bn(&exponent, "-1");

	BN_mod_inverse(d, e, oSlashed, ctx);
}


void rsaEncrypt(BIGNUM * C, BIGNUM *M, BIGNUM *e, BIGNUM *n){
	BN_CTX *ctx = BN_CTX_new();
	BN_mod_exp(C, M, e, n, ctx);
}

void rsaDecrypt(BIGNUM * M, BIGNUM *C, BIGNUM *d, BIGNUM *n){
	BN_CTX *ctx = BN_CTX_new();
	BN_mod_exp(M, C, d, n, ctx);
}

bool unsignSignature(BIGNUM *C , BIGNUM *Signature, BIGNUM *e, BIGNUM *n ){
	BN_CTX *ctx = BN_CTX_new();
	BN_mod_exp(C, Signature, e, n, ctx);
}

