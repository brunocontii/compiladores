#ifndef SYMBOL_TO_IMAGE_H
#define SYMBOL_TO_IMAGE_H

#include "table_symbols.h"

// Función para generar visualización de la tabla de símbolos
void generateTSDotFile(const Symbol* ts, const char* base_filename);

// Función para mostrar información de un símbolo en consola
void printInfo(const Info* info);

#endif