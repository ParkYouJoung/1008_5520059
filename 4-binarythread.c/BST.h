#pragma once

// 일반 이진 트리 노드
typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

// 스레드 이진 트리 노드
typedef struct ThreadNode {
    int data;
    struct ThreadNode* left, * right;
    int lthread, rthread;
} ThreadNode;

// 이진 탐색 트리 
extern TreeNode* GenerateBinaryTree(int inputData[], int size);

// 이진 탐색 트리 중위 순회 
extern void BinaryTreeInOrder(TreeNode* root);

// 스레드 이진 트리
extern ThreadNode* GenerateThreadTree(int inputData[], int size);

// 스레드 이진 트리 중위 순회
extern void ThreadTreeInOrder(ThreadNode* root);
