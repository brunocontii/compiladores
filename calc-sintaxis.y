%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast/ast.h"
#include "table_of_symbols/table_symbols.h"
#include "table_of_symbols/symbol_to_image.h"

Node* root;
Symbol* head = NULL;

%}

%code requires {
    #include "ast/ast.h"
    #include "table_of_symbols/table_symbols.h"

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
%token <sval> TOKEN_ID
%token <ival> TOKEN_NUM

%right TOKEN_IGUAL
%left TOKEN_OP_MAS TOKEN_OP_RES
%left TOKEN_OP_MULT TOKEN_OP_DIV

%type <node> exp senten sentens dec decs prog
%type <tipo_info> tipo

%%

prog: tipo TOKEN_MAIN TOKEN_PAR_A TOKEN_PAR_C TOKEN_LLA_A decs sentens TOKEN_LLA_C 
        {   
            printf("No hay errores \n"); 
            
            Info *tipo_info = malloc(sizeof(Info));
            tipo_info->name = strdup($1.name);
            tipo_info->token = $1.token;

            Info *main_info = malloc(sizeof(Info));
            main_info->name = strdup("main");
            main_info->token = MAIN;

            Node* main_node = createTree(main_info, $6, $7);
            $$ = createTree(tipo_info, main_node, NULL);
            root = $$;
                        
            if (root != NULL) {
                generateDotFile(root, "prog_ast.dot");
                int result = system("dot -Tpng prog_ast.dot -o prog_ast.png");
                
                if (result == 0) {
                    system("open prog_ast.png");
                } else {
                    printf("Error al generar la imagen.\n");
                }
            }

            generateAndOpenSymbolTable(head, "symbol_table");
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
            printf("Error: variable '%s' ya declarada\n", $2);
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
                printf("Error: variable '%s' no declarada\n", $1);
                YYERROR;
            } else if (id_buscado->type != $3->info->type) {
                printf("Error: tipos incompatibles en la asignacion\n");
                YYERROR;
            } else {
                Node *id = createLeaf(id_buscado);

                Info *igual_info = malloc(sizeof(Info));
                igual_info->op = strdup("=");
                igual_info->token = OP;

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
                printf("Error: operacion suma requiere operandos enteros\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("+");
            op_info->token = OP;
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_MULT exp
        {
            if ($1->info->type != INTEGER || $3->info->type != INTEGER) {
                printf("Error: operacion multiplicacion requiere operandos enteros\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("*");
            op_info->token = OP;
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_RES exp
        {
            if ($1->info->type != INTEGER || $3->info->type != INTEGER) {
                printf("Error: operacion resta requiere operandos enteros\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("-");
            op_info->token = OP;
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_DIV exp
        {
            if ($1->info->type != INTEGER || $3->info->type != INTEGER) {
                printf("Error: operacion division requiere operandos enteros\n");
                YYERROR;
            }

            Info *op_info = malloc(sizeof(Info));
            op_info->op = strdup("/");
            op_info->token = OP;
            $$ = createTree(op_info, $1, $3);
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
    ;

%%


