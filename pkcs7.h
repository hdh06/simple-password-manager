#ifndef _PKCS7_H_
#define _PKCS7_H_
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

size_t pkcs7_pad(char **s, size_t len);
size_t pkcs7_unpad(char **s, size_t len);

#endif // _PKCS7_H_
