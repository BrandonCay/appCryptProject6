

/* bn_sample.c */
#include "rsaFunctions.h"
#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256
void printBN(char *msg, BIGNUM * a)
{
/* Use BN_bn2hex(a) for hex string
* Use BN_bn2dec(a) for decimal string */
    char * number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main ()
{

    BN_CTX *ctx = BN_CTX_new();

    BIGNUM *C = BN_new();
    BIGNUM *M = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *S = BN_new();

    BN_hex2bn(&M, "4c61756e63682061206d697373696c652e"); //"Launch a missle."
    BN_hex2bn(&C, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
    BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");

    unsignSignature(C,S,e,n);

    if(BN_cmp(C, M) == 0){
        printf("Valid");
    }
    else{
        printf("Fail");
    }

    BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");//bugged
    
    unsignSignature(C,S,e,n);

    printBN("C (corrupted) = ", C);

    if(BN_cmp(C, M) == 0){
        printf("Valid");
    }
    else{
        printf("Fail");
    }


    //deallocate vars

return 0;
}