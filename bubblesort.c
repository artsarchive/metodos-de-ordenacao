#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Referência: 
    https://www.ime.usp.br/~leo/intr_prog/introducao_ordenacao.html
*/

void bubbleSort (int vet[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

void gerarVetor (int vet[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        vet[i] = rand() % qtd;
    }
}

void copiarVetor (int origem[], int destino[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        destino[i] = origem[i];
    }
}

void imprime (int vet[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main (void) {
    int qtd = 0;
    double tempo;
    clock_t inicio, fim;

    printf("Intervalo dos números gerados:\nExemplo:\n100\n1.000\n10.000\n");
    scanf("%d", &qtd);

    int vetor[qtd], copia[qtd];

    gerarVetor (vetor, qtd);

    printf("----- VETOR ORIGINAL -----\n");
    imprime (vetor, qtd);

    printf("\n");

    copiarVetor (vetor, copia, qtd);
    inicio = clock();
    bubbleSort (vetor, qtd);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("----- BUBBLE SORT -----\n");
    imprime (vetor, qtd);
    printf("Tempo: %.5f segundos.\n", tempo);

    return 0;
}