#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_symbols.h"

const char* getTokenStringTable(Token token) {
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

const char* getTypeStringTable(Type type) {
    switch(type) {
        case INTEGER: return "INTEGER";
        case BOOLEAN: return "BOOLEAN";
        case TYPE_VOID: return "VOID";
        default: return "UNKNOWN";
    }
}

void printInfo(const Info* info) {
    if (!info) return;
    printf("{ ");
    if (info->name) printf("name: \"%s\", ", info->name);
    printf("token: %s, ", getTokenStringTable(info->token));
    printf("type: %s, ", getTypeStringTable(info->type));
    if (info->token == NUM) printf("i_value: %d, ", info->i_value);
    if (info->token == BOOL) printf("b_value: %s, ", info->b_value ? "true" : "false");
    if (info->token == OP) printf("op: '%s', ", info->op);
    if (info->token == DEL) printf("del: '%c', ", info->del);
    printf("}\n");
}

// Genera el contenido de la etiqueta para un nodo de la tabla de símbolos
void getSymbolLabelString(const Info* info, char* buffer, size_t bufsize) {
    if (!info) {
        snprintf(buffer, bufsize, "NULL");
        return;
    }
    
    char value_part[128] = "";
    
    // Generar la parte del valor según el token
    switch(info->token) {
        case NUM:
            snprintf(value_part, sizeof(value_part), "Value: %d", info->i_value);
            break;
        case BOOL:
            snprintf(value_part, sizeof(value_part), "Value: %s", info->b_value ? "true" : "false");
            break;
        case OP:
            snprintf(value_part, sizeof(value_part), "Op: '%s'", info->op);
            break;
        case DEL:
            snprintf(value_part, sizeof(value_part), "Del: '%c'", info->del);
            break;
        case ID:
            snprintf(value_part, sizeof(value_part), "Name: '%s'", info->name);
            break;
        case INT:
            snprintf(value_part, sizeof(value_part), "Name: %s", info->name);
            break;
        case T_VOID:
            snprintf(value_part, sizeof(value_part), "Name: '%s'", info->name);
            break;
        case MAIN:
            snprintf(value_part, sizeof(value_part), "Name: '%s'", info->name);
            break;
        case RETURN:
            snprintf(value_part, sizeof(value_part), "Name: '%s'", info->name);
            break;
        case SENTENS:
            snprintf(value_part, sizeof(value_part), "Name: '%s'", info->name);
            break;
        case DECS:
            snprintf(value_part, sizeof(value_part), "Name: '%s'", info->name);
            break;
        case DEC:
        default:
            // Para estos casos, el valor principal es el nombre
            if (info->name) {
                snprintf(value_part, sizeof(value_part), "Name: %s", info->name);
            } else {
                snprintf(value_part, sizeof(value_part), "No name");
            }
            break;
    }
    
    // Crear la etiqueta completa
    if (info->name && (info->token == NUM || info->token == BOOL || info->token == OP || info->token == DEL)) {
        // Para tokens con valor especial, mostrar tanto nombre como valor
        snprintf(buffer, bufsize, "%s\\n%s\\nToken: %s\\nType: %s", 
                 info->name, value_part, getTokenStringTable(info->token), getTypeStringTable(info->type));
    } else {
        // Para otros tokens, mostrar solo el valor principal
        snprintf(buffer, bufsize, "%s\\nToken: %s\\nType: %s", 
                 value_part, getTokenStringTable(info->token), getTypeStringTable(info->type));
    }
}

// Genera los nodos DOT para la tabla de símbolos
void generateSymbolDotNodes(const Symbol* ts, FILE* file, int* nodeCount) {
    if (ts == NULL) return;
    
    int currentId = (*nodeCount)++;
    char labelStr[256];
    getSymbolLabelString(ts->info, labelStr, sizeof(labelStr));
    
    // Crear el nodo con estilo específico para tabla de símbolos
    fprintf(file, "  node%d [label=\"%s\", shape=record, style=filled, fillcolor=lightblue];\n",
            currentId, labelStr);
    
    // Si hay siguiente nodo, crear la conexión
    if (ts->next != NULL) {
        int nextId = *nodeCount;
        generateSymbolDotNodes(ts->next, file, nodeCount);
        fprintf(file, "  node%d -> node%d [label=\"next\", color=blue];\n", currentId, nextId);
    }
}

// Función principal para generar archivo DOT de la tabla de símbolos
void generateSymbolTableDotFile(const Symbol* ts, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: No se pudo crear el archivo %s\n", filename);
        return;
    }
    
    fprintf(file, "digraph SymbolTable {\n");
    fprintf(file, "  rankdir=LR;\n");  // Horizontal para listas enlazadas
    fprintf(file, "  node [fontname=\"Arial\", fontsize=10];\n");
    fprintf(file, "  edge [fontname=\"Arial\", fontsize=10];\n");
    
    if (ts == NULL) {
        fprintf(file, "  empty [label=\"Tabla vacía\", shape=plaintext, fontsize=14];\n");
    } else {
        int nodeCount = 0;
        generateSymbolDotNodes(ts, file, &nodeCount);
        
        // Agregar título
        fprintf(file, "  title [label=\"Tabla de Símbolos\", shape=plaintext, fontsize=16, fontweight=bold];\n");
        fprintf(file, "  title -> node0 [style=invisible];\n");
    }
    
    fprintf(file, "}\n");
    fclose(file);
    
    printf("Archivo DOT de tabla de símbolos generado: %s\n", filename);
    printf("Para generar imagen PNG: dot -Tpng %s -o %s.png\n", filename, filename);
    printf("Para generar imagen SVG: dot -Tsvg %s -o %s.svg\n", filename, filename);
}

// Función todo-en-uno: genera DOT, crea imagen PNG y la abre automáticamente
void generateAndOpenSymbolTable(const Symbol* ts, const char* base_filename) {
    char dot_filename[256];
    char png_filename[256];
    char command[1024];
    
    // Generar nombres de archivos
    snprintf(dot_filename, sizeof(dot_filename), "%s.dot", base_filename);
    snprintf(png_filename, sizeof(png_filename), "%s.png", base_filename);
    
    printf("=== GENERANDO VISUALIZACIÓN ===\n");
    
    // Paso 1: Generar archivo DOT
    FILE* file = fopen(dot_filename, "w");
    if (file == NULL) {
        printf("Error: No se pudo crear el archivo %s\n", dot_filename);
        return;
    }
    
    fprintf(file, "digraph SymbolTable {\n");
    fprintf(file, "  rankdir=LR;\n");
    fprintf(file, "  node [fontname=\"Arial\", fontsize=10];\n");
    fprintf(file, "  edge [fontname=\"Arial\", fontsize=10];\n");
    
    if (ts == NULL) {
        fprintf(file, "  empty [label=\"Tabla vacía\", shape=plaintext, fontsize=14];\n");
    } else {
        int nodeCount = 0;
        generateSymbolDotNodes(ts, file, &nodeCount);
        
        fprintf(file, "  title [label=\"Tabla de Símbolos\", shape=plaintext, fontsize=16, fontweight=bold];\n");
        fprintf(file, "  title -> node0 [style=invisible];\n");
    }
    
    fprintf(file, "}\n");
    fclose(file);
    printf("Archivo DOT generado: %s\n", dot_filename);
    
    // Paso 2: Generar imagen PNG
    snprintf(command, sizeof(command), "dot -Tpng %s -o %s 2>/dev/null", dot_filename, png_filename);
    int result = system(command);
    
    if (result != 0) {
        printf("Error: No se pudo generar la imagen PNG.\n");
        printf("Instala Graphviz: sudo apt install graphviz\n");
        printf("Y ejecuta: dot -Tpng %s -o %s\n", dot_filename, png_filename);
        return;
    }
    printf("Imagen PNG generada: %s\n", png_filename);
    
    // Paso 3: Abrir la imagen automáticamente
    printf("Abriendo imagen...\n");
    
#ifdef __APPLE__
    // macOS
    snprintf(command, sizeof(command), "open %s", png_filename);
#elif __linux__
    // Linux
    snprintf(command, sizeof(command), "xdg-open %s 2>/dev/null", png_filename);
#elif _WIN32
    // Windows
    snprintf(command, sizeof(command), "start %s", png_filename);
#else
    // Sistema desconocido - intentar xdg-open
    snprintf(command, sizeof(command), "xdg-open %s 2>/dev/null", png_filename);
#endif
    
    int open_result = system(command);
    if (open_result == 0) {
        printf("Imagen abierta en el visor predeterminado\n");
    } else {
        printf("No se pudo abrir automáticamente la imagen\n");
        printf("Abre manualmente: %s\n", png_filename);
    }
    
    printf("=== PROCESO COMPLETADO ===\n");
}