%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"

Node* root;

%}

%code requires {
    #include "ast.h"
}

%union {
    int ival;
    char *sval;
    Node* node;
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
%type <sval> tipo

%%

prog: tipo TOKEN_MAIN TOKEN_PAR_A TOKEN_PAR_C TOKEN_LLA_A decs sentens TOKEN_LLA_C 
        {   
            printf("No hay errores \n"); 
            
            Info tipo_info;
            InfoType tipo_infotype;
            
            tipo_info.name = $1;

            if (strcmp($1, "int") == 0) {
                tipo_infotype = INT;
            } else if (strcmp($1, "bool") == 0) {
                tipo_infotype = BOOL;
            } else if (strcmp($1, "void") == 0) {
                tipo_infotype = VOID;
            } else {
                tipo_info.name = "unknown";
                tipo_infotype = VOID;
            }
            
            Info main_info = {.name = "main"};
            Node* main_node = createTree(main_info, MAIN, $6, $7);
            
            $$ = createTree(tipo_info, tipo_infotype, main_node, NULL);
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
        }
    ;

tipo: TOKEN_INT
        {
            $$ = strdup("int");
        }
    | TOKEN_BOOL
        {
            $$ = strdup("bool");
        }
    | TOKEN_VOID
        {
            $$ = strdup("void");
        }
    ;

decs: dec
        {
            $$ = $1;
        }
    | dec decs
        {
            Info decs_info = {.name = "decs"};
            $$ = createTree(decs_info, DECS, $1, $2);
        }
    ;

dec: tipo TOKEN_ID TOKEN_PYC
    {
        Info dec_info = {.name = "dec"};
        Info tipo_info;
        InfoType tipo_infotype;

        tipo_info.name = $1;
        
        if (strcmp($1, "int") == 0) {
            tipo_infotype = INT;
        } else if (strcmp($1, "bool") == 0) {
            tipo_infotype = BOOL;
        } else if (strcmp($1, "void") == 0) {
            tipo_infotype = VOID;
        } else {
            tipo_info.name = "unknown";
            tipo_infotype = VOID;
        }
        
        Node* tipo = createLeaf(tipo_info, tipo_infotype);
        Info id_info = {.name = $2};
        Node* id = createLeaf(id_info, ID);
        $$ = createTree(dec_info, DEC, tipo, id);
    }
;

sentens: senten
        {
            $$ = $1;
        }
    | senten sentens
        {
            Info sentens_info = {.name = "sentens"};
            $$ = createTree(sentens_info, SENTENS, $1, $2);
        }
    ;

senten: TOKEN_ID TOKEN_IGUAL exp TOKEN_PYC
        {
            Info id_info = {.name = $1};
            Node* id = createLeaf(id_info, ID);
            Info igual_info = {.op = '='};
            $$ = createTree(igual_info, OP, id, $3);
        }
    | TOKEN_RETURN exp TOKEN_PYC
        {
            Info ret_info = {.name = "return"};
            $$ = createTree(ret_info, RETURN, $2, NULL);
        }
    | TOKEN_RETURN TOKEN_PYC
        {
            Info ret_info = {.name = "return"};
            $$ = createLeaf(ret_info, RETURN);
        }
    ;

exp: exp TOKEN_OP_MAS exp
        {
            Info op_info = {.op = '+'};
            $$ = createTree(op_info, OP, $1, $3);
        }
    | exp TOKEN_OP_MULT exp
        {
            Info op_info = {.op = '*'};
            $$ = createTree(op_info, OP, $1, $3);
        }
    | exp TOKEN_OP_RES exp
        {
            Info op_info = {.op = '-'};
            $$ = createTree(op_info, OP, $1, $3);
        }
    | exp TOKEN_OP_DIV exp
        {
            Info op_info = {.op = '/'};
            $$ = createTree(op_info, OP, $1, $3);
        }
    | TOKEN_PAR_A exp TOKEN_PAR_C
        {
            $$ = $2;
        }
    | TOKEN_NUM
        {
            Info num_info = {.i_value = $1};
            $$ = createLeaf(num_info, NUM);
        }
    | TOKEN_ID
        {
            Info id_info = {.name = $1};
            $$ = createLeaf(id_info, ID);
        }
    ;

%%


