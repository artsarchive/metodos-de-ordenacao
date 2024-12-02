#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Referência: 
    https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/quick.html#Divide

    https://www.ime.usp.br/~pf/algoritmos/aulas/quick.html#basic-qsort

    Livro Algoritmos, Teoria e Prática, Thomas N. Cormen, Charles E. Leiserson, 
    Ronald L. Rivest, Clifford Stein.
*/

int divide (int vet[], int p, int r) {    // Auxiliar para o QuickSort
    int pivo = vet[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (vet[j] <= pivo) {
            i++;
            int aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }
    int temp = vet[i + 1];
    vet[i + 1] = vet[r];
    vet[r] = temp;

    return i + 1;
}
void quickSort (int vet[], int p, int r) { 
    int q;

    if (p < r) {
        q = divide (vet, p, r);
        quickSort (vet, p, q - 1);
        quickSort (vet, q + 1, r);
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

    printf("Vetor original: ");
    imprime (vetor, qtd);

    printf("\n");

    copiarVetor (vetor, copia, qtd);
    inicio = clock();
    quickSort (vetor, 0, qtd - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("----- QUICK SORT -----\n");
    imprime (vetor, qtd);
    printf("Tempo: %.5f segundos.\n", tempo);

    return 0;
}