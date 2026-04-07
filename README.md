# Busca_HotWheels

Número da Lista: 1
Conteúdo da Disciplina: Algoritmos de Busca (Estruturas de Dados II)

## Alunos

| Matrícula | Aluno                            |
| --------- | -------------------------------- |
| 211061903 | Isaque Santos                    |
| 200023985 | Maria Eduarda dos Santos Marques |

## Sobre

Sistema desenvolvido em **C** para gerenciamento e busca em uma coleção de carros Hot Wheels com implementação de algoritmos de otimização de busca. O projeto utiliza duas estratégias de busca principais: **Move-to-Front (MTF)** com busca linear e **Hash Table** para acesso rápido por código.

## Screenshots

Tela inicial do programa

![Tela inicial](/hotwheels/assets/inicial.png)

Resultado de uma busca por nome

![mtf](/hotwheels/assets/mtf.png)

Resultado de uma busca por código

![hash](/hotwheels/assets/hash.png)

Exibição completa da coleção

![colecao](/hotwheels/assets/colecao.png)

## Instalação

Linguagem C

### Pré-requisitos

* GCC instalado
* Terminal ou prompt de comando
* Permissão de execução no diretório


### Compilação e Execução no Linux

```bash
cd ../hotwheels/src
gcc -o programa main.c lista.c hash.c arquivo.c
./programa
```

### Testes Automatizados

```bash
cd ./hotwheels
chmod +x tests/run_test.sh
./tests/run_test.sh
```

### Compilação Manual de Testes

```bash
gcc -o tests/testes tests/testes.c src/lista.c src/hash.c src/arquivo.c
./tests/testes
```

## Outros

### Funcionalidades

* Busca por nome com substring e Move-to-Front
* Busca por código utilizando tabela hash
* Inserção, edição e remoção de miniaturas
* Contagem de comparações nas buscas
* Sistema case-insensitive
* Persistência em arquivo
* Controle de frequência de buscas

### Algoritmos Utilizados

Move-to-Front (MTF):
Reorganiza a lista movendo elementos mais acessados para o início, melhorando buscas futuras.

Tabela Hash com Linear Probing:
Permite busca eficiente por código, com complexidade média O(1).

### Formato dos Dados

Arquivo `carros.txt`:

**Formato**: `codigo;nome;frequencia`
- **codigo**: Identificador único (HW###)
- **nome**: Nome do carro
- **frequencia**: Número de vezes que foi buscado

Exemplo:

```
HW001;Skyline R34 NOVO;0
HW005;Lamborghini Aventador;4
HW025;Mazda CX-5;15
```

### Conceitos Importantes

Ocorrência: quantidade de itens encontrados que correspondem à busca.

Comparação: número de verificações realizadas durante a execução da busca.

### Observações

* Capacidade máxima de 100 miniaturas
* Tabela hash com 50 posições
* Frequências são incrementadas em todas as buscas
* Dados são salvos ao encerrar o programa
* Todas as operações são case-insensitive
* Move-to-Front reordena a lista, não a hash table

### Vídeo do trabalho


[Clique aqui para assistir à demonstração](https://youtu.be/FUskpwCpEg8)
