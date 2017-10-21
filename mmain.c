// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//#pragma once
#include <stdio.h>
#include "HashMap.h"

int main(void) {
    hm_node_ptr mapa;
    hash_new_node(&mapa,1);
    for (int i = 0; i < 20; i++) {
        str_t key;
        key.size = i + 1;
        hash_test_insert(mapa, key, NULL);
    }
    str_t key;
    key.size = 10;
    avlnode_ptr node;
    node = hash_test_search(mapa, key);
    
    hash_test_delete(mapa, key);
    hash_test_print(mapa);
    /*avlnode_ptr top = NULL;
    for (int i = 0; i < 20; i++) {
        avlnode_ptr node;
        str_t key;
        key.size = i;
        avl_new_node(&node, key, NULL);
        avl_insert_node(&top, node);
    }
    avlnode_ptr node;
    str_t key;
    key.size = 18;
    avl_new_node(&node, key, NULL);
    avl_test_remove_node(&top, node);
    printf("BEGIN INPUT\n\n");
    avl_test_print(top, 1);
    //__avl_erase(top);*/
    return 0;
}