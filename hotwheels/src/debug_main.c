#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "hash.h"
#include "arquivo.h"

int main() {
    fprintf(stderr, "DEBUG: Iniciando\n");
    fflush(stderr);
    
    printf("INICIANDO SISTEMA...\n");
    fflush(stdout);
    
    fprintf(stderr, "DEBUG: Antes de carregar_txt\n");
    fflush(stderr);
    
    carregar_txt();
    
    fprintf(stderr, "DEBUG: Depois de carregar_txt, tamanho=%d\n", tamanho);
    fflush(stderr);
    
    printf("Carros carregados: %d\n", tamanho);
    fflush(stdout);
    
    return 0;
}