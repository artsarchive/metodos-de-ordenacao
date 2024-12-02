#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Referência: 
    https://www.geeksforgeeks.org/shell-sort/
    https://homepages.dcc.ufmg.br/~cunha/teaching/20121/aeds2/shellsort.pdf
    https://homepages.dcc.ufmg.br/~clodoveu/files/AEDS2/AEDS2.11%20Shellsort.pdf
*/

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
    shellSort (vetor, qtd);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("----- SHELL SORT -----\n");
    imprime (vetor, qtd);
    printf("Tempo: %.5f segundos.\n", tempo);

    return 0;
}