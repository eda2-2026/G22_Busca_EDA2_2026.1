#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"

Carro colecao[MAX];
int tamanho = 0;

// Função auxiliar para converter string para minúsculas
void str_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Função para buscar TODAS as ocorrências com MTF (uma única busca, contagem correta)
int busca_mtf_todas(char nome[]) {
    int comparacoes = 0;
    int encontrados = 0;
    int primeiro_idx = -1;
    char nome_lower[50];
    char carro_lower[50];

    // Converter entrada para minúsculas
    strcpy(nome_lower, nome);
    str_lower(nome_lower);

    printf("\n--- Resultados da busca por '%s' ---\n", nome);

    // Primeira passagem: encontrar todas as ocorrências e o primeiro
    for (int i = 0; i < tamanho; i++) {
        comparacoes++;

        // Converter nome do carro para minúsculas
        strcpy(carro_lower, colecao[i].nome);
        str_lower(carro_lower);

        // Busca parcial (substring) - case insensitive
        if (strstr(carro_lower, nome_lower) != NULL) {
            encontrados++;
            colecao[i].frequencia++;
            
            // Guardar índice do primeiro encontrado
            if (primeiro_idx == -1) {
                primeiro_idx = i;
            }
        }
    }

    // Se encontrou algo, aplicar Move-to-Front no primeiro
    if (primeiro_idx != -1 && primeiro_idx != 0) {
        Carro temp = colecao[primeiro_idx];
        for (int j = primeiro_idx; j > 0; j--) {
            colecao[j] = colecao[j - 1];
        }
        colecao[0] = temp;
    }

    // Segunda passagem: listar todos (agora em ordem atualizada)
    encontrados = 0;
    for (int i = 0; i < tamanho; i++) {
        strcpy(carro_lower, colecao[i].nome);
        str_lower(carro_lower);

        if (strstr(carro_lower, nome_lower) != NULL) {
            encontrados++;
            printf("%d. %s - %s (freq: %d)\n", 
                   encontrados, 
                   colecao[i].codigo, 
                   colecao[i].nome, 
                   colecao[i].frequencia);
        }
    }

    if (encontrados == 0) {
        printf("Nenhum carro encontrado!\n");
    } else {
        printf("Total de ocorrencias: %d\n", encontrados);
        printf("Total de comparacoes: %d\n", comparacoes);
    }

    return encontrados;
}

void mostrar_colecao() {
    if (tamanho == 0) {
        printf("Colecao vazia!\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%s - %s (freq: %d)\n",
               colecao[i].codigo,
               colecao[i].nome,
               colecao[i].frequencia);
    }
}

// Função para inserir novo carro
int inserir_carro(char codigo[], char nome[]) {
    if (tamanho >= MAX) {
        printf("Erro: Colecao cheia!\n");
        return 0;
    }

    // Validar entrada
    if (strlen(codigo) == 0 || strlen(nome) == 0) {
        printf("Erro: Codigo e nome nao podem ser vazios!\n");
        return 0;
    }

    // Converter código para verificação case-insensitive
    char codigo_lower[10];
    strcpy(codigo_lower, codigo);
    str_lower(codigo_lower);

    // Verificar se código já existe
    for (int i = 0; i < tamanho; i++) {
        char existing_lower[10];
        strcpy(existing_lower, colecao[i].codigo);
        str_lower(existing_lower);
        
        if (strcmp(existing_lower, codigo_lower) == 0) {
            printf("Erro: Codigo %s ja existe! (Conflito detectado)\n", codigo);
            return 0;
        }
    }

    strcpy(colecao[tamanho].codigo, codigo);
    strcpy(colecao[tamanho].nome, nome);
    colecao[tamanho].frequencia = 0;
    tamanho++;

    printf("Carro inserido com sucesso!\n");
    return 1;
}

// Função para excluir carro por código
int excluir_carro(char codigo[]) {
    int pos = -1;
    char codigo_lower[10];
    strcpy(codigo_lower, codigo);
    str_lower(codigo_lower);

    // Procurar carro com esse código (case-insensitive)
    for (int i = 0; i < tamanho; i++) {
        char existing_lower[10];
        strcpy(existing_lower, colecao[i].codigo);
        str_lower(existing_lower);
        
        if (strcmp(existing_lower, codigo_lower) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Erro: Carro com codigo %s nao encontrado!\n", codigo);
        return 0;
    }

    // Remover carro (deslocar todos para frente)
    for (int i = pos; i < tamanho - 1; i++) {
        colecao[i] = colecao[i + 1];
    }

    tamanho--;
    printf("Carro excluido com sucesso!\n");
    return 1;
}

// Função para editar carro por código
int editar_carro(char codigo[], char novo_nome[]) {
    char codigo_lower[10];
    strcpy(codigo_lower, codigo);
    str_lower(codigo_lower);

    for (int i = 0; i < tamanho; i++) {
        char existing_lower[10];
        strcpy(existing_lower, colecao[i].codigo);
        str_lower(existing_lower);
        
        if (strcmp(existing_lower, codigo_lower) == 0) {
            strcpy(colecao[i].nome, novo_nome);
            printf("Carro editado com sucesso!\n");
            return 1;
        }
    }

    printf("Erro: Carro com codigo %s nao encontrado!\n", codigo);
    return 0;
}