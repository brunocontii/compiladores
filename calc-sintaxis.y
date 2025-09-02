%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast/ast.h"
#include "table_of_symbols/table_symbols.h"
#include "table_of_symbols/symbol_to_image.h"
#include "interpreter/interpreter.h"
#include "generate_asm/generate_asm.h"

Node* root;
Symbol* head = NULL;

%}

%code requires {
    #include "ast/ast.h"
    #include "table_of_symbols/table_symbols.h"
    #include "interpreter/interpreter.h"
    #include "generate_asm/generate_asm.h"

    typedef struct {
        char* name;
        Token token;
        Type type;
    } InfoTipo;
}

%union {
    int ival;
    char *sval;
    Node* node;
    InfoTipo tipo_info;
}

%token TOKEN_INT TOKEN_BOOL TOKEN_VOID TOKEN_MAIN TOKEN_RETURN 
%token TOKEN_OP_RES TOKEN_OP_MAS TOKEN_OP_MULT TOKEN_OP_DIV TOKEN_IGUAL
%token TOKEN_PYC TOKEN_PAR_A TOKEN_PAR_C TOKEN_LLA_A TOKEN_LLA_C
%token TOKEN_VTRUE TOKEN_VFALSE TOKEN_OP_AND TOKEN_OP_OR TOKEN_OP_NOT
%token <sval> TOKEN_ID
%token <ival> TOKEN_NUM
TRUE
%right TOKEN_IGUAL
%left TOKEN_OP_OR
%left TOKEN_OP_AND
%right TOKEN_OP_NOT
%left TOKEN_OP_MAS TOKEN_OP_RES
%left TOKEN_OP_MULT TOKEN_OP_DIV

%type <node> exp senten sentens dec decs prog
%type <tipo_info> tipo

%%

prog: tipo TOKEN_MAIN TOKEN_PAR_A TOKEN_PAR_C TOKEN_LLA_A decs sentens TOKEN_LLA_C 
        {   
            printf("There are no errors \n"); 

            Info *tipo_info = malloc(sizeof(Info));
            tipo_info->name = strdup($1.name);
            tipo_info->token = $1.token;
            tipo_info->type = $1.type;

            Info *main_info = malloc(sizeof(Info));
            main_info->name = strdup("main");
            main_info->token = MAIN;

            Node* main_node = createTree(main_info, $6, $7);
            $$ = createTree(tipo_info, main_node, NULL);
            root = $$;

            if (root != NULL && head != NULL) {
                generateASTDotFile(root, "prog_ast");
                generateTSDotFile(head, "symbol_table");
                interpreter(root, head);
                generateCodeASM(root, "ast_to_asm.txt");
            }
        }
    ;

tipo: TOKEN_INT
        {
            $$.name = strdup("int");
            $$.token = INT;
            $$.type = INTEGER;
        }
    | TOKEN_BOOL
        {
            $$.name = strdup("bool");
            $$.token = BOOL;
            $$.type = BOOLEAN;
        }
    | TOKEN_VOID
        {
            $$.name = strdup("void");
            $$.token = T_VOID;
            $$.type = TYPE_VOID;
        }
    ;

decs: dec
        {
            $$ = $1;
        }
    | dec decs
        {
            Info *decs_info = malloc(sizeof(Info));
            decs_info->name = strdup("decs");
            decs_info->token = DECS;
            $$ = createTree(decs_info, $1, $2);
        }
    ;

dec: tipo TOKEN_ID TOKEN_PYC
    {
        Info *id_buscado = searchByName(head, $2);
        if (id_buscado != NULL) {
            printf("Error: Variable '%s' already declared\n", $2);
            YYERROR;
        }

        Info *dec_info = malloc(sizeof(Info));
        dec_info->name = strdup("dec");
        dec_info->token = DEC;

        Info *tipo_info = malloc(sizeof(Info));
        tipo_info->name = strdup($1.name);
        tipo_info->token = $1.token;
        Node* tipo = createLeaf(tipo_info);

        Info *id_info = malloc(sizeof(Info));
        id_info->name = strdup($2);
        id_info->token = ID;
        id_info->type = $1.type;
        Node* id = createLeaf(id_info);

        head = insertByName(head, id_info);

        $$ = createTree(dec_info, tipo, id);
    }
;

sentens: senten
        {
            $$ = $1;
        }
    | senten sentens
        {
            Info *sentens_info = malloc(sizeof(Info));
            sentens_info->name = strdup("sentest");
            sentens_info->token = SENTENS;
            $$ = createTree(sentens_info, $1, $2);
        }
    ;

senten: TOKEN_ID TOKEN_IGUAL exp TOKEN_PYC
        {
            Info *id_buscado = searchByName(head, $1);
            if (id_buscado == NULL) {
                printf("Error: Undeclared variable '%s'\n", $1);
                YYERROR;
            } else if (id_buscado->type != $3->info->type) {
                printf("Error: Incompatible types in assignment\n");
                YYERROR;
            } else {
                Node *id = createLeaf(id_buscado);

                Info *igual_info = malloc(sizeof(Info));
                igual_info->op = strdup("=");
                igual_info->token = IGUAL;

                $$ = createTree(igual_info, id, $3);
            }
        }
    | TOKEN_RETURN exp TOKEN_PYC
        {
            Info *ret_info = malloc(sizeof(Info));
            ret_info->name = strdup("return");
            ret_info->token = RETURN;
            $$ = createTree(ret_info, $2, NULL);
        }
    | TOKEN_RETURN TOKEN_PYC
        {
            Info *ret_info = malloc(sizeof(Info));
            ret_info->name = strdup("return");
            ret_info->token = RETURN;
            $$ = createLeaf(ret_info);
        }
    ;

exp: exp TOKEN_OP_MAS exp
        {
            if ($1->info->type != INTEGER || $3->info->type != INTEGER) {
                printf("Error: Addition (+) operation requires integer operands\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("+");
            op_info->token = OP;
            op_info->type = INTEGER;
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_MULT exp
        {
            if ($1->info->type != INTEGER || $3->info->type != INTEGER) {
                printf("Error: Multiplication (*) operation requires integer operands\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("*");
            op_info->token = OP;
            op_info->type = INTEGER;
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_RES exp
        {
            if ($1->info->type != INTEGER || $3->info->type != INTEGER) {
                printf("Error: Subtraction (-) operation requires integer operands\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("-");
            op_info->token = OP;
            op_info->type = INTEGER;
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_DIV exp
        {
            if ($1->info->type != INTEGER || $3->info->type != INTEGER) {
                printf("Error: Division (/) operation requires integer operands\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("/");
            op_info->token = OP;
            op_info->type = INTEGER;
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_AND exp
        {
            if ($1->info->type != BOOLEAN || $3->info->type != BOOLEAN) {
                printf("Error: Operation 'and' requires Boolean operators\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("and");
            op_info->token = OP;
            op_info->type = BOOLEAN;
            $$ = createTree(op_info, $1, $3);
        } 
    | exp TOKEN_OP_OR exp
        {
            if ($1->info->type != BOOLEAN || $3->info->type != BOOLEAN) {
                printf("Error: Operation 'or' requires Boolean operators\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("or");
            op_info->token = OP;
            op_info->type = BOOLEAN;
            $$ = createTree(op_info, $1, $3);
        }
    | TOKEN_OP_NOT exp
        {
            if ($2->info->type != BOOLEAN) {
                printf("Error: Operation 'not' require Boolean operator\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("not");
            op_info->token = OP;
            op_info->type = BOOLEAN;
            $$ = createTree(op_info, NULL, $2);
        }
    | TOKEN_PAR_A exp TOKEN_PAR_C
        {
            $$ = $2;
        }
    | TOKEN_NUM
        {
            Info *num_info = malloc(sizeof(Info));
            num_info->i_value = $1;
            num_info->token = NUM;
            num_info->type = INTEGER;
            $$ = createLeaf(num_info);
        }
    | TOKEN_ID
        {
            Info *id_buscado = searchByName(head, $1);
            if (id_buscado == NULL) {
                printf("Error: variable '%s' no declarada\n", $1);
                YYERROR;
            } else {
                $$ = createLeaf(id_buscado);
            }
        }
    | TOKEN_VTRUE
        {
            Info *booleano = malloc(sizeof(Info));
            booleano->bool_string = strdup("true");
            booleano->b_value = true;
            booleano->type = BOOLEAN;
            booleano->token = BOOL;
            $$ = createLeaf(booleano);
        }
    | TOKEN_VFALSE
        {
            Info *booleano = malloc(sizeof(Info));
            booleano->bool_string = strdup("false");
            booleano->b_value = false;
            booleano->type = BOOLEAN;
            booleano->token = BOOL;
            $$ = createLeaf(booleano);
        }
    ;

%%


