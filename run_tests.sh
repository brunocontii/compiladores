#!/bin/bash

# Script simple para ejecutar todos los tests
echo "Ejecutando todos los tests..."
echo

# Contadores
passed=0
failed=0
failed_tests=()

# Recorrer todos los archivos .txt en la carpeta tests-para-preproyecto
for test_file in tests-para-preproyecto/*.txt; do
    # Verificar si el archivo existe (en caso de que no haya archivos .txt)
    if [ -f "$test_file" ]; then
        # Obtener solo el nombre del archivo sin la ruta
        filename=$(basename "$test_file")
        
        echo "=== $filename ==="
        echo "Archivo: $filename"
        output=$(./prog "$test_file" 2>&1)
        echo "$output"
        if echo "$output" | grep -q "No hay errores"; then
            echo "✓ PASÓ"
            ((passed++))
        else
            echo "✗ FALLÓ"
            ((failed++))
            failed_tests+=("$filename")
        fi
        echo
    else
        echo "No se encontraron archivos .txt en tests-para-preproyecto/"
        break
    fi
done

echo "========================================="
echo "RESUMEN:"
echo "Tests que pasaron: $passed"
echo "Tests que fallaron: $failed"

if [ $failed -gt 0 ]; then
    echo "Tests que fallaron:"
    for test in "${failed_tests[@]}"; do
        echo "  - $test"
    done
fi

echo "========================================="
