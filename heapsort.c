#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Referências: 
    https://www.geeksforgeeks.org/heap-sort/#implementation-of-heap-sort

    Livro Algoritmos, Teoria e Prática, Thomas N. Cormen, Charles E. Leiserson, 
    Ronald L. Rivest, Clifford Stein.
*/

void heapify (int vet[], int qtd, int i) {
    int maior = i; 
    int indice_esq = 2 * i + 1;
    int indice_dir = 2 * i + 2;

    if (indice_esq < qtd && vet[indice_esq] > vet[maior]) 
        maior = indice_esq;
    
    if (indice_dir < qtd && vet[indice_dir] > vet[maior]) 
        maior = indice_dir;

    if (maior != i) {
        int aux = vet[i];
        vet[i] = vet[maior];
        vet[maior] = aux;

        heapify (vet, qtd, maior);
    }
}

void heapSort (int vet[], int qtd) {
    for (int i = (qtd / 2) - 1; i >= 0; i--) 
        heapify (vet, qtd, i);

    for (int i = qtd - 1; i > 0; i--) {
        int aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;

        heapify (vet, i, 0);
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
    heapSort (vetor, qtd);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("----- HEAP SORT -----\n");
    imprime (vetor, qtd);
    printf("Tempo: %.5f segundos.\n", tempo);

    return 0;
}