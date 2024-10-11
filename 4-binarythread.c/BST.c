#include <stdio.h>
#include <stdlib.h>
#include "BST.h"


TreeNode* insertBST(TreeNode* node, int data) {
    if (node == NULL) {
        node = (TreeNode*)malloc(sizeof(TreeNode));
        node->data = data;
        node->left = node->right = NULL;
    }
    else if (data < node->data) {
        node->left = insertBST(node->left, data);
    }
    else {
        node->right = insertBST(node->right, data);
    }
    return node;
}


TreeNode* GenerateBinaryTree(int inputData[], int size) {
    TreeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insertBST(root, inputData[i]);
    }
    return root;
}

void BinaryTreeInOrder(TreeNode* root) {
    if (root == NULL) return;
    BinaryTreeInOrder(root->left);
    printf("%d ", root->data);
    BinaryTreeInOrder(root->right);
}


ThreadNode* insertThreaded(ThreadNode* root, ThreadNode* ptr) {
    ThreadNode* parent = NULL, * current = root;

    while (current != NULL) {
        parent = current;
        if (ptr->data < current->data) {
            if (current->lthread == 0) {
                current = current->left;
            }
            else {
                break;
            }
        }
        else {
            if (current->rthread == 0) {
                current = current->right;
            }
            else {
                break;
            }
        }
    }

    if (parent == NULL) {
        root = ptr;
    }
    else if (ptr->data < parent->data) {
        ptr->left = parent->left;
        ptr->right = parent;
        parent->lthread = 0;
        parent->left = ptr;
    }
    else {
        ptr->right = parent->right;
        ptr->left = parent;
        parent->rthread = 0;
        parent->right = ptr;
    }

    return root;
}


ThreadNode* GenerateThreadTree(int inputData[], int size) {
    ThreadNode* root = NULL;
    for (int i = 0; i < size; i++) {
        ThreadNode* newNode = (ThreadNode*)malloc(sizeof(ThreadNode));
        newNode->data = inputData[i];
        newNode->lthread = 1;
        newNode->rthread = 1;
        root = insertThreaded(root, newNode);
    }
    return root;
}


ThreadNode* leftMost(ThreadNode* node) {
    if (node == NULL) return NULL;
    while (node->lthread == 0) {
        node = node->left;
    }
    return node;
}


void ThreadTreeInOrder(ThreadNode* root) {
    ThreadNode* current = leftMost(root);

    while (current != NULL) {
        printf("%d ", current->data);

        if (current->rthread == 1) {
            current = current->right;
        }
        else {
            current = leftMost(current->right);
        }
    }
}
