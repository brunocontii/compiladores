#ifndef GENERATE_ASM_H
#define GENERATE_ASM_H

#include "../ast/ast.h"

void generateCodeASM(Node* root, const char* filename);
void generateDecs(Node* decs_node);
void generateSentens(Node* sentens_node);
void generateDec(Node* dec_node);
void generateSen(Node* sen_node);
void generateExp(Node* exp_node);

#endif