// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef TREE_DIAMETER_H
#define TREE_DIAMETER_H

#include <stddef.h>

#include "../utils/binary_tree.h"

size_t max(const size_t value_1, const size_t value_2)
{
    return value_1 > value_2 ? value_1 : value_2;
}

size_t get_bt_diameter(const bt_node_t* root, size_t* height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    size_t left_height = 0;
    const size_t left_diameter = get_bt_diameter(root->left, &left_height);

    size_t right_height = 0;
    const size_t right_diameter = get_bt_diameter(root->right, &right_height);

    *height = max(left_height, right_height) + 1;
    return max(left_height + right_height + 1, max(left_diameter, right_diameter));
}

#endif //TREE_DIAMETER_H
