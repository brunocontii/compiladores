#ifndef TABLE_SYMBOLS_H
#define TABLE_SYMBOLS_H

#include <stdbool.h>

typedef enum {
    INT,BOOL,T_VOID,MAIN,RETURN,NUM,ID,OP,DEL,SENTENS,DECS,DEC
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

typedef struct Symbol {
    Info *info;
    struct Symbol* next;
} Symbol;


Symbol* createSymbol(Info *info); // crea un simbolo de la tabla
Symbol* insertByName(Symbol* ts, Info *info); //inserta un elemento en la tabla (no puede haber duplicados)
Info* searchByName(Symbol* ts, char* name); // busca un elemento en la tabla
                                            // si lo encuentra devuelve un puntero a info, si no NULL

#endif