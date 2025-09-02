#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "../ast/ast.h"
#include "../table_of_symbols/table_symbols.h"

void interpreter(Node* root, Symbol* ts);
void executeSentens(Node* sens_node, Symbol* ts, Type expected_return_type);
void executeSen(Node* sen_node, Symbol* ts, Type expected_return_type);
void executeAssign(Node* assign_node, Symbol* ts);
void executeRet(Node* ret_node, Symbol* ts, Type expected_return_type);
void evaluateExp(Node* exp_node, Symbol* ts);
void printType(Type type);

#endif
