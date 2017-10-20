#include "HashMap.h"
#include "AVLnode.h"

int32_t hash_new_node(hm_node_ptr *node, uint32_t dep) {
    //create new hash table
    (*in) = (hm_node*) malloc(sizeof(hm_node));
    if (!(*in)) {
        return -1;
    }
    (*node)->dep = dep;
    return 0;
}
hm_node_ptr hash_search(hm_node_ptr node, str_t key) {
    if (!key) {
        return NULL;
    }
    int32_t mid_key = hash(key, hash(node->dep));
    while (1) {
        if (node->len_of_list[mid_key] < MAX_HASH_DEP) {
            return avl_search(node->top[mid_key], key);
        } else {
            node = node->top[mid_key];
        }
    }
}