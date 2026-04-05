#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

// Função auxiliar para encontrar o caminho correto do arquivo
const char* obter_caminho_arquivo() {
    static char caminho[256];
    
    // Tentar primeiro caminho: ../data/carros.txt (quando executa de src/)
    FILE *teste = fopen("../data/carros.txt", "r");
    if (teste != NULL) {
        fclose(teste);
        return "../data/carros.txt";
    }
    
    // Tentar segundo caminho: data/carros.txt (quando executa da raiz)
    teste = fopen("data/carros.txt", "r");
    if (teste != NULL) {
        fclose(teste);
        return "data/carros.txt";
    }
    
    // Retornar caminho padrão
    return "../data/carros.txt";
}

void salvar_txt() {
    const char *caminho = obter_caminho_arquivo();
    FILE *f = fopen(caminho, "w");

    if (f == NULL) {
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(f, "%s;%s;%d\n",
            colecao[i].codigo,
            colecao[i].nome,
            colecao[i].frequencia);
    }

    fclose(f);
}

void carregar_txt() {
    const char *caminho = obter_caminho_arquivo();
    FILE *f = fopen(caminho, "r");

    if (f == NULL) {
        printf("Arquivo nao encontrado!\n");
        return;
    }

    tamanho = 0;

    while (1) {
        char codigo[10];
        char nome[50];
        int freq;

        int lidos = fscanf(f, "%[^;];%[^;];%d\n", codigo, nome, &freq);

        if (lidos != 3) break;

        strcpy(colecao[tamanho].codigo, codigo);
        strcpy(colecao[tamanho].nome, nome);
        colecao[tamanho].frequencia = freq;

        tamanho++;
    }

    fclose(f);
}