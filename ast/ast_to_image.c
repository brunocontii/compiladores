#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ast.h"

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

const char* getTypeString(Type type) {
    switch(type) {
        case INTEGER: return "INTEGER";
        case BOOLEAN: return "BOOLEAN";
        case TYPE_VOID:    return "VOID";
        default:      return "UNKNOWN";
    }
}

void getNodeValueString(Node* node, char* buffer, size_t bufsize) {
    if (!node || !node->info) {
        snprintf(buffer, bufsize, "?");
        return;
    }
    
    char temp[256] = "";
    bool first = true;
    
    if (node->info->name) {
        if (!first) strcat(temp, " | ");
        strcat(temp, "name: ");
        strcat(temp, node->info->name);
        first = false;
    }
    
    if (node->info->op) {
        if (!first) strcat(temp, " | ");
        strcat(temp, "op: ");
        strcat(temp, node->info->op);
        first = false;
    }
    
    if (node->info->token == NUM) {
        if (!first) strcat(temp, " | ");
        char num_str[32];
        sprintf(num_str, "i_value: %d", node->info->i_value);
        strcat(temp, num_str);
        first = false;
    }
    
    if (node->info->token == BOOL) {
        if (!first) strcat(temp, " | ");
        char bool_str[64];
        
        if (node->info->bool_string) {
            sprintf(bool_str, "bool_string: %s | b_value: %s", 
                    node->info->bool_string, 
                    node->info->b_value ? "true" : "false");
        } else {
            sprintf(bool_str, "b_value: %s", node->info->b_value ? "true" : "false");
        }

        strcat(temp, bool_str);
        first = false;
    }
    
    if (node->info->del != 0) {
        if (!first) strcat(temp, " | ");
        char del_str[16];
        sprintf(del_str, "del: %c", node->info->del);
        strcat(temp, del_str);
        first = false;
    }
    
    if (first) {
        snprintf(temp, sizeof(temp), "%s", getTokenString(node->info->token));
    }
    
    snprintf(buffer, bufsize, "%s", temp);
}

void generateDotNodes(Node* node, FILE* file, int* nodeCount) {
    if (node == NULL) return;

    int currentId = (*nodeCount)++;
    char valueStr[256];
    getNodeValueString(node, valueStr, sizeof(valueStr));

    if (node->info->token == ID || node->info->token == NUM || node->info->token == BOOL) {
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

void generateASTDotFile(Node* root, const char* base_filename) {
    char dot_filename[256];
    char png_filename[256];
    
    // Crear nombres de archivos
    snprintf(dot_filename, sizeof(dot_filename), "%s.dot", base_filename);
    snprintf(png_filename, sizeof(png_filename), "%s.png", base_filename);
    
    FILE* file = fopen(dot_filename, "w");
    if (file == NULL) {
        printf("Error: No se pudo crear el archivo %s\n", dot_filename);
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

    printf("Archivo DOT del AST generado: %s\n", dot_filename);

    char command[1024];
    snprintf(command, sizeof(command), "dot -Tpng %s -o %s 2>/dev/null && open %s 2>/dev/null", 
                dot_filename, png_filename, png_filename);
    
    int result = system(command);
    if (result == 0) {
        printf("Imagen AST generada y abierta: %s\n", png_filename);
    } else {
        printf("Error al generar imagen. Instala: sudo apt install graphviz\n");
        printf("Ejecuta manualmente: dot -Tpng %s -o %s\n", dot_filename, png_filename);
    }
}