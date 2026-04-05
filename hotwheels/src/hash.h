#ifndef HASH_H
#define HASH_H

#define TAMANHO_HASH 50

typedef struct {
    char codigo[10];
    int posicao;
} HashItem;

extern HashItem hash_table[TAMANHO_HASH];

int funcao_hash(char codigo[]);
void inserir_hash(char codigo[], int posicao);
int buscar_hash(char codigo[]);
void atualizar_hash();

#endif