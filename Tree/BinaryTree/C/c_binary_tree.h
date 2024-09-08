#pragma once
typedef struct Node {
    void* data;
    struct Node* left;
    struct Node* rifht;
} Node;


struct Node* newNode(void* data, size_t data_size);
void inorderTraversal(struct Node* root);
struct Node* insert(struct Node* root, void* data, size_t data_size);
void freeTree(struct Node* root);

class BinaryTree
{
};
