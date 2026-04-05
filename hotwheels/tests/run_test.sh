#!/bin/bash

echo "======================================"
echo "Compilacao e execucao dos testes"
echo "======================================"
echo ""

# Ir para a raiz do projeto
cd "$(dirname "$0")/.."

# Compilar programa principal
echo "Compilando o programa principal..."
cd src
gcc -o programa main.c lista.c hash.c arquivo.c

if [ $? -ne 0 ]; then
    echo "Erro na compilacao do programa."
    exit 1
fi

echo "Compilacao do programa concluida com sucesso."
cd ..
echo ""

# Compilar testes
echo "Compilando os testes..."
gcc -o tests/testes tests/testes.c src/lista.c src/hash.c src/arquivo.c

if [ $? -ne 0 ]; then
    echo "Erro na compilacao dos testes."
    exit 1
fi

echo "Compilacao dos testes concluida com sucesso."
echo ""

# Executar testes automaticos
echo "Executando testes automaticos..."
echo "--------------------------------------"
./tests/testes
echo ""

echo "--------------------------------------"
echo "Executando testes manuais"
echo "--------------------------------------"
echo ""

# Teste 1
echo "Teste 1: busca por nome (porsche)"
cd src
(echo "1"; sleep 0.1; echo "porsche"; sleep 0.1; echo "0") | timeout 3 ./programa 2>&1 | grep -A 5 "Resultados"
cd ..
echo ""

# Teste 2
echo "Teste 2: busca por codigo (HW005)"
cd src
(echo "2"; sleep 0.1; echo "HW005"; sleep 0.1; echo "0") | timeout 3 ./programa 2>&1 | grep -A 2 "Encontrado\|Comparacoes"
cd ..
echo ""

# Teste 3
echo "Teste 3: exibicao da colecao"
cd src
(echo "3"; sleep 0.1; echo "0") | timeout 3 ./programa 2>&1 | grep -A 5 "COLECAO"
cd ..
echo ""

# Teste 4
echo "Teste 4: insercao de novo carro"
cd src
(echo "4"; sleep 0.1; echo "HW999"; sleep 0.1; echo "Test Car"; sleep 0.1; echo "0") | timeout 3 ./programa 2>&1 | grep "inserido\|Conflito"
cd ..
echo ""

# Teste 5
echo "Teste 5: busca case-insensitive (ferrari)"
cd src
(echo "1"; sleep 0.1; echo "ferrari"; sleep 0.1; echo "0") | timeout 3 ./programa 2>&1 | grep -A 3 "Resultados"
cd ..
echo ""

# Teste 6
echo "Teste 6: remocao de carro (HW999)"
cd src
(echo "5"; sleep 0.1; echo "HW999"; sleep 0.1; echo "0") | timeout 3 ./programa 2>&1 | grep "excluido"
cd ..
echo ""

# Teste 7
echo "Teste 7: edicao de carro (HW004)"
cd src
(echo "6"; sleep 0.1; echo "HW004"; sleep 0.1; echo "Mustang Custom"; sleep 0.1; echo "0") | timeout 3 ./programa 2>&1 | grep "editado"
cd ..
echo ""

# Teste 8
echo "Teste 8: tentativa de insercao de codigo duplicado"
cd src
(echo "4"; sleep 0.1; echo "HW001"; sleep 0.1; echo "Outro"; sleep 0.1; echo "0") | timeout 3 ./programa 2>&1 | grep "Conflito\|existe"
cd ..
echo ""

echo "======================================"
echo "Execucao dos testes finalizada"
echo "======================================"