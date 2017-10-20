#include <stdint.h>
#include <stdlib.h>
#include "AVLnode.h"

/*enum {
    MAX_KEY_LEN = 1024,
};
typedef struct keystrt
{ 
    uint32_t size; 
    char *ptr; 
} str_t;*/
enum {
    MAX_HASH_NODE = 1024,
    MAX_HASH_DEP = 1024,
};

typedef struct HashMap  //create here hast table
{ 
    // if len_of_list[index]>MAX_LEN then top[index] is a ptr on new hash_table, else it is ptr on list
    // dont forget mix hash after create new child table!!!!
    int dep;
    uint32_t  len_of_list[MAX_HASH_NODE]; //here i save the length of each list    
    void  *top[MAX_HASH_NODE];  //here is my ptr on list or on hash table
} hm_node;
typedef hm_node *hm_node_ptr;

int32_t hash (str_t key,int dep);

//local metodes
int32_t __hash_remake(hm_node_ptr node, uint32_t index);
int32_t __hash_insert_avl_in_hash(hm_node_ptr node, avlnode_ptr go);
//metodes 
