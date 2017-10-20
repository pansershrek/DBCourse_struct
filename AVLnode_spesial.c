#include "AVLnode.h"

int32_t key_comp(str_t key_first, str_t key_second) {
    if (key_first.size - key_second.size) {
        return key_first.size - key_second.size;
    }
    return strcmp(key_first.ptr,key_second.ptr);
}
int32_t max_32t(int32_t first, int32_t second) {
    return (first > second) ? first : second;
}