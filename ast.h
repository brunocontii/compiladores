#ifndef AST_H
#define AST_H

#include <stdbool.h>

typedef enum {
    INT,BOOL,TOKEN_VOID,MAIN,RETURN,NUM,ID,OP,DEL,SENTENS,DECS,DEC
} Token;

typedef enum {
    INTEGER, BOOLEAN, TYPE_VOID
} Type;

typedef struct {
    int i_value;
    bool b_value;
    char* name;
    char op;
    char del;
    Type type;
    Token token;
} Info;

typedef struct Node {
    Info info;
    struct Node* left;
    struct Node* right;
} Node;

Node* createTree(Info info, Node* left, Node* right);
Node* createLeaf(Info info);

void generateDotFile(Node* root, const char* filename);

#endif