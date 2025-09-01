#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"

void interpreter(Node* root, Symbol* ts) {
    if (root == NULL || ts == NULL) {
        printf("Error: root of AST or symbol table is NULL\n");
        exit(EXIT_FAILURE);
    }

    Node* main_node = searchNodeByToken(root, MAIN);
    if (main_node == NULL) {
        printf("Error: MAIN function not found\n");
        exit(EXIT_FAILURE);
    }

    executeSentens(main_node->right, ts);
}

void executeSentens(Node* sens_node, Symbol* ts) {
    if (sens_node == NULL) {
        printf("Error: NULL statements node encountered\n");
        exit(EXIT_FAILURE);
    }

    if (sens_node->info->token == SENTENS) {
        executeSentens(sens_node->left, ts);
        executeSentens(sens_node->right, ts);
    } else {
        executeSen(sens_node, ts);
    }
}

void executeSen(Node* sen_node, Symbol* ts) {
    if (sen_node == NULL) {
        printf("Error: NULL statement node encountered\n");
        exit(EXIT_FAILURE);
    }

    if (sen_node->info->token == IGUAL) {
        executeAssign(sen_node, ts);
    } else if (sen_node->info->token == RETURN) {
        executeRet(sen_node, ts);
    } else {
        printf("Error: Unknown statement type\n");
        exit(EXIT_FAILURE);
    }
}


void executeAssign(Node* assign_node, Symbol* ts) {
    if (assign_node == NULL) {
        printf("Error: Invalid assignment node\n");
        exit(EXIT_FAILURE);
    }

    Info* id_info = searchByName(ts, assign_node->left->info->name);
    if (id_info == NULL) {
        printf("Error: Variable '%s' not found\n", assign_node->left->info->name);
        exit(EXIT_FAILURE);
    }

    evaluateExp(assign_node->right, ts);

    if (id_info->type == INTEGER) {
        id_info->i_value = assign_node->right->info->i_value;
    } else if (id_info->type == BOOLEAN) {
        id_info->b_value = assign_node->right->info->b_value;
    }

    printf("Variable '%s' assigned with value : ", id_info->name);
    if (id_info->type == INTEGER) {
        printf("%d\n", id_info->i_value);
    } else if (id_info->type == BOOLEAN) {
        printf("%s\n", id_info->b_value ? "true" : "false");
    }
}

void executeRet(Node* ret_node, Symbol* ts) {
    if (ret_node == NULL) {
        printf("Error: NULL return node encountered\n");
        exit(EXIT_FAILURE);
    }

    if (ret_node->left != NULL) {
        evaluateExp(ret_node->left, ts);
        if (ret_node->left->info->type == INTEGER) {
            printf("Return value: %d\n", ret_node->left->info->i_value);
        } else if (ret_node->left->info->type == BOOLEAN) {
            printf("Return value: %s\n", ret_node->left->info->b_value ? "true" : "false");
        }
    } else {
        printf("Return statement with no value\n");
    }
}

void evaluateExp(Node* exp_node, Symbol* ts) {
    if (exp_node == NULL) {
        printf("Error: NULL expression node encountered\n");
        exit(EXIT_FAILURE);
    }

    switch (exp_node->info->token) {
    case NUM:
        printf("Number: %d\n", exp_node->info->i_value);
        break;
    case ID:
        Info* id_info = searchByName(ts, exp_node->info->name);
        if (id_info == NULL) {
            printf("Error: Variable '%s' not found\n", exp_node->info->name);
            exit(EXIT_FAILURE);
        }
        exp_node->info->i_value = id_info->i_value;
        exp_node->info->b_value = id_info->b_value;
        exp_node->info->type = id_info->type;
        break;
    case BOOL:
        printf("Boolean: %s\n", exp_node->info->b_value ? "true" : "false");
        break;
    case OP:
        if (strcmp(exp_node->info->op, "not") == 0) {
            evaluateExp(exp_node->right, ts);
            exp_node->info->b_value = !exp_node->right->info->b_value;
            exp_node->info->type = BOOLEAN;
        } else {
            evaluateExp(exp_node->left, ts);
            evaluateExp(exp_node->right, ts);
        
            if (strcmp(exp_node->info->op, "+") == 0) {
                exp_node->info->i_value = exp_node->left->info->i_value + exp_node->right->info->i_value;
                exp_node->info->type = INTEGER;
            } else if (strcmp(exp_node->info->op, "-") == 0) {
                exp_node->info->i_value = exp_node->left->info->i_value - exp_node->right->info->i_value;
                exp_node->info->type = INTEGER;
            } else if (strcmp(exp_node->info->op, "*") == 0) {
                exp_node->info->i_value = exp_node->left->info->i_value * exp_node->right->info->i_value;
                exp_node->info->type = INTEGER;
            } else if (strcmp(exp_node->info->op, "/") == 0) {
                if (exp_node->right->info->i_value == 0) {
                    printf("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                exp_node->info->i_value = exp_node->left->info->i_value / exp_node->right->info->i_value;
                exp_node->info->type = INTEGER;
            } else if (strcmp(exp_node->info->op, "and") == 0) {
                exp_node->info->b_value = exp_node->left->info->b_value && exp_node->right->info->b_value;
                exp_node->info->type = BOOLEAN;
            } else if (strcmp(exp_node->info->op, "or") == 0) {
                exp_node->info->b_value = exp_node->left->info->b_value || exp_node->right->info->b_value;
                exp_node->info->type = BOOLEAN;
            }
        }
        break;
    default:
        printf("Error: Unknown expression type\n");
        exit(EXIT_FAILURE);
        break;
    }
}
