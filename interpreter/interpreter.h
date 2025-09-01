#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "../ast/ast.h"
#include "../table_of_symbols/table_symbols.h"

void interpreter(Node* root, Symbol* ts);
void evaluateExp(Node* exp_node, Symbol* ts);
void executeSentens(Node* sens_node, Symbol* ts);
void executeSen(Node* sen_node, Symbol* ts);
void executeAssign(Node* assign_node, Symbol* ts);
void executeRet(Node* return_node, Symbol* ts);

#endif
