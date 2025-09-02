#ifndef AST_H
#define AST_H

#include <stdbool.h>

// Tipos de tokens que reconoce el analizador léxico
typedef enum {
    INT,        // Palabra reservada 'int'
    BOOL,       // Palabra reservada 'bool'
    T_VOID,     // Palabra reservada 'void'
    MAIN,       // Palabra reservada 'main'
    RETURN,     // Palabra reservada 'return'
    NUM,        // Número
    ID,         // Identificador
    OP,         // Operador
    DEL,        // Delimitador
    SENTENS,    // Secuencia de sentencias
    DECS,       // Secuencia de declaraciones
    DEC,        // Declaración
    IGUAL       // Asignación
} Token;

// Tipos de datos que soporta el lenguaje
typedef enum {
    INTEGER, BOOLEAN, TYPE_VOID
} Type;

// Estructura que almacena la información de cada nodo del AST
typedef struct {
    int i_value;           // Valor entero (para números)
    bool b_value;          // Valor booleano
    char* name;            // Nombre de variable o función
    char* op;              // Operador (+, -, *, /, and, or, not)
    char* bool_string;     // Representación en string del booleano
    char del;              // Delimitadores (;, {, }, etc.)
    Type type;             // Tipo de dato (INTEGER, BOOLEAN, TYPE_VOID)
    Token token;           // Tipo de token
} Info;

// Estructura de un nodo del Árbol de Sintaxis Abstracta
typedef struct Node {
    Info *info;            // Información del nodo
    struct Node* left;     // Hijo izquierdo
    struct Node* right;    // Hijo derecho
} Node;

// Funciones para crear nodos del AST
Node* createTree(Info *info, Node* left, Node* right);
Node* createLeaf(Info *info);

// Función para generar visualización del AST
void generateASTDotFile(Node* root, const char* base_filename);

// Función para buscar nodos en el AST
Node* searchNodeByToken(Node* root, Token token);

#endif