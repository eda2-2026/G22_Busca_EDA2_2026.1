#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
#include "lista.h"

HashItem hash_table[TAMANHO_HASH];

// Função auxiliar para converter string para minúsculas
void str_lower_hash(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int funcao_hash(char codigo[]) {
    int soma = 0;
    for (int i = 0; codigo[i] != '\0'; i++) {
        soma += codigo[i];
    }
    return soma % TAMANHO_HASH;
}

void inserir_hash(char codigo[], int posicao) {
    char codigo_lower[10];
    
    // Converter para minúsculas
    strcpy(codigo_lower, codigo);
    str_lower_hash(codigo_lower);
    
    int idx = funcao_hash(codigo_lower);  // Usar hash do código minúsculo
    int inicio = idx;

    while (hash_table[idx].codigo[0] != '\0') {
        idx = (idx + 1) % TAMANHO_HASH;
        
        // Evita loop infinito
        if (idx == inicio) {
            printf("ERRO: Tabela hash cheia!\n");
            return;
        }
    }

    strcpy(hash_table[idx].codigo, codigo_lower);
    hash_table[idx].posicao = posicao;
}

int buscar_hash(char codigo[]) {
    char codigo_lower[10];
    
    // Converter código de entrada para minúsculas
    strcpy(codigo_lower, codigo);
    str_lower_hash(codigo_lower);
    
    int idx = funcao_hash(codigo_lower);  // Usar hash do código minúsculo
    int comparacoes = 0;
    int inicio = idx;

    while (hash_table[idx].codigo[0] != '\0') {
        comparacoes++;

        if (strcmp(hash_table[idx].codigo, codigo_lower) == 0) {
            printf("Comparacoes: %d\n", comparacoes);
            return hash_table[idx].posicao;
        }

        idx = (idx + 1) % TAMANHO_HASH;
        
        // Evita loop infinito se a tabela estiver cheia
        if (idx == inicio) {
            printf("Nao encontrado!\n");
            return -1;
        }
    }

    printf("Nao encontrado!\n");
    return -1;
}

void atualizar_hash() {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        hash_table[i].codigo[0] = '\0';
        hash_table[i].posicao = -1;
    }

    for (int i = 0; i < tamanho; i++) {
        inserir_hash(colecao[i].codigo, i);
    }
}