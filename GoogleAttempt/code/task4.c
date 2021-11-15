

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

    BN_hex2bn(&M, "49206f776520796f75202432303030"); //"I owe you $2000"
    BN_hex2bn(&C, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
    BN_hex2bn(&e, "0D88C3");
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");

    rsaEncrypt(C,M,e,n);

    printBN("C $2000 = ", C);

    BN_hex2bn(&M, "49206f776520796f75202433303030"); //"I owe you $3000"

    rsaEncrypt(C,M,e,n);

    printBN("C $3000 = ", C);

    //deallocate vars

return 0;
}