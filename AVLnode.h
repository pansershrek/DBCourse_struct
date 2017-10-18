#include <stdint.h>
#include <stdlib.h>

typedef 
{ 
    uint32_t size; 
    char * ptr; 
} str_t;
typedef struct AVLNode
{
    str_t key;
    void *page;
    struct AVLNode *left,*right,*parent;
    int32_t hight;
} avlnode;
typedef avlnode *avlnode_ptr;

int32_t key_comp(str_t key_first, str_t key_second) {
    if (key_first.size - key_second.size) {
        return key_first.size - key_second.size;
    }
    return strcmp(key_first.ptr,key_second.ptr);
}
int32_t max_32t(int32_t first, int32_t second){
    return (first > second) ? first : second;
}
int32_t avl_new_node(avlnode_ptr new_node, str_t key);
avlnode_ptr avl_search(avlnode_ptr node, str_t key);
int32_t avl_insert_node(avlnode_ptr *node, avlnode_ptr node_new);
int32_t avl_remove_node(avlnode_ptr *node, avlnode_ptr node_new);