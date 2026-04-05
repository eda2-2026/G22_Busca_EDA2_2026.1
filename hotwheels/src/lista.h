#ifndef LISTA_H
#define LISTA_H

#define MAX 100

typedef struct {
    char codigo[10];
    char nome[50];
    int frequencia;
} Carro;

extern Carro colecao[MAX];
extern int tamanho;

int busca_mtf_todas(char nome[]);
void mostrar_colecao();
int inserir_carro(char codigo[], char nome[]);
int excluir_carro(char codigo[]);
int editar_carro(char codigo[], char novo_nome[]);

#endif