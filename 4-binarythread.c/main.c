#include <stdio.h>
#include "BST.h"

int main() {
    int inputData[] = { 4, 1, 9, 13, 15, 3, 6, 14, 7, 10, 12, 2, 5, 8, 11 };
    int size = sizeof(inputData) / sizeof(inputData[0]);

    // 이진 탐색 트리 생성
    TreeNode* root = GenerateBinaryTree(inputData, size);
    printf("Binary tree inorder: ");
    BinaryTreeInOrder(root);
    printf("\n");

    // 스레드 이진 트리 생성
    ThreadNode* troot = GenerateThreadTree(inputData, size);
    printf("Thread tree inorder: ");
    ThreadTreeInOrder(troot);
    printf("\n");

    // 메모리 해제
    free(root);
    free(troot);

    return 0;
}