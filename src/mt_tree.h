#ifndef MT_TREE_H
#define MT_TREE_H

#include "mt_pair.h"

// A Red-Black tree
typedef struct MtTree MtTree;

MtTree* mt_tree_new();

MtPair* mt_tree_search(MtTree* tree, MtString* key);

void mt_tree_traverse(MtTree* tree, bool(*fn)(MtPair*, void*), void* data);

void mt_tree_insert(MtTree* tree, MtString* key, void* value);

void mt_tree_move_pair(MtTree* tree, MtPair* pair);

void mt_tree_remove(MtTree* tree, MtString* key);

void mt_tree_clear(MtTree* tree);
void mt_tree_free(MtTree* tree);

#endif // MT_TREE_H
