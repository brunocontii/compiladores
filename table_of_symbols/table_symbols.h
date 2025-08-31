#ifndef TABLE_SYMBOLS_H
#define TABLE_SYMBOLS_H

#include "../ast/ast.h"

typedef struct Symbol {
    Info *info;
    struct Symbol* next;
} Symbol;


Symbol* createSymbol(Info *info);
Symbol* insertByName(Symbol* ts, Info *info);
Info* searchByName(Symbol* ts, char* name);

#endif