#include <stdio.h>
#include "../src/lista.h"
#include "../src/hash.h"
#include "../src/arquivo.h"

void teste_mtf() {
    printf("\nTESTE MTF:\n");
    printf("Buscando por 'Mazda' 3 vezes:\n");

    busca_mtf_todas("Mazda");
    busca_mtf_todas("Mazda");
    busca_mtf_todas("Mazda");

    printf("\nColecao apos testes:\n");
    mostrar_colecao();
}

void teste_hash() {
    printf("\nTESTE HASH:\n");

    buscar_hash("HW002");
    buscar_hash("HW002");
    buscar_hash("HW002");
}

int main() {
    carregar_txt();

    if (tamanho == 0) {
        printf("Inicializando dados...\n");
    }

    atualizar_hash();

    teste_mtf();
    atualizar_hash();
    teste_hash();

    salvar_txt();

    return 0;
}