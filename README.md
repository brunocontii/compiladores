# Preproyecto - Taller de Diseño de Software

## Descripción

Este es un preproyecto para la materia **Taller de Diseño de Software** que implementa un compilador/intérprete básico para un lenguaje de programación simple. El preproyecto incluye análisis léxico, análisis sintáctico, generación de AST (Árbol de Sintaxis Abstracta), tabla de símbolos, interpretación y generación de código pseudo-assembler.

## Características del Lenguaje

### Tipos de Datos Soportados
- `int` - Números enteros
- `bool` - Valores booleanos (true/false)
- `void` - Tipo vacío (para funciones que no retornan valor)

### Operaciones
- **Aritméticas**: `+`, `-`, `*`, `/`
- **Lógicas**: `and`, `or`, `not`
- **Asignación**: `=`

### Estructura del Programa
- Función `main` obligatoria con tipo de retorno
- Declaración de variables antes de su uso
- Sentencias de asignación
- Sentencias `return` (con o sin expresión)

### Ejemplo de Código Válido
```c
int main() {
    int x;
    bool flag;
    
    x = 5 + 3 * 2;
    flag = true and not false;
    
    return x;
}
```

## Arquitectura del Proyecto

```
├── ast/                     # Módulo de AST
├── generate_asm/            # Generador de pseudo-assembler
├── interpreter/             # Intérprete
├── table_of_symbols/        # Tabla de símbolos
├── tests-para-preproyecto/  # Casos de prueba
├── calc-lexico.l            # Analizador léxico (Flex)
├── calc-sintaxis.y          # Analizador sintáctico (Bison)
├── Makefile                 # Archivo para compilación automática
├── preproyecto.pdf          # PDF con las consignas
├── run_tests.sh             # Script para ejecutar todos los tests
├── script.sh                # Script para compilar manualmente
└── README.md
```

## Dependencias

### Herramientas Requeridas
- **flex** - Generador de analizadores léxicos
- **bison** - Generador de analizadores sintácticos
- **gcc** - Compilador de C
- **gdb** - Depurador
- **graphviz** - Para generar visualizaciones de AST y tabla de símbolos

### Instalación en Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install flex bison gcc gdb graphviz
```

## Compilación y Ejecución

### Opción 1: Compilar con Makefile (Recomendado)
```bash
# Compilar el proyecto
make

# Limpiar archivos generados (opcional)
make clean
```

### Opción 2: Compilación Manual con Script
```bash
# Dar permisos de ejecución al script
chmod +x script

# Compilar manualmente
./script
```

### Opción 3: Compilación Manual sin Script
```bash
# Generar analizador léxico
flex calc-lexico.l

# Generar analizador sintáctico
bison -d calc-sintaxis.y

# Compilar todo
gcc -o prog lex.yy.c calc-sintaxis.tab.c ast/ast.c ast/ast_to_image.c table_of_symbols/table_symbols.c table_of_symbols/symbol_to_image.c interpreter/interpreter.c generate_asm/generate_asm.c -lfl
```

### Ejecutar con Archivo de Entrada
```bash
./prog < archivo_de_prueba.txt
```

## Archivos Generados

El compilador genera los siguientes archivos:

1. **lex.yy.c** - Código C del analizador léxico generado por Flex
2. **calc-sintaxis.tab.c** - Código C del analizador sintáctico generado por Bison
3. **calc-sintaxis.tab.h** - Archivo de cabecera con definiciones
4. **prog_ast.dot** - Representación del AST en formato DOT
5. **prog_ast.png** - Imagen visual del AST
6. **symbol_table.dot** - Representación de la tabla de símbolos en formato DOT
7. **symbol_table.png** - Imagen visual de la tabla de símbolos
8. **ast_to_asm.txt** - Código pseudo-assembler generado

## Funcionalidades

### ✅ Análisis Léxico
- Reconocimiento de tokens: palabras clave, identificadores, números, operadores
- Manejo de espacios en blanco y comentarios

### ✅ Análisis Sintáctico
- Verificación de la gramática del lenguaje
- Construcción del AST
- Manejo de precedencia de operadores

### ✅ Análisis Semántico
- **Verificación de tipos**: Las operaciones aritméticas requieren operandos enteros
- **Verificación de declaraciones**: Las variables deben ser declaradas antes de su uso
- **Detección de redeclaraciones**: No se permite declarar la misma variable dos veces
- **Compatibilidad de tipos en asignaciones**: El tipo de la expresión debe coincidir con el tipo de la variable

### ✅ Tabla de Símbolos
- Almacenamiento de información de variables (nombre, tipo, valor)
- Búsqueda eficiente de símbolos
- Detección de variables no declaradas

### ✅ Generación de AST
- Construcción de árbol de sintaxis abstracta
- Visualización gráfica del AST

### ✅ Intérprete
- Ejecución del código analizado
- Evaluación de expresiones aritméticas y lógicas
- Manejo de asignaciones y retornos

### ✅ Generador de Pseudo-Assembler
- Traducción del AST a código pseudo-assembler
- Instrucciones simples y legibles
- Generación automática de código

## Casos de Prueba

El directorio `tests-para-preproyecto/` contiene ejemplos que demuestran:

- ✅ **Casos válidos**: Programas que compilan y ejecutan correctamente
- ❌ **Casos inválidos**: Programas con errores sintácticos o semánticos

### Tipos de Errores Detectados
- Variables no declaradas
- Redeclaración de variables
- Incompatibilidad de tipos en operaciones
- Incompatibilidad de tipos en asignaciones
- Errores de sintaxis

## Desarrollo

### Estructura de Archivos Principales

- **calc-lexico.l**: Define los tokens y patrones léxicos
- **calc-sintaxis.y**: Define la gramática y las reglas semánticas
- **ast/**: Implementación del AST y funciones de manipulación
- **table_of_symbols/**: Implementación de la tabla de símbolos
- **interpreter/**: Lógica de interpretación y ejecución
- **generate_asm/**: Generador de código pseudo-assembler

## Verificaciones Semánticas

### Control de Tipos
- Las operaciones aritméticas (`+`, `-`, `*`, `/`) requieren operandos de tipo `int`
- Las operaciones lógicas (`and`, `or`) requieren operandos de tipo `bool`
- El operador `not` requiere un operando de tipo `bool`
- Las asignaciones deben ser compatibles en tipo

### Control de Símbolos
- Verificación de declaración antes del uso
- Detección de redeclaraciones
- Mantenimiento de tabla de símbolos durante el análisis

## Limitaciones Conocidas

- Solo soporta la función `main`
- No hay soporte para funciones definidas por el usuario
- No hay estructuras de control (if, while, for)
- No hay arrays o estructuras de datos complejas
- Solo tipos de datos básicos (int, bool, void)
- El pseudo-assembler es una representación intermedia, no código ejecutable

