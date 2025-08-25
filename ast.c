#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

Node* createTree(Info info, InfoType info_type, Node* left, Node* right) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->info = info;
    newNode->info_type = info_type;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* createLeaf(Info info, InfoType info_type) {
    return createTree(info, info_type, NULL, NULL);
}

// int main() {
//     // gcc -o ast ast.c ast_to_image.c

//     // Nivel 4
//     Info node4_info = { .i_value = 20 }; // NUM
//     InfoType node4_info_type = NUM;
//     Node* node4 = createLeaf(node4_info, node4_info_type);

//     Info node5_info = { .i_value = 45 }; // NUM
//     InfoType node5_info_type = NUM;
//     Node* node5 = createLeaf(node5_info, node5_info_type);

//     // Nivel 3
//     Info node3_info = { .op = '+' }; // OP_MAS
//     InfoType node3_info_type = OP;
//     Node* node3 = createTree(node3_info, node3_info_type, node4, node5);

//     // Nivel 2
//     Info node2_info = { .i_value = 6 }; // NUM
//     InfoType node2_info_type = NUM;
//     Node* node2 = createTree(node2_info, node2_info_type, NULL, NULL);

//     // Nivel 1 (Raíz)
//     Info root_info = { .op = '*' }; // OP_MULT
//     InfoType root_info_type = OP;
//     Node* root = createTree(root_info, root_info_type, node2, node3);

//     generateDotFile(root, "ast_to_image.dot");

//     printf("Generando imagen PNG...\n");
//     int result = system("dot -Tpng ast_to_image.dot -o ast_to_image.png");
    
//     if (result == 0) {
//         printf("Imagen generada exitosamente: ast_to_image.png\n");
//         printf("Abriendo imagen...\n");
//         system("open ast_to_image.png");
//     } else {
//         printf("Error al generar la imagen.\n");
//     }

// }

