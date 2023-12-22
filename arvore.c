#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct {
    struct Node *root;
} BST;

// Função para criar um novo nó
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    // Encontrar o nó mais à esquerda para encontrar o valor mínimo
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}


// Função para inserir um elemento na árvore
struct Node *insertNode(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}
struct Node *removeElement(struct Node *root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = removeElement(root->left, value);
    } else if (value > root->data) {
        root->right = removeElement(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        
        struct Node *temp = minValueNode(root->right);

    
        root->data = temp->data;

        
        root->right = removeElement(root->right, temp->data);
    }
    return root;
}

// Função para verificar se um elemento está na árvore
int search(struct Node *root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == value) {
        return 1;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Função para listar os elementos da árvore em ordem 
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Função para destruir a árvore
void destroyTree(struct Node *root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

// Função para criar uma árvore vazia
BST createEmptyTree() {
    BST newTree;
    newTree.root = NULL;
    return newTree;
}

// Função para inserir elemento na árvore
void insertElement(BST *tree, int value) {
    tree->root = insertNode(tree->root, value);
}

// Função para verificar se um elemento está na árvore
int isElementInTree(BST tree, int value) {
    return search(tree.root, value);
  
}

// Função para listar os elementos da árvore
void listElements(BST tree) {
    
    inorderTraversal(tree.root);
  
}

// Função para destruir a árvore vazia
void destroyEmptyTree(BST *tree) {
    destroyTree(tree->root);
    tree->root = NULL;
}
void removeElementFromTree(BST *tree, int value) {
    tree->root = removeElement(tree->root, value);
}
