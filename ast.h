#ifndef AST_H
#define AST_H

#include <stdbool.h>

typedef union {
    int i_value;
    bool b_value;
    char* name;
    char op;
    char del;
} Info;

typedef enum {
    INT,BOOL,VOID,MAIN,RETURN,EXP,NUM,ID,OP,DEL,SENTENS,DECS,DEC
} InfoType;

typedef struct Node {
    Info info;
    InfoType info_type;
    struct Node* left;
    struct Node* right;
} Node;

Node* createTree(Info info, InfoType info_type, Node* left, Node* right);
Node* createLeaf(Info info, InfoType info_type);

void generateDotFile(Node* root, const char* filename);

#endif