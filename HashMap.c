#include "HashMap.h"


int32_t new_node(ht_node_ptr *node,uint32_t dep) {
    //create new hash table
    (*in) = (ht_node*) malloc(sizeof(ht_node));
    if (!(*in)) {
        return -1;
    }
    (*node)->dep = dep;
    return 0;
}