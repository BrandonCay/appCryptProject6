
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

    BIGNUM *C = BN_new();
    BIGNUM *M = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *S = BN_new();

    //BN_hex2bn(&M, "4c61756e63682061206d697373696c652e"); //"Launch a missle."
    /*
    char google_e [] = "65537" ;
    
    char google_n [] = "BD4A4350DAD86ADA684EE5AB83B7717999DC8A0F6701C637D60DFE6\
    4153DAC42E872C9F4BDF56B1B0064B7643B13E96E3F205185240B2826A2FE8003AED2\
    50E82CF0E4BB9719281716428711570028CF87EE0919E2150DE7061E576250C1F71CD\
    E1034E205BA047CDDE99E1988D64A2E8F73F84A6F4D1FA3D42A0739D48377D2788AD56\
    8F01CF0FD706492BFE6C92397F6B5468FC4BB5FFDE016C033E922DE771D15C30D46A\
    E4370DA0954944CA8BE98608B3A577B26B401E56AB24015DDE292974C9EDD4D36B512FBB0D0EC8B6D10A61BAE\
    716D4D0D0753BC801AD9986850A00D2BE1858078471752CB8F63D232CAD4A054848A94EB2698DEA3A4E658637489";
    
    char google_C [] = "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F";
    
    char google_S [] = "7466bd6a013940556326d37ff21cbbe05934c56acee72fb3a6262685dd47fd4721400bc12a8b2429249ca575f31a761c1b4c5cb2ae5523af15ad316385b468e70bbfa0eb283c22b \
    131e4c03cd876cf9aa64459093b595586d48624d50ad6a407f8e4c0a075e7d2e7a296c5dcbdc04c \
    78ffd74031a7c548f4cf218fdd4086ede37415dd61dd8aad958264d3fbe6fab3d2f6d181d63a281\
    d075919986795acd7e63ec5cfdeeae8e5de8d6305398a021b50b37fd4979ac136d11168ad058d2e\
    c971e9a3a6c643128f6ce20340be3e656f04c6e1a9c09aed4a739109db20380ef37c64e9186b03bf\
    fe464d6e4f699cd7fa2f1d50df273caca750779b1c9b918df102";
    //google was a failure
    */
    
    char example_e[10] = "65537";
    
    char example_n[2000] = "BAFCEECCCA0A08FF0E931DB3BE0B9C0396229EB14F10AE5140FD535FB3C461 \
    402804EEA2E61200B08285985C6D5B6B20844462954E6B767C50705DDF131DEC6383AD63A55204F \
    2CF84BADB2A8CC72EB43C64DFEB6136FE860354793ECD03598FEFC204931023E2A1B9B658B \
    826AE356826D4942B7B7AAB865E89089A10BE518E48A501194B4B4A0F8BEEDA4B19D3841E \
    B69D24F2359D02F300DBB5B71308071CD7951966C93C2D039FB46A3F0D77AFB845C92 \
    E53A657B2C23758D6707B69DEA47195D96C471A159ED9B9EAC0E9190F184F8FB2765 \
    16F5A052646285E29ACBAF91516159E1D05C2182D5CB83592ACCDDCA50BCECCA1F6B \
    D2EDDD79FB31A5B3823";

    char example_C[2000] = "308205BDA00302010202100F\
    BE08B0854D05738AB0CCE1C9AFEEC9300D06092A8648\
    86F70D01010B0500304F310B30090603550406130255\
    5331153013060355040A130C44696769436572742049\
    6E633129302706035504031320446967694365727420\
    544C5320525341205348413235362032303230204341\
    31301E170D3230313132343030303030305A170D3231\
    313232353233353935395A308190310B300906035504\
    0613025553311330110603550408130A43616C69666F\
    726E6961311430120603550407130B4C6F7320416E67\
    656C6573313C303A060355040A1333496E7465726E65\
    7420436F72706F726174696F6E20666F722041737369\
    676E6564204E616D657320616E64204E756D62657273\
    311830160603550403130F7777772E6578616D706C65\
    2E6F726730820122300D06092A864886F70D01010105\
    000382010F003082010A0282010100BAFCEECCCA0A08\
    FF0E931DB3BE0B9C0396229EB14F10AE5140FD535FB3\
    C461402804EEA2E61200B08285985C6D5B6B20844462\
    954E6B767C50705DDF131DEC6383AD63A55204F2CF84\
    BADB2A8CC72EB43C64DFEB6136FE860354793ECD03598\
    FEFC204931023E2A1B9B658B826AE356826D4942B7B7A\
    AB865E89089A10BE518E48A501194B4B4A0F8BEEDA4B19D3841EB69D24F2359D02F300DBB5B\
    71308071CD7951966C93C2D039FB46A3F0D77AFB845C92E53A657B2C23758D6707B69DEA471\
    95D96C471A159ED9B9EAC0E9190F184F8FB276516F5A052646285E29ACBAF91516159E1D05C\
    2182D5CB83592ACCDDCA50BCECCA1F6BD2EDDD79FB31A5B38230203010001A3820369308203\
    65301F0603551D23041830168014B76BA2EAA8AA848C79EAB4DA0F98B2C59576B9F4301D060\
    3551D0E04160414261AF8E4B1B07284CEDA8106D22798FBED3A3D173081810603551D11047A\
    3078820F7777772E6578616D706C652E6F7267820B6578616D706C652E636F6D820B6578616\
    D706C652E656475820B6578616D706C652E6E6574820B6578616D706C652E6F7267820F7777\
    772E6578616D706C652E636F6D820F7777772E6578616D706C652E656475820F7777772E657\
    8616D706C652E6E6574300E0603551D0F0101FF0404030205A0301D0603551D250416301406\
    082B0601050507030106082B0601050507030230818B0603551D1F048183308180303EA03CA\
    03A8638687474703A2F2F63726C332E64696769636572742E636F6D2F446967694365727454\
    4C53525341534841323536323032304341312E63726C303EA03CA03A8638687474703A2F2F6\
    3726C342E64696769636572742E636F6D2F4469676943657274544C53525341534841323536\
    323032304341312E63726C304C0603551D2004453043303706096086480186FD6C0101302A3\
    02806082B06010505070201161C68747470733A2F2F7777772E64696769636572742E636F6D\
    2F4350533008060667810C010202307D06082B060105050701010471306F302406082B06010\
    5050730018618687474703A2F2F6F6373702E64696769636572742E636F6D304706082B0601\
    0505073002863B687474703A2F2F636163657274732E64696769636572742E636F6D2F44696\
    76943657274544C53525341534841323536323032304341312E637274300C0603551D130101\
    FF0402300030820105060A2B06010401D6790204020481F60481F300F1007700F65C942FD17\
    73022145418083094568EE34D131933BFDF0C2F200BCC4EF164E300000175FBBDD86E000004\
    0300483046022100A46BA8D043A4F107322DED9C397D77E873C19FED224A00C5BE9AC9B5B61\
    2DCB10221008DE85F8AC752CD0DA123D5B5BBDBDB62138822D670EC835E3FC9AC944C8C583A\
    0076005CDC4392FEE6AB4544B15E9AD456E61037FBD5FA47DCA17394B25EE6F6C70ECA00000\
    175FBBDD8CD000004030047304502206AAC11FA050912FF9B8E8930DF0E056ECA8E59CCEDB5\
    C20A3C3334A8B033DAAC022100DAD85C516D640AA6AA3D8B3520133A6A974F76B967CBBEFCC\
    CA45767B43F1BBD";

    char example_S[2000] = "a72a10305cb86b7a1bf86638f6e9a00ad5138282f8658957a5b8eb13291d846cecfbe30511d71e315e0ee2\
    c000e56d0648be3d556fbab71135b6eac4cf84f1304cbb339e11172bc9d2194b2cd0ad5f172384e1df17a23ba87f69297c48a6615f\
    263f75e23b5ba336b31ccde30457301ffcc9fa4b8e488058279ca2c7c326dc1702fae66cea81015c928fd3180817707ac2a34b6c3a\
    fae3cff6fe7ec956e5a54e1b144fa9989d79b11ec3abb10d1585a946b6e5c258e85afec814286890c6b8c8947fe10f89faa7d60937\
    a162b70027b5bef1b15e452806b35415e6c3c8ac8201ce86e22be17ae4bd4ccb9c5ed062c261bd8b5a62b67630bc460fe34523c0645f";

    BN_hex2bn(&C, example_C);

    BN_hex2bn(&e, example_e);

    BN_hex2bn(&n, example_n);

    BN_hex2bn(&S, example_S);

    unsignSignature(C,S,e,n);
//unsinged of google = 0112953A40000504D64AE9D22BD5F0D837AD3EB96269A2F5E7403C89
    printBN("C = ", C);

    if(BN_cmp(C, M) == 0){
        printf("Valid");
    }
    else{
        printf("Fail");
    }
    //deallocate vars if it becomes a problem

return 0;
}
