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
        printf("The symbol table is empty, there is no item to search for.\n");
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
