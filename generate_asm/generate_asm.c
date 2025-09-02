#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generate_asm.h"
#include "../ast/ast.h"

static FILE* asm_file = NULL;

void generateCodeASM(Node* root, const char* filename) {
    if (root == NULL) {
        printf("Error: NULL AST node encountered, cannot generate ASM code\n");
        exit(EXIT_FAILURE);
    }

    asm_file = fopen(filename, "w");
    if (asm_file == NULL) {
        printf("Error: Could not open file %s for writing ASM code\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(asm_file, "BEGIN\n");

    Node* main_node = searchNodeByToken(root, MAIN);
    if (main_node == NULL) {
        printf("Error: No 'main' function found in AST\n");
        exit(EXIT_FAILURE);
    }

    if (main_node->left != NULL) {
        generateDecs(main_node->left);
    }

    if (main_node->right != NULL) {
        generateSentens(main_node->right);
    }

    fprintf(asm_file, "END\n");
    fclose(asm_file);
    printf("Pseudo-Assembly code generated: %s\n", filename);
}

void generateDecs(Node* decs_node) {
    if (decs_node == NULL) {
        printf("Error: NULL declarations node encountered, cannot generate ASM declarations code\n");
        exit(EXIT_FAILURE);
    }

    if (decs_node->info->token == DECS) {
        generateDec(decs_node->left);
        generateDecs(decs_node->right);
    } else if (decs_node->info->token == DEC) {
        generateDec(decs_node);
    } else {
        printf("Error: Unexpected token in declarations node\n");
        exit(EXIT_FAILURE);
    }
}

void generateSentens(Node* sentens_node) {
    if (sentens_node == NULL) {
        printf("Error: NULL declarations node encountered, cannot generate ASM statements code");
        exit(EXIT_FAILURE);
    }

    if (sentens_node->info->token == SENTENS) {
        generateSen(sentens_node->left);
        generateSentens(sentens_node->right);
    } else if (sentens_node->info->token == RETURN || sentens_node->info->token == IGUAL) {
        generateSen(sentens_node);
    } else {
        printf("Error: Unexpected token in statements node\n");
        exit(EXIT_FAILURE);
    }
}

void generateDec(Node* dec_node) {
    if (dec_node == NULL) {
        printf("Error: NULL declaration node encountered, cannot generate ASM declaration code\n");
        exit(EXIT_FAILURE);
    }

    if (dec_node->info->token == DEC) {
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

        fprintf(asm_file, "DEC %s : %s\n", dec_node->right->info->name, type);
    } else {
        printf("Error: Unexpected token in declaration node\n");
        exit(EXIT_FAILURE);
    }
}

void generateSen(Node* sen_node) {
    if (sen_node == NULL) {
        printf("Error: NULL statement node encountered, cannot generate ASM statement code\n");
        exit(EXIT_FAILURE);
    }

    if (sen_node->info->token == IGUAL) {
        fprintf(asm_file, "LOAD %s\n", sen_node->left->info->name);
        Node* exp_node = sen_node->right;
        generateExp(exp_node);
        fprintf(asm_file, "STORE %s\n", sen_node->left->info->name);
    } else if (sen_node->info->token == RETURN) {
        if (sen_node->left != NULL) {
            generateExp(sen_node->left);
        }
        fprintf(asm_file, "RETURN\n");
    }
}

void generateExp(Node* exp_node) {
    if (exp_node == NULL) {
        printf("Error: NULL expression node encountered, cannot generate ASM expression code\n");
        exit(EXIT_FAILURE);
    }

    switch (exp_node->info->token) {
        case NUM:
            fprintf(asm_file, "  PUSH %d\n", exp_node->info->i_value);
            break;
        case ID:
            fprintf(asm_file, "  LOAD %s\n", exp_node->info->name);
            break;
        case BOOL:
            fprintf(asm_file, "  PUSH %s\n", exp_node->info->b_value ? "true" : "false");
            break;
        case OP:
            if (strcmp(exp_node->info->op, "not") == 0) {
                generateExp(exp_node->right);
                fprintf(asm_file, "  NOT\n");
            } else {
                generateExp(exp_node->left);
                generateExp(exp_node->right);
                
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