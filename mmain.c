// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//#pragma once
#include <stdio.h>
#include "HashMap.h"

int main(void) {
    hm_node_ptr mapa;       //this is my hashmap;
    hash_new_node(&mapa,1);     //here i initialize it, were 2 num is a deep of hasm map
    for (int i = 0; i < 20; i++) {
        str_t key;
        key.size = i + 1;
        hash_insert(mapa, key, NULL); // here i insert in hashmap MAPA with KEY => key, PAGA => NULL
    }
    str_t key;
    key.size = 10;
    avlnode_ptr node;
    node = hash_search(mapa, key); // here i search in hashmap MAPA with KEY => key;
    
    hash_delete(mapa, key); // i delete from hashmap MAPA with KEY => key;
    hash_erase(mapa);  // here i clean memory
    return 0;
}