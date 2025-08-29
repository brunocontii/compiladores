#ifndef TABLE_SYMBOLS_H
#define TABLE_SYMBOLS_H

#include "../ast/ast.h"

typedef struct Symbol {
    Info *info;
    struct Symbol* next;
} Symbol;


Symbol* createSymbol(Info *info); // crea un simbolo de la tabla
Symbol* insertByName(Symbol* ts, Info *info); //inserta un elemento en la tabla (no puede haber duplicados)
Info* searchByName(Symbol* ts, char* name); // busca un elemento en la tabla
                                            // si lo encuentra devuelve un puntero a info, si no NULL

#endif