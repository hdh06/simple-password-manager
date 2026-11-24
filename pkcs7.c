#include "pkcs7.h"

// replace string s with padded string and return size
size_t pkcs7_pad(char **s, size_t len) {
    int pad_num = 0;

    if (len % BLOCK_SIZE == 0)
        pad_num = BLOCK_SIZE;
    else 
        pad_num = (BLOCK_SIZE - len % BLOCK_SIZE);

    size_t new_len = len + pad_num;
    
    *s = realloc(*s, new_len * sizeof(**s));

    for (int i = len; i < new_len;  i++) {
        (*s)[i] = pad_num;
    }
    return new_len;
}

size_t pkcs7_unpad(char **s, size_t len) {
    if (!len || len % BLOCK_SIZE != 0) {
        // padded string must not be empty and divided by BLOCK_SIZE
        return -1; 
    }

    char pad_byte = (*s)[len - 1]; 
    if (!pad_byte) {
        // pad_byte = NULL, not valid
        return -1;
    }

    // check if padding valid
    for (char i = len - 1; i > len - 1 - pad_byte; i--) {
        if (*((*s) + i) != pad_byte) {
            return -1;
        }
    }

    size_t new_len = len - pad_byte;

    *s = realloc(*s, new_len * sizeof(**s));

    return new_len;
}
