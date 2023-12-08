#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
} Produto;


void inicializarEstoque(Produto estoque[], int *numProdutos) {
    *numProdutos = 0;
}


void adicionarProduto(Produto estoque[], int *numProdutos) {
    printf("Informe o código do produto: ");
    scanf("%d", &estoque[*numProdutos].codigo);

    printf("Informe a descrição do produto: ");
    scanf("%s", estoque[*numProdutos].descricao);

    printf("Informe a quantidade do produto: ");
    scanf("%d", &estoque[*numProdutos].quantidade);

    printf("Informe o valor do produto: ");
    scanf("%f", &estoque[*numProdutos].valor);

    (*numProdutos)++;
}


void gerarRelatorio(Produto estoque[], int numProdutos) {
    printf("\nRelatório de Estoque:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Código: %d | Descrição: %s | Quantidade: %d | Valor: %.2f\n",
               estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
    }
}


void consultarProduto(Produto estoque[], int numProdutos) {
    int codigo;
    printf("Informe o código do produto a ser consultado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < numProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Código: %d | Descrição: %s | Quantidade: %d | Valor: %.2f\n",
                   estoque[i].codigo, estoque[i].descricao, estoque[i].quantidade, estoque[i].valor);
            return;
        }
    }

    printf("Produto não encontrado.\n");
}


void removerProduto(Produto estoque[], int *numProdutos) {
    int codigo;
    printf("Informe o código do produto a ser removido: ");
    scanf("%d", &codigo);

    for (int i = 0; i < *numProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            // Remove o produto movendo os elementos subsequentes uma posição para trás
            for (int j = i; j < *numProdutos - 1; j++) {
                estoque[j] = estoque[j + 1];
            }
            (*numProdutos)--;
            printf("Produto removido com sucesso.\n");
            return;
        }
    }

    printf("Produto não esta cadastrado.\n");
}

int main() {
    Produto estoque[100];  
    int numProdutos = 0;
    int opcao;

    do {
        printf("\n===== Menu de Controle de Estoque =====\n");
        printf("1. Inicializar Estoque\n");
        printf("2. Adicionar Produto\n");
        printf("3. Gerar Relatório\n");
        printf("4. Consultar Produto\n");
        printf("5. Remover Produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inicializarEstoque(estoque, &numProdutos);
                printf("Estoque inicializado.\n");
                break;
            case 2:
                adicionarProduto(estoque, &numProdutos);
                printf("Produto adicionado ao estoque.\n");
                break;
            case 3:
                gerarRelatorio(estoque, numProdutos);
                break;
            case 4:
                consultarProduto(estoque, numProdutos);
                break;
            case 5:
                removerProduto(estoque, &numProdutos);
                break;
            case 0:
                printf("Saindo do programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
