#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

/**
 * Crea un nuevo nodo del AST con la información dada y sus hijos izquierdo y derecho
 */
Node* createTree(Info *info, Node* left, Node* right) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL; // Error al asignar memoria
    }
    newNode->info = info;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

/**
 * Crea un nodo hoja (sin hijos) con la información dada
 */
Node* createLeaf(Info *info) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL; // Error al asignar memoria
    }
    newNode->info = info;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * Busca en el AST el primer nodo que tenga el token especificado
 * Recorre el árbol en profundidad: nodo actual -> izquierda -> derecha
 */
Node* searchNodeByToken(Node* root, Token token) {
    if (root == NULL) {
        return NULL; // Árbol vacío o llegamos al final
    }
    
    // Verificar si el nodo actual tiene el token que buscamos
    if (root->info->token == token) {
        return root;
    }
    
    // Buscar primero en el subárbol izquierdo
    Node* resultLeft = searchNodeByToken(root->left, token);
    if (resultLeft != NULL) {
        return resultLeft; // Encontrado en la izquierda
    }
    
    // Si no está en la izquierda, buscar en la derecha
    return searchNodeByToken(root->right, token);
}