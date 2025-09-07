#include <stdio.h>

#define MAX 50

void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    int i = *tamanho - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i];
        i--;
    }
    vetor[i + 1] = valor;
    (*tamanho)++;
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

void removerElemento(int vetor[], int *tamanho, int valor) {
    int pos = buscaBinaria(vetor, *tamanho, valor);
    if (pos != -1) {
        for (int i = pos; i < *tamanho - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        (*tamanho)--;
        printf("Elemento %d removido.\n", valor);
    } else {
        printf("Elemento %d não encontrado.\n", valor);
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(void) {
    int vetor[MAX];
    int tamanho = 0;
    int capacidade;

    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &capacidade);
    } while (capacidade < 3 || capacidade > MAX);

    printf("Digite %d valores inteiros:\n", capacidade);
    for (int i = 0; i < capacidade; i++) {
        int valor;
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        inserirOrdenado(vetor, &tamanho, valor);
    }

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Imprimir vetor\n");
        printf("2 - Consultar valor (busca binária)\n");
        printf("3 - Remover valor\n");
        printf("4 - Inserir valor\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        int valor;
        switch (opcao) {
            case 1:
                imprimirVetor(vetor, tamanho);
                break;
            case 2:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                int pos;
                pos = buscaBinaria(vetor, tamanho, valor);
                if (pos != -1)
                    printf("Elemento %d encontrado na posição %d.\n", valor, pos);
                else
                    printf("Elemento não encontrado.\n");
                break;
            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                removerElemento(vetor, &tamanho, valor);
                break;
            case 4:
                if (tamanho >= MAX) {
                    printf("O vetor está cheio! Não é possível inserir mais elementos.\n");
                } else {
                    printf("Digite o valor a inserir: ");
                    scanf("%d", &valor);
                    inserirOrdenado(vetor, &tamanho, valor);
                    printf("Valor inserido com sucesso.\n");
                }
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
