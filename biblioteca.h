#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Procedimentos usados para teste!
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
//-------------------------------------

// BUBBLE SORT
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


// QUICKSORT e AUXILIARES
int divide (int vet[], int p, int r) { 
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

// HEAP SORT e AUXILIARES
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

// SHELL SHORT 
void shellSort(int vet[], int qtd) {
    int j, h = 1; 
    int x;

    do {
        h = h * 3 + 1;
    } while (h < qtd);

    do {
        h = h / 3; 
        for (int i = h; i < qtd; i++) {
            x = vet[i];
            j = i;

            while (j >= h && vet[j - h] > x) {
                vet[j] = vet[j - h];
                j = j - h;
            }

            vet[j] = x; 
        }
    } while (h != 1);
}

#endif