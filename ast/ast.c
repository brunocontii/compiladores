#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

Node* createTree(Info *info, Node* left, Node* right) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->info = info;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* createLeaf(Info *info) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->info = info;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
