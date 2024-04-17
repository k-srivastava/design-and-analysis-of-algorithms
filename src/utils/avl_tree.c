// #include "avl_tree.h"
//
// bt_node_t* rotate_right(bt_node_t* root)
// {
//     bt_node_t* root_left = root->left;
//     bt_node_t* right_subchild = root_left->right;
//
//     root_left->right = root;
//     root->left = right_subchild;
//
//     return root_left;
// }
//
// bt_node_t* rotate_left(bt_node_t* root)
// {
//     bt_node_t* root_right = root->right;
//     bt_node_t* left_subchild = root_right->left;
//
//     root_right->left = root;
//     root->right = left_subchild;
//
//     return root_right;
// }
//
// bt_node_t* insert_into_avl_tree(bt_node_t* root, const int data)
// {
//     if (root == NULL) { return init_bt_node(data, NULL, NULL); }
//
//     if (data < root->data) { root->left = insert_into_avl_tree(root->left, data); }
//     else if (data > root->data) { root->right = insert_into_avl_tree(root->right, data); }
//     else { return root; }
//
//     const int balance_factor = get_node_balance_factor(root);
//
//     if (balance_factor > 1 && data < root->left->data) { return rotate_right(root); }
//     if (balance_factor < -1 && data > root->right->data) { return rotate_left(root); }
//
//     if (balance_factor > 1 && data > root->left->data)
//     {
//         root->left = rotate_left(root->left);
//         return rotate_right(root);
//     }
//
//     if (balance_factor < -1 && data < root->right->data)
//     {
//         root->right = rotate_right(root->right);
//         return rotate_left(root);
//     }
//
//     return root;
// }
//
// // int get_node_balance_factor(const bt_node_t* node)
// // {
// //     if (node == NULL) { return 0; }
// //     return get_node_height(node->left) - get_node_height(node->right);
// // }
