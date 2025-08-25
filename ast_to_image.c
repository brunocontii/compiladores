#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ast.h"

// Devuelve el string del tipo
const char* getTypeString(InfoType type) {
    switch(type) {
        case INT: return "INT";
        case BOOL: return "BOOL";
        case VOID: return "VOID";
        case MAIN: return "MAIN";
        case RETURN: return "RETURN";
        case NUM: return "NUM";
        case ID: return "ID";
        case OP: return "OP";
        case DEL: return "DEL";
        case SENTENS: return "SENTENS";
        case DECS: return "DECS";
        case DEC: return "DEC";
        default: return "UNKNOWN";
    }
}

// Devuelve el string del valor del nodo según el tipo
void getNodeValueString(Node* node, char* buffer, size_t bufsize) {
    switch(node->info_type) {
        case INT:
            snprintf(buffer, bufsize, "%s", node->info.name ? node->info.name : "");
            break;
        case NUM:
            snprintf(buffer, bufsize, "%d", node->info.i_value);
            break;
        case BOOL:
            snprintf(buffer, bufsize, "%s", node->info.name ? node->info.name : "");
            break;
        case ID:
            snprintf(buffer, bufsize, "%s", node->info.name ? node->info.name : "");
            break;
        case MAIN:
            snprintf(buffer, bufsize, "%s", node->info.name ? node->info.name : "");
            break;
        case RETURN:
            snprintf(buffer, bufsize, "%s", node->info.name ? node->info.name : "");
            break;
        case SENTENS:
            snprintf(buffer, bufsize, "%s", node->info.name ? node->info.name : "");
            break;
        case DECS:
            snprintf(buffer, bufsize, "%s", node->info.name ? node->info.name : "");
            break;
        case DEC:
            snprintf(buffer, bufsize, "%s", node->info.name ? node->info.name : "");
            break;
        case OP:
            snprintf(buffer, bufsize, "%c", node->info.op);
            break;
        case DEL:
            snprintf(buffer, bufsize, "%c", node->info.del);
            break;
        case VOID:
            snprintf(buffer, bufsize, "%s", node->info.name ? node->info.name : "");
            break;
        default:
            snprintf(buffer, bufsize, "?");
            break;
    }
}

// Genera los nodos DOT
void generateDotNodes(Node* node, FILE* file, int* nodeCount) {
    if (node == NULL) return;

    int currentId = (*nodeCount)++;
    char valueStr[64];
    getNodeValueString(node, valueStr, sizeof(valueStr));

    fprintf(file, "  node%d [label=\"%s\\n(%s)\", shape=box];\n",
            currentId, valueStr, getTypeString(node->info_type));

    if (node->left != NULL) {
        int leftId = *nodeCount;
        generateDotNodes(node->left, file, nodeCount);
        fprintf(file, "  node%d -> node%d [label=\"L\"];\n", currentId, leftId);
    }
    if (node->right != NULL) {
        int rightId = *nodeCount;
        generateDotNodes(node->right, file, nodeCount);
        fprintf(file, "  node%d -> node%d [label=\"R\"];\n", currentId, rightId);
    }
}

// Función principal para generar archivo DOT
void generateDotFile(Node* root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: No se pudo crear el archivo %s\n", filename);
        return;
    }

    fprintf(file, "digraph AST {\n");
    fprintf(file, "  rankdir=TB;\n");
    fprintf(file, "  node [fontname=\"Arial\"];\n");
    fprintf(file, "  edge [fontname=\"Arial\"];\n");

    if (root == NULL) {
        fprintf(file, "  empty [label=\"Árbol vacío\", shape=plaintext];\n");
    } else {
        int nodeCount = 0;
        generateDotNodes(root, file, &nodeCount);
    }

    fprintf(file, "}\n");
    fclose(file);

    printf("Archivo DOT generado: %s\n", filename);
}