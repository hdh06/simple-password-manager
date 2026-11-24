#include <stdio.h> 
#include "spm.h"
#include "pkcs7.h"

int main() {
    printf("Your password is %d\n", 4);
    int len = 4;
    char* s = (char *)malloc(sizeof(char) * len);
    s[0] = '1';
    s[1] = '2';
    s[2] = '3';
    s[3] = '4';
    len = pkcs7_pad(&s, len);
    for (int i = 0; i < len; i++) {
        printf("%02x ", s[i]);
    }
    printf("\n");

    len = pkcs7_unpad(&s, len);
    for (int i = 0; i < len; i++) {
        printf("%02x ", s[i]);
    }
    free(s);
    return 0;
}
