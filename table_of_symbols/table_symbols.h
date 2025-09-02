#ifndef TABLE_SYMBOLS_H
#define TABLE_SYMBOLS_H

#include "../ast/ast.h"

// Estructura de la tabla de símbolos como lista enlazada
typedef struct Symbol {
    Info *info;              // Información del símbolo (nombre, tipo, valor, etc.)
    struct Symbol* next;     // Puntero al siguiente símbolo en la lista
} Symbol;

// Funciones para manipular la tabla de símbolos
Symbol* createSymbol(Info *info);                    // Crea un nuevo símbolo
Symbol* insertByName(Symbol* ts, Info *info);        // Inserta un símbolo (verifica duplicados)
Info* searchByName(Symbol* ts, char* name);          // Busca un símbolo por nombre

#endif