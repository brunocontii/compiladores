#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

Node* createTree(Info info, Node* left, Node* right) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->info = info;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* createLeaf(Info info) {
    return createTree(info, NULL, NULL);
}

int main() {
    // gcc -o ast ast.c ast_to_image.c

    // Nivel 4
    Info node4_info;
    node4_info.i_value = 20;
    node4_info.token = NUM; // Token NUM
    node4_info.type = INTEGER; // Type INTEGER
    Node* node4 = createLeaf(node4_info);

    Info node5_info;
    node5_info.i_value = 45;
    node5_info.token = NUM; // Token NUM
    node5_info.type = INTEGER; // Type INTEGER
    Node* node5 = createLeaf(node5_info);

    // Nivel 3
    Info node3_info;
    node3_info.op = '+'; // OP_MAS
    node3_info.token = OP; // Token OP
    Node* node3 = createTree(node3_info, node4, node5);

    // Nivel 2
    Info node2_info;
    node2_info.i_value = 6;
    node2_info.token = NUM; // Token NUM
    node2_info.type = INTEGER; // Type INTEGER
    Node* node2 = createTree(node2_info, NULL, NULL);

    // Nivel 1 (Raíz)
    Info root_info;
    root_info.op = '*'; // OP_MULT
    root_info.token = OP; // Token OP
    Node* root = createTree(root_info, node2, node3);

    generateDotFile(root, "ast_to_image.dot");

    printf("Generando imagen PNG...\n");
    int result = system("dot -Tpng ast_to_image.dot -o ast_to_image.png");
    
    if (result == 0) {
        printf("Imagen generada exitosamente: ast_to_image.png\n");
        printf("Abriendo imagen...\n");
        system("open ast_to_image.png");
    } else {
        printf("Error al generar la imagen.\n");
    }

}

