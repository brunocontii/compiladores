#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "table_symbols.h"

// Funciones externas para convertir enums a strings
extern const char* getTokenString(Token token);
extern const char* getTypeString(Type type);

/**
 * Imprime toda la información de un símbolo en la consola
 * Muestra nombre, token, tipo, valores, operadores, etc.
 */
void printInfo(const Info* info) {
    if (!info) return;
    printf("{ ");
    if (info->name) printf("name: \"%s\", ", info->name);
    printf("token: %s, ", getTokenString(info->token));
    printf("type: %s, ", getTypeString(info->type));
    if (info->token == NUM) printf("i_value: %d, ", info->i_value);
    if (info->token == BOOL) {
        if (info->bool_string) printf("bool_string: %s, ", info->bool_string);
        printf("b_value: %s, ", info->b_value ? "true" : "false");
    }
    if (info->op) printf("op: '%s', ", info->op);
    if (info->del != 0) printf("del: '%c', ", info->del);
    printf("}\n");
}

/**
 * Genera el string que se mostrará como etiqueta del símbolo en la visualización
 * Incluye toda la información disponible del símbolo
 */
void getSymbolLabelString(const Info* info, char* buffer, size_t bufsize) {
    if (!info) {
        snprintf(buffer, bufsize, "NULL");
        return;
    }
    
    char temp[512] = "";
    bool first = true;
    
    // Agregar nombre del símbolo
    if (info->name) {
        strcat(temp, "name: ");
        strcat(temp, info->name);
        first = false;
    }
    
    // Agregar operador si existe
    if (info->op) {
        if (!first) strcat(temp, " | ");
        strcat(temp, "op: ");
        strcat(temp, info->op);
        first = false;
    }
    
    // Agregar valor numérico si es un número
    if (info->token == NUM) {
        if (!first) strcat(temp, " | ");
        char num_str[32];
        sprintf(num_str, "i_value: %d", info->i_value);
        strcat(temp, num_str);
        first = false;
    }
    
    // Agregar valor booleano si es un booleano
    if (info->token == BOOL) {
        if (!first) strcat(temp, " | ");
        char bool_str[64];
        if (info->bool_string) {
            sprintf(bool_str, "bool_string: %s | b_value: %s", 
                    info->bool_string, info->b_value ? "true" : "false");
        } else {
            sprintf(bool_str, "b_value: %s", info->b_value ? "true" : "false");
        }
        strcat(temp, bool_str);
        first = false;
    }
    
    // Agregar delimitador si existe
    if (info->del != 0) {
        if (!first) strcat(temp, " | ");
        char del_str[16];
        sprintf(del_str, "del: %c", info->del);
        strcat(temp, del_str);
        first = false;
    }
    
    // Si no hay información específica, usar solo el token
    if (first) {
        snprintf(temp, sizeof(temp), "%s", getTokenString(info->token));
    }
    
    // Formato final: información + token + tipo
    snprintf(buffer, bufsize, "%s\\nToken: %s\\nType: %s", 
                temp, getTokenString(info->token), getTypeString(info->type));
}

/**
 * Genera recursivamente los nodos de la tabla de símbolos en formato DOT
 * Recorre la lista enlazada y crea la representación visual
 */
void generateSymbolDotNodes(const Symbol* ts, FILE* file, int* nodeCount) {
    if (!ts) return;
    
    int currentId = (*nodeCount)++;
    char labelStr[512];
    getSymbolLabelString(ts->info, labelStr, sizeof(labelStr));
    
    // Crear el nodo con la información del símbolo
    fprintf(file, "  node%d [label=\"%s\", shape=record, style=filled, fillcolor=lightblue];\n",
            currentId, labelStr);
    
    // Si hay un siguiente símbolo, generar enlace
    if (ts->next) {
        int nextId = *nodeCount;
        generateSymbolDotNodes(ts->next, file, nodeCount);  // Procesar siguiente símbolo
        fprintf(file, "  node%d -> node%d [label=\"next\", color=blue];\n", currentId, nextId);
    }
}

/**
 * Función principal que genera el archivo DOT y la imagen PNG de la tabla de símbolos
 * Crea archivos .dot y .png para visualizar la tabla como lista enlazada
 */
void generateTSDotFile(const Symbol* ts, const char* base_filename) {
    char dot_filename[256];
    char png_filename[256];

    // Crear nombres de archivos con extensiones
    snprintf(dot_filename, sizeof(dot_filename), "%s.dot", base_filename);
    snprintf(png_filename, sizeof(png_filename), "%s.png", base_filename);

    FILE* file = fopen(dot_filename, "w");
    if (!file) {
        printf("Error: No se pudo crear el archivo %s\n", dot_filename);
        return;
    }

    // Escribir cabecera del archivo DOT
    fprintf(file, "digraph SymbolTable {\n"
                    "  rankdir=LR;\n"                    // Dirección: izquierda a derecha
                    "  node [fontname=\"Arial\", fontsize=10];\n"
                    "  edge [fontname=\"Arial\", fontsize=10];\n");

    if (!ts) {
        // Tabla vacía
        fprintf(file, "  empty [label=\"Tabla vacía\", shape=plaintext, fontsize=14];\n");
    } else {
        // Generar todos los nodos de la tabla
        int nodeCount = 0;
        generateSymbolDotNodes(ts, file, &nodeCount);
        
        // Agregar título a la visualización
        fprintf(file, "  title [label=\"Tabla de Símbolos\", shape=plaintext, fontsize=16, fontweight=bold];\n"
                        "  title -> node0 [style=invisible];\n");
    }

    fprintf(file, "}\n");
    fclose(file);
    printf("Archivo DOT de la TS generado: %s\n", dot_filename);

    // Intentar generar la imagen PNG usando Graphviz
    char command[1024];
    snprintf(command, sizeof(command), "dot -Tpng %s -o %s 2>/dev/null && xdg-open %s 2>/dev/null", 
                dot_filename, png_filename, png_filename);
    
    if (system(command) != 0) {
        printf("Error generando imagen. Instala: sudo apt install graphviz\n");
        printf("Ejecuta manualmente: dot -Tpng %s -o %s\n", dot_filename, png_filename);
    } else {
        printf("Tabla de símbolos generada: %s\n", png_filename);
    }
}