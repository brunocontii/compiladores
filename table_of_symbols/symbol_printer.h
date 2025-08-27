#ifndef SYMBOL_PRINTER_H
#define SYMBOL_PRINTER_H

#include "table_symbols.h"

void printInfo(const Info* info);
void printTableSymbols(const Symbol* ts);
const char* getTokenString(Token token);
const char* getTypeString(Type type);

#endif