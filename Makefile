CC = gcc
CFLAGS = -Wall -g
TARGET = prog

SOURCES = calc-sintaxis.tab.c lex.yy.c \
		ast/ast.c ast/ast_to_image.c \
		table_of_symbols/table_symbols.c table_of_symbols/symbol_to_image.c \
		interpreter/interpreter.c \
		generate_asm/generate_asm.c

all: $(TARGET)

$(TARGET): calc-sintaxis.tab.c lex.yy.c $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) -lm

calc-sintaxis.tab.c calc-sintaxis.tab.h: calc-sintaxis.y
	bison -d calc-sintaxis.y

lex.yy.c: calc-lexico.l calc-sintaxis.tab.h
	flex calc-lexico.l

clean:
	rm -f $(TARGET) calc-sintaxis.tab.c calc-sintaxis.tab.h lex.yy.c *.dot *.png table_of_symbols/*.dot table_of_symbols/*.png ast_to_asm.txt

.PHONY: all clean