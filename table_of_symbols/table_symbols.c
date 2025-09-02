#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "table_symbols.h"
#include "symbol_to_image.h"

/**
 * Crea un nuevo símbolo para la tabla de símbolos
 * Inicializa la estructura y asigna memoria
 */
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

/**
 * Inserta un símbolo en la tabla verificando que no exista duplicado
 * Si la tabla está vacía, crea el primer símbolo
 * Si ya existe un símbolo con el mismo nombre, muestra error
 */
Symbol* insertByName(Symbol* ts, Info *info) {
    // Si la tabla está vacía, crear el primer símbolo
    if (ts == NULL) {
        return createSymbol(info);
    }
    
    // Recorrer la lista buscando duplicados y el final
    Symbol* aux = ts;
    while (aux != NULL) {
        // Verificar si ya existe un símbolo con el mismo nombre
        if (aux->info->name && info->name && strcmp(aux->info->name, info->name) == 0) {
            fprintf(stderr, "Error: Symbol with name '%s' already exists.\n", info->name);
            return ts; // No insertar, retornar tabla sin cambios
        }
        // Si llegamos al final de la lista, salir del bucle
        if (aux->next == NULL) {
            break;
        }
        aux = aux->next;
    }
    
    // Insertar el nuevo símbolo al final de la lista
    Symbol* new_symbol = createSymbol(info);
    aux->next = new_symbol;
    printf("Inserted symbol: %s\n", info->name);
    return ts;
}

/**
 * Busca un símbolo por nombre en la tabla de símbolos
 * Recorre la lista enlazada hasta encontrar el símbolo o llegar al final
 */
Info* searchByName(Symbol* ts, char* name) {
    if (ts == NULL) {
        printf("The symbol table is empty, there is no item to search for.\n");
        return NULL;
    }
    
    // Recorrer la lista buscando el símbolo
    Symbol* aux = ts;
    while (aux != NULL) {
        // Comparar nombres (verificando que no sean NULL)
        if (aux->info->name && name && strcmp(aux->info->name, name) == 0) {
            return aux->info; // Símbolo encontrado
        }
        aux = aux->next;
    }
    
    // Símbolo no encontrado
    printf("Error: Symbol with name '%s' not found.\n", name);
    return NULL;
}
