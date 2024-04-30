#include "BTree.h"


void insert(btree*& root, int key) {

}


void remove(btree*& root, int key) {
    
}

btree* find(btree* root, int key) {
    if (root == NULL)
    return NULL;
    
    int i = 0;
    while (i < root->num_keys && key > root->keys[i])
        i++;    
    if (i < root->num_keys && key == root->keys[i])
        return root;
    if (root->is_leaf)
        return NULL;
    return find(root->children[i], key);

}

int count_nodes(btree* root) {
    if (root == NULL)
        return 0;
    
    int count = 1;
    for (int i = 0; i < root->num_keys + 1; ++i)
        count += count_nodes(root->children[i]);
    return count;
}

int count_keys(btree* root) {
    if (root == NULL)
        return 0;
    int count = root->num_keys;
    for (int i = 0; i < root->num_keys + 1; ++i)
        count += count_keys(root->children[i]);
    return count;
}