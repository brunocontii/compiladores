%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast/ast.h"

Node* root;

%}

%code requires {
    #include "ast/ast.h"

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
            
            Info tipo_info = { .name = strdup($1.name), .token = $1.token };            
            Info main_info = { .name = strdup("main"), .token = MAIN };
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
            Info decs_info = { .name = strdup("decs"), .token = DECS };
            $$ = createTree(decs_info, $1, $2);
        }
    ;

dec: tipo TOKEN_ID TOKEN_PYC
    {
        Info dec_info = { .name = strdup("dec"), .token = DEC };

        Info tipo_info = { .name = $1.name, .token = $1.token };
        Node* tipo = createLeaf(tipo_info);

        Info id_info = { .name = $2, .token = ID, .type = $1.type };
        Node* id = createLeaf(id_info);

        $$ = createTree(dec_info, tipo, id);
    }
;

sentens: senten
        {
            $$ = $1;
        }
    | senten sentens
        {
            Info sentens_info = { .name = strdup("sentens"), .token = SENTENS };
            $$ = createTree(sentens_info, $1, $2);
        }
    ;

senten: TOKEN_ID TOKEN_IGUAL exp TOKEN_PYC
        {
            Info id_info = { .name = $1, .token = ID };
            Node* id = createLeaf(id_info);

            Info igual_info = { .op = '=', .token = OP };
            $$ = createTree(igual_info, id, $3);
        }
    | TOKEN_RETURN exp TOKEN_PYC
        {
            Info ret_info = { .name = strdup("return"), RETURN };
            $$ = createTree(ret_info, $2, NULL);
        }
    | TOKEN_RETURN TOKEN_PYC
        {
            Info ret_info = { .name = strdup("return"), .token = RETURN };
            $$ = createLeaf(ret_info);
        }
    ;

exp: exp TOKEN_OP_MAS exp
        {
            Info op_info = { .op = '+', .token = OP };
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_MULT exp
        {
            Info op_info = { .op = '*', .token = OP };
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_RES exp
        {
            Info op_info = { .op = '-', .token = OP };
            $$ = createTree(op_info, $1, $3);
        }
    | exp TOKEN_OP_DIV exp
        {
            Info op_info = { .op = '/', .token = OP };
            $$ = createTree(op_info, $1, $3);
        }
    | TOKEN_PAR_A exp TOKEN_PAR_C
        {
            $$ = $2;
        }
    | TOKEN_NUM
        {
            Info num_info = { .i_value = $1, .token = NUM, .type = INTEGER };
            $$ = createLeaf(num_info);
        }
    | TOKEN_ID
        {
            Info id_info = { .name = $1, .token = ID };
            $$ = createLeaf(id_info);
        }
    ;

%%


