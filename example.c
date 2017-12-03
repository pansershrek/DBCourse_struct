// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <stdio.h>
#include "HashMap.h"

int main(void) {
    hm_node_ptr mapa;           // this is my hashmap
    hash_new_node(&mapa, 1);     // here I initialize it, were 2-nd number is a deep of hashmap
    for (int i = 0; i < 20; i++) {
        str_t key;
        key.size = i + 1;
        hash_insert(mapa, key, NULL); // here I insert into hashmap `mapa` pair KEY => key, PAGE => NULL
    }
    str_t key;
    key.size = 10;
    avlnode_ptr node;
    node = hash_search(mapa, key); // here I search through hashmap `mapa` KEY => key;

    hash_delete(mapa, key); // I delete from hashmap `mapa` KEY => key;
    hash_erase(mapa);  // here I clean memory
    return 0;
}