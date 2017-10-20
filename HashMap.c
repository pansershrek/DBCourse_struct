#include "HashMap.h"
#include "AVLnode.h"


int32_t __hash_remake(hm_node_ptr node, uint32_t index);
int32_t __hash_insert_avl_in_hash(hm_node_ptr node, avlnode_ptr go);

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
    if (!node) {
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
int32_t hash_insert(hm_node_ptr node, str_t key, void *page) {
    if (!node) {
        return -1;
    }
    int32_t mid_key = hash(key, node->dep);
    while (node->len_of_list[mid_key] > MAX_HASH_DEP) {
        node = node->top[mid_key];
        mid_key = hash(key, node->dep);
    }
    node->len_of_list[mid_key]++;
    avlnode_ptr new_avl_node;
    avl_new_node(&new_avl_node, key, page);
    avl_insert_node(node->top[mid_key], new_avl_node);
    __hash_remake(node);
    return 1;
}
int32_t hash_delete(hm_node_ptr node, str_t key) {
    node = hash_search(node, key);
    if (!node) {
        return 0;
    }
    int32_t mid_key = hash(key, node->dep);
    avlnode_ptr new_avl_node;
    avl_new_node(&new_avl_node, key, NULL);
    avl_remove_node(node->top[mid_key], new_avl_node);
    return 1;
}


int32_t __hash_remake(hm_node_ptr node, uint32_t index) {
    //if == then it is flag that make new hash, if > that it is hash
    if (node->len_of_list[index] != MAX_HASH_DEP) {
        return 0;
    } 
    hm_node_ptr new_node;
    hash_new_node(&new_node, node->dep+1);
    avlnode_ptr go = node->top[index];
    __hash_insert_avl_in_hash(new_node, go);
    node->top[index] = new_node;
    node->len_of_list[index]++;
    return 1;
}
int32_t __hash_insert_avl_in_hash(hm_node_ptr node, avlnode_ptr go) {
    if (!go) {
        return 0;
    }
    if (go->left) {
        __hash_insert_avl_frm(go->left);
    }
    if (go->right) {
        __hash_insert_avl_frm(go->right);
    }
    if (go->parent) {
        if (go->parent->left == go) {
            go->parent->left = NULL;
        } else {
            go->parent->right = NULL;
        }
    }
    __avl_calc_hight(go->parent);
    __avl_rebalance(go->parent);
    go->parent = NULL;
    __avl_calc_hight(go);
    __avl_rebalance(go);
    int32_t mid_key = hash(go->key, node->dep);
    node->len_of_list[mid_key]++;
    avl_insert_node(node->top[mid_key], go);
    return 1;
}