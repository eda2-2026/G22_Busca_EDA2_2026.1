#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "hash.h"
#include "arquivo.h"

void inicializar() {
    strcpy(colecao[0].codigo, "HW001");
    strcpy(colecao[0].nome, "Skyline R34");

    strcpy(colecao[1].codigo, "HW002");
    strcpy(colecao[1].nome, "Supra MK4");

    strcpy(colecao[2].codigo, "HW003");
    strcpy(colecao[2].nome, "Camaro SS");

    tamanho = 3;

    for (int i = 0; i < tamanho; i++) {
        colecao[i].frequencia = 0;
    }
}

int main() {
    int opcao;
    char entrada[100];
    char nome[50];
    char codigo[10];

    printf("INICIANDO SISTEMA...\n");
    fflush(stdout);

    carregar_txt();

    printf("Carros carregados: %d\n", tamanho);
    fflush(stdout);

    if (tamanho == 0) {
        printf("Inicializando dados padrao...\n");
        inicializar();
    }

    atualizar_hash();
    fflush(stdout);

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Buscar por nome (MTF e todas as ocorrencias)\n");
        printf("2 - Buscar por codigo (HASH)\n");
        printf("3 - Mostrar colecao\n");
        printf("4 - Inserir carro\n");
        printf("5 - Excluir carro\n");
        printf("6 - Editar carro\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        fflush(stdout);

        // leitura segura
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            printf("Erro na leitura!\n");
            continue;
        }

        if (sscanf(entrada, "%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Nome: ");
                if (fgets(nome, sizeof(nome), stdin) != NULL) {
                    nome[strcspn(nome, "\n")] = '\0';
                    busca_mtf_todas(nome);
                    atualizar_hash();
                }
                break;

            case 2:
                printf("Codigo: ");
                if (fgets(codigo, sizeof(codigo), stdin) != NULL) {
                    codigo[strcspn(codigo, "\n")] = '\0';
                    int pos = buscar_hash(codigo);
                    if (pos != -1) {
                        printf("Encontrado: %s\n", colecao[pos].nome);
                        colecao[pos].frequencia++;
                        
                        // Aplicar Move-to-Front
                        if (pos != 0) {
                            Carro temp = colecao[pos];
                            for (int j = pos; j > 0; j--) {
                                colecao[j] = colecao[j - 1];
                            }
                            colecao[0] = temp;
                        }
                        atualizar_hash();
                    }
                }
                break;

            case 3:
                printf("\n--- COLECAO ---\n");
                mostrar_colecao();
                break;

            case 4:
                printf("Codigo: ");
                if (fgets(codigo, sizeof(codigo), stdin) != NULL) {
                    codigo[strcspn(codigo, "\n")] = '\0';
                    printf("Nome: ");
                    if (fgets(nome, sizeof(nome), stdin) != NULL) {
                        nome[strcspn(nome, "\n")] = '\0';
                        inserir_carro(codigo, nome);
                        atualizar_hash();
                    }
                }
                break;

            case 5:
                printf("Codigo do carro a excluir: ");
                if (fgets(codigo, sizeof(codigo), stdin) != NULL) {
                    codigo[strcspn(codigo, "\n")] = '\0';
                    excluir_carro(codigo);
                    atualizar_hash();
                }
                break;

            case 6:
                printf("Codigo do carro a editar: ");
                if (fgets(codigo, sizeof(codigo), stdin) != NULL) {
                    codigo[strcspn(codigo, "\n")] = '\0';
                    printf("Novo nome: ");
                    if (fgets(nome, sizeof(nome), stdin) != NULL) {
                        nome[strcspn(nome, "\n")] = '\0';
                        editar_carro(codigo, nome);
                        atualizar_hash();
                    }
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    salvar_txt();

    return 0;
}