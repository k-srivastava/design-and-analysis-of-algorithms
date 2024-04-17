// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef TREE_DIAMETER_H
#define TREE_DIAMETER_H

#include <stddef.h>

#include "../utils/binary_tree.h"
#include "../utils/utils.h"

size_t get_bt_diameter(const bt_node_t* root, size_t* height)
{
    if (root == NULL) { return 0; }

    const size_t left = get_bt_diameter(root->left, height);
    const size_t right = get_bt_diameter(root->right, height);

    *height = max(*height, left + right);
    return max(left, right) + 1;
}

#endif //TREE_DIAMETER_H
