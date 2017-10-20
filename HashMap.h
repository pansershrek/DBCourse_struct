#include <stdint.h>
#include <stdlib.h>


typedef 
{ 
    uint32_t size; 
    char * ptr; 
} str_t;

enum {
    MAX_HASH_NODE=1024,
    MAX_HASH_DEP=1024,
};

typedef struct HashMap  //create here hast table
-{ 
-    // if len_of_list[index]>MAX_LEN then top[index] is a ptr on new hash_table, else it is ptr on list
-    // dont forget mix hash after create new child table!!!!
-    int dep;
-    uint32_t  len_of_list[MAX_HASH_DEP]; //here i save the length of each list    
-    void  *top[MAX_HASH_NODE];  //here is my ptr on list or on hash table
-} hm_node;
typedef hm_node *hm_node_ptr;

int32_t hash (const char *key,int dep) { // dep if parametr for change const in hash f
    int32_t mid = 0, p = 57, m = 1031;
    switch (dep) {
        case 2: p = 97; m = 3089; break;
        case 3: p = 71; m = 2029; break;
        case 4: p = 107; m = 4019; break;
        case 5: p = 89; m = 6079; break;
    }
    while (*key) {
        mid = (mid + p * ((mytype)(*key))) % m;
        key++;
    }
    return mid;
}