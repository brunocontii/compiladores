#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ast.h"

// Devuelve el string del enum Token
const char* getTokenString(Token token) {
    switch(token) {
        case INT: return "T_INT";
        case BOOL: return "T_BOOL";
        case T_VOID: return "T_VOID";
        case MAIN: return "T_MAIN";
        case RETURN: return "T_RETURN";
        case NUM: return "T_NUM";
        case ID: return "T_ID";
        case OP: return "T_OP";
        case DEL: return "T_DEL";
        case SENTENS: return "T_SENTENS";
        case DECS: return "T_DECS";
        case DEC: return "T_DEC";
        default: return "UNKNOWN";
    }
}

// Devuelve el string del enum Type
const char* getTypeString(Type type) {
    switch(type) {
        case INTEGER: return "INTEGER";
        case BOOLEAN: return "BOOLEAN";
        case TYPE_VOID:    return "VOID";
        default:      return "UNKNOWN";
    }
}

// Devuelve el string del valor del nodo según el token
void getNodeValueString(Node* node, char* buffer, size_t bufsize) {
    if (!node) {
        snprintf(buffer, bufsize, "?");
        return;
    }
    switch(node->info->token) {
        case NUM:
            snprintf(buffer, bufsize, "%d", node->info->i_value);
            break;
        case BOOL:
            snprintf(buffer, bufsize, "%s", node->info->b_value ? "true" : "false");
            break;
        case ID:
            snprintf(buffer, bufsize, "%s", node->info->name ? node->info->name : "");
            break;
        case INT:
            snprintf(buffer, bufsize, "%s", node->info->name ? node->info->name : "");
            break;
        case T_VOID:
            snprintf(buffer, bufsize, "%s", node->info->name ? node->info->name : "");
            break;
        case MAIN:
            snprintf(buffer, bufsize, "%s", node->info->name ? node->info->name : "");
            break;
        case RETURN:
            snprintf(buffer, bufsize, "%s", node->info->name ? node->info->name : "");
            break;
        case SENTENS:
            snprintf(buffer, bufsize, "%s", node->info->name ? node->info->name : "");
            break;
        case DECS:
            snprintf(buffer, bufsize, "%s", node->info->name ? node->info->name : "");
            break;
        case DEC:
            snprintf(buffer, bufsize, "%s", node->info->name ? node->info->name : "");
            break;
        case OP:
            snprintf(buffer, bufsize, "%s", node->info->op);
            break;
        case DEL:
            snprintf(buffer, bufsize, "%c", node->info->del);
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

    // Etiqueta: valor\n(Token)\n[Type si aplica]
    if (node->info->token == ID || node->info->token == NUM) {
        fprintf(file, "  node%d [label=\"%s\\n(%s)\\n[%s]\", shape=box];\n",
            currentId, valueStr, getTokenString(node->info->token), getTypeString(node->info->type));
    } else {
        fprintf(file, "  node%d [label=\"%s\\n(%s)\", shape=box];\n",
            currentId, valueStr, getTokenString(node->info->token));
    }

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