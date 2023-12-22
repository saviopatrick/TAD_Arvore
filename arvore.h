#ifndef ARVORE_H
#define ARVORE_H

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};


typedef struct {
    struct Node *root;
} BST;

struct Node *createNode(int value);
struct Node *insertNode(struct Node *root, int value);
int search(struct Node *root, int value);
void inorderTraversal(struct Node *root);
void destroyTree(struct Node *root);
BST createEmptyTree();
void insertElement(BST *tree, int value);
int isElementInTree(BST tree, int value);
void listElements(BST tree);
void destroyEmptyTree(BST *tree);
void removeElementFromTree(BST *tree, int value);
struct Node *removeElement(struct Node *root, int value) ;
struct Node *minValueNode(struct Node *node);

#endif

