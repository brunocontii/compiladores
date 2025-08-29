#include <stdio.h>
#include "symbol_printer.h"

void printInfo(const Info* info) {
    if (!info) return;
    printf("{ ");
    if (info->name) printf("name: \"%s\", ", info->name);
    printf("token: %s, ", getTokenStringTable(info->token));
    printf("type: %s, ", getTypeStringTable(info->type));
    if (info->token == NUM) printf("i_value: %d, ", info->i_value);
    if (info->token == BOOL) printf("b_value: %s, ", info->b_value ? "true" : "false");
    if (info->token == OP) printf("op: '%s', ", info->op);
    if (info->token == DEL) printf("del: '%c', ", info->del);
    printf("}\n");
}

void printTableSymbols(const Symbol* ts) {
    printf("Tabla de simbolos:\n");
    while (ts != NULL) {
        printInfo(ts->info);
        ts = ts->next;
    }
}

const char* getTokenStringTable(Token token) {
    switch(token) {
        case INT: return "T_INT";
        case BOOL: return "T_BOOL";
        case T_VOID: return "T_VOID";
        case MAIN: return "T_MAIN";
        case RETURN: return "T_RETURN";
        case NUM: return "T_NUM";
        case ID: return "T_ID";
        case OP: return "T_OP";
        case DEL: return "T_DEL";
        case SENTENS: return "T_SENTENS";
        case DECS: return "T_DECS";
        case DEC: return "T_DEC";
        default: return "UNKNOWN";
    }
}

const char* getTypeStringTable(Type type) {
    switch(type) {
        case INTEGER: return "INTEGER";
        case BOOLEAN: return "BOOLEAN";
        case TYPE_VOID: return "VOID";
        default: return "UNKNOWN";
    }
}
