#pragma once

// �Ϲ� ���� Ʈ�� ���
typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

// ������ ���� Ʈ�� ���
typedef struct ThreadNode {
    int data;
    struct ThreadNode* left, * right;
    int lthread, rthread;
} ThreadNode;

// ���� Ž�� Ʈ�� 
extern TreeNode* GenerateBinaryTree(int inputData[], int size);

// ���� Ž�� Ʈ�� ���� ��ȸ 
extern void BinaryTreeInOrder(TreeNode* root);

// ������ ���� Ʈ��
extern ThreadNode* GenerateThreadTree(int inputData[], int size);

// ������ ���� Ʈ�� ���� ��ȸ
extern void ThreadTreeInOrder(ThreadNode* root);
