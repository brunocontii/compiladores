#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generate_asm.h"
#include "../ast/ast.h"

// Variable global para el archivo de salida del pseudo-assembler
static FILE* asm_file = NULL;

/**
 * Función principal que genera el archivo de pseudo-assembler completo
 * Busca el main, genera declaraciones y sentencias, y maneja el archivo
 */
void generateCodeASM(Node* root, const char* filename) {
    if (root == NULL) {
        printf("Error: NULL AST node encountered, cannot generate ASM code\n");
        exit(EXIT_FAILURE);
    }

    // Abrir archivo para escribir el pseudo-assembler
    asm_file = fopen(filename, "w");
    if (asm_file == NULL) {
        printf("Error: Could not open file %s for writing ASM code\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(asm_file, "BEGIN\n");

    // Buscar el nodo MAIN en el AST
    Node* main_node = searchNodeByToken(root, MAIN);
    if (main_node == NULL) {
        printf("Error: No 'main' function found in AST\n");
        exit(EXIT_FAILURE);
    }

    // Generar declaraciones de variables (hijo izquierdo del main)
    if (main_node->left != NULL) {
        generateDecs(main_node->left);
    }

    // Generar sentencias del programa (hijo derecho del main)
    if (main_node->right != NULL) {
        generateSentens(main_node->right);
    }

    fprintf(asm_file, "END\n");
    fclose(asm_file);
    printf("Pseudo-Assembly code generated: %s\n", filename);
}

/**
 * Genera código para una lista de declaraciones de variables
 * Maneja tanto DECS (lista) como DEC (declaración individual)
 */
void generateDecs(Node* decs_node) {
    if (decs_node == NULL) {
        printf("Error: NULL declarations node encountered, cannot generate ASM declarations code\n");
        exit(EXIT_FAILURE);
    }

    if (decs_node->info->token == DECS) {
        // Si es una lista de declaraciones, procesar recursivamente
        generateDec(decs_node->left);       // Procesar primera declaración
        generateDecs(decs_node->right);     // Procesar resto de declaraciones
    } else if (decs_node->info->token == DEC) {
        // Si es una declaración individual, procesarla
        generateDec(decs_node);
    } else {
        printf("Error: Unexpected token in declarations node\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * Genera código para una lista de sentencias
 * Maneja tanto SENTENS (lista) como sentencias individuales
 */
void generateSentens(Node* sentens_node) {
    if (sentens_node == NULL) {
        printf("Error: NULL statements node encountered, cannot generate ASM statements code\n");
        exit(EXIT_FAILURE);
    }

    if (sentens_node->info->token == SENTENS) {
        // Si es una lista de sentencias, procesar recursivamente
        generateSen(sentens_node->left);        // Procesar primera sentencia
        generateSentens(sentens_node->right);   // Procesar resto de sentencias
    } else if (sentens_node->info->token == RETURN || sentens_node->info->token == IGUAL) {
        // Si es una sentencia individual (return o asignación)
        generateSen(sentens_node);
    } else {
        printf("Error: Unexpected token in statements node\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * Genera código para una declaración individual de variable
 * Formato: DEC nombre_variable : TIPO
 */
void generateDec(Node* dec_node) {
    if (dec_node == NULL) {
        printf("Error: NULL declaration node encountered, cannot generate ASM declaration code\n");
        exit(EXIT_FAILURE);
    }

    if (dec_node->info->token == DEC) {
        // Determinar el tipo de la variable
        char* type;
        switch (dec_node->left->info->type) {
        case INTEGER:
            type = "INTEGER";
            break;
        case BOOLEAN:
            type = "BOOLEAN";
            break;
        case TYPE_VOID:
            type = "VOID";
            break;
        default:
            type = "UNKNOWN";
            break;
        }

        // Escribir la declaración: DEC nombre : tipo
        fprintf(asm_file, "DEC %s : %s\n", dec_node->right->info->name, type);
    } else {
        printf("Error: Unexpected token in declaration node\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * Genera código para una sentencia individual (asignación o return)
 */
void generateSen(Node* sen_node) {
    if (sen_node == NULL) {
        printf("Error: NULL statement node encountered, cannot generate ASM statement code\n");
        exit(EXIT_FAILURE);
    }

    if (sen_node->info->token == IGUAL) {
        // Asignación: variable = expresión
        fprintf(asm_file, "LOAD %s\n", sen_node->left->info->name);
        generateExp(sen_node->right);       // Generar código de la expresión
        fprintf(asm_file, "STORE %s\n", sen_node->left->info->name);
    } else if (sen_node->info->token == RETURN) {
        if (sen_node->left != NULL) {
            // Return con valor
            if (sen_node->left->info->token == ID) {
                // Si es una variable, retornar directamente
                fprintf(asm_file, "RETURN %s\n", sen_node->left->info->name);
            } else {
                // Si es una expresión, evaluarla primero
                generateExp(sen_node->left);
                fprintf(asm_file, "RETURN\n");
            }
        } else {
            // Return sin valor (void)
            fprintf(asm_file, "RETURN\n");
        }
    }
}

/**
 * Genera código para expresiones usando arquitectura de pila
 * Maneja números, variables, booleanos y operaciones
 */
void generateExp(Node* exp_node) {
    if (exp_node == NULL) {
        printf("Error: NULL expression node encountered, cannot generate ASM expression code\n");
        exit(EXIT_FAILURE);
    }

    switch (exp_node->info->token) {
        case NUM:
            // Número literal: ponerlo en la pila
            fprintf(asm_file, "  PUSH %d\n", exp_node->info->i_value);
            break;
        case ID:
            // Variable: cargar su valor en la pila
            fprintf(asm_file, "  LOAD %s\n", exp_node->info->name);
            break;
        case BOOL:
            fprintf(asm_file, "  PUSH %s\n", exp_node->info->b_value ? "true" : "false");
            break;
        case OP:
            if (strcmp(exp_node->info->op, "not") == 0) {
                // Operador unario NOT
                generateExp(exp_node->right);   // Evaluar operando
                fprintf(asm_file, "  NOT\n");
            } else {
                // Operadores binarios (+, -, *, /, and, or)
                generateExp(exp_node->left);    // Evaluar operando izquierdo
                generateExp(exp_node->right);   // Evaluar operando derecho
                
                // Generar instrucción según el operador
                if (strcmp(exp_node->info->op, "+") == 0) {
                    fprintf(asm_file, "  ADD\n");
                } else if (strcmp(exp_node->info->op, "-") == 0) {
                    fprintf(asm_file, "  SUB\n");
                } else if (strcmp(exp_node->info->op, "*") == 0) {
                    fprintf(asm_file, "  MUL\n");
                } else if (strcmp(exp_node->info->op, "/") == 0) {
                    fprintf(asm_file, "  DIV\n");
                } else if (strcmp(exp_node->info->op, "and") == 0) {
                    fprintf(asm_file, "  AND\n");
                } else if (strcmp(exp_node->info->op, "or") == 0) {
                    fprintf(asm_file, "  OR\n");
                }
            }
            break;
        default:
            printf("Error: Unexpected token in expression node\n");
            exit(EXIT_FAILURE);
    }
}