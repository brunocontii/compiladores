#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "../ast/ast.h"
#include "../table_of_symbols/table_symbols.h"

// Función principal del intérprete que ejecuta el programa desde el AST
void interpreter(Node* root, Symbol* ts);

// Funciones para ejecutar diferentes tipos de nodos
void executeSentens(Node* sens_node, Symbol* ts, Type expected_return_type);    // Ejecuta lista de sentencias
void executeSen(Node* sen_node, Symbol* ts, Type expected_return_type);         // Ejecuta una sentencia individual
void executeAssign(Node* assign_node, Symbol* ts);                              // Ejecuta asignaciones (variable = expresión)
void executeRet(Node* ret_node, Symbol* ts, Type expected_return_type);         // Ejecuta sentencias return
void evaluateExp(Node* exp_node, Symbol* ts);                                   // Evalúa expresiones y calcula valores

// Función auxiliar para mostrar tipos
void printType(Type type);

#endif
