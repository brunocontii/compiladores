#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table_symbols.h"
#include "symbol_to_image.h"

Symbol* createSymbol(Info *info) {
    Symbol* ts = (Symbol*)malloc(sizeof(Symbol));
    if (ts == NULL) {
        fprintf(stderr, "Error allocating memory for Symbol\n");
        exit(EXIT_FAILURE);
    }
    ts->info = info;
    ts->next = NULL;
    printf("Created new symbol: %s\n", info->name);
    return ts;
}

Symbol* insertByName(Symbol* ts, Info *info) {
    if (ts == NULL) {
        return createSymbol(info);
    }
    Symbol* aux = ts;
    while (aux != NULL) {
        if (aux->info->name && info->name && strcmp(aux->info->name, info->name) == 0) {
            fprintf(stderr, "Error: Symbol with name '%s' already exists.\n", info->name);
            return ts;
        }
        if (aux->next == NULL) {
            break;
        }
        aux = aux->next;
    }
    Symbol* new_symbol = createSymbol(info);
    aux->next = new_symbol;
    printf("Inserted symbol: %s\n", info->name);
    return ts;
}

Info* searchByName(Symbol* ts, char* name) {
    if (ts == NULL) {
        printf("Error: Symbol table is empty.\n");
        return NULL;
    }
    Symbol* aux = ts;
    while (aux != NULL) {
        if (aux->info->name && name && strcmp(aux->info->name, name) == 0) {
            return aux->info;
        }
        aux = aux->next;
    }
    printf("Error: Symbol with name '%s' not found.\n", name);
    return NULL;
}

int main() {
    // gcc -o table_symbols table_symbols.c symbol_printer.c symbol_to_image.c
    Symbol* tabla = NULL;

    // Crear símbolos de ejemplo
    Info* info1 = (Info*)malloc(sizeof(Info));
    info1->name = strdup("x");
    info1->token = ID;
    info1->type = INTEGER;
    info1->i_value = 10;

    Info* info2 = (Info*)malloc(sizeof(Info));
    info2->name = strdup("y");
    info2->token = ID;
    info2->type = BOOLEAN;
    info2->b_value = 1;

    Info* info3 = (Info*)malloc(sizeof(Info));
    info3->name = strdup("sum");
    info3->token = NUM;
    info3->type = INTEGER;
    info3->i_value = 42;

    tabla = insertByName(tabla, info1);
    tabla = insertByName(tabla, info2);
    tabla = insertByName(tabla, info3);

    generateAndOpenSymbolTable(tabla, "symbol_table");

    Info* buscado = searchByName(tabla, "y");
    if (buscado) {
        printf("Símbolo encontrado:\n");
        printInfo(buscado);
    }

    Info* buscado2 = searchByName(tabla, "noExiste");
    if (buscado2) {
        printf("Símbolo encontrado:\n");
        printInfo(buscado2);
    }

    return 0;
}