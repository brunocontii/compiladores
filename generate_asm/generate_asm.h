#ifndef GENERATE_ASM_H
#define GENERATE_ASM_H

#include "../ast/ast.h"

// Función principal que genera el archivo de pseudo-assembler
void generateCodeASM(Node* root, const char* filename);

// Funciones para generar código de diferentes partes del AST
void generateDecs(Node* decs_node);         // Genera declaraciones de variables
void generateSentens(Node* sentens_node);   // Genera lista de sentencias
void generateDec(Node* dec_node);           // Genera una declaración individual
void generateSen(Node* sen_node);           // Genera una sentencia individual
void generateExp(Node* exp_node);           // Genera código para expresiones

#endif