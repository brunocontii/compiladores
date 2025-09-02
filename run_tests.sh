#!/bin/bash

# Script para ejecutar automáticamente todos los tests del proyecto
# Busca archivos .txt en la carpeta tests-para-preproyecto y los ejecuta con el compilador

echo "Ejecutando todos los tests..."
echo

# Contadores para estadísticas finales
passed=0
failed=0
failed_tests=()

# Recorrer todos los archivos .txt en la carpeta tests-para-preproyecto
for test_file in tests-para-preproyecto/*.txt; do
    # Verificar si el archivo existe (en caso de que no haya archivos .txt)
    if [ -f "$test_file" ]; then
        # Obtener solo el nombre del archivo sin la ruta completa
        filename=$(basename "$test_file")
        
        echo "=== Ejecutando $filename ==="
        echo "Archivo: $filename"
        
        # Ejecutar el compilador con el archivo de test y capturar toda la salida
        output=$(./prog < "$test_file" 2>&1)
        echo "$output"
        
        # Verificar si el test pasó buscando mensajes de éxito
        if echo "$output" | grep -q -i "no hay errores\|there are no errors\|no errors\|successfully parsed\|compilation successful"; then
            echo "✓ TEST PASÓ"
            ((passed++))  # Incrementar contador de tests exitosos
        else
            echo "✗ TEST FALLÓ"
            ((failed++))  # Incrementar contador de tests fallidos
            failed_tests+=("$filename")  # Agregar a la lista de tests fallidos
        fi
        echo
    else
        echo "No se encontraron archivos .txt en tests-para-preproyecto/"
        break
    fi
done

# Mostrar resumen final de la ejecución
echo "========================================="
echo "RESUMEN DE TESTS:"
echo "Tests que pasaron: $passed"
echo "Tests que fallaron: $failed"
echo "Total de tests: $((passed + failed))"

# Si hay tests fallidos, mostrar cuáles fueron
if [ $failed -gt 0 ]; then
    echo
    echo "Tests que fallaron:"
    for test in "${failed_tests[@]}"; do
        echo "  - $test"
    done
fi

echo "========================================="
