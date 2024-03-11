#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAROLE 1000
#define MAX_LUNGHEZZA_PAROLA 100

typedef struct {
    char parola[MAX_LUNGHEZZA_PAROLA];
    float surprisal;
} ParolaSurprisal;

// Modifica qui per ordinare in modo crescente
int comparaSurprisal(const void *a, const void *b) {
    ParolaSurprisal *psA = (ParolaSurprisal *)a;
    ParolaSurprisal *psB = (ParolaSurprisal *)b;
    return (psA->surprisal > psB->surprisal) - (psA->surprisal < psB->surprisal);
}

int main() {
    FILE *file = fopen("surprisal.txt", "r");
    if (!file) {
        perror("Errore nell'apertura del file surprisal.txt");
        return EXIT_FAILURE;
    }

    ParolaSurprisal parole[MAX_PAROLE];
    int numParole = 0;

    while (fscanf(file, "%[^;];%f", parole[numParole].parola, &parole[numParole].surprisal) == 2) {
        numParole++;
        if (numParole >= MAX_PAROLE) break;
        // Consuma l'eventuale newline dopo ogni lettura
        fgetc(file);
    }
    fclose(file);

    qsort(parole, numParole, sizeof(ParolaSurprisal), comparaSurprisal);

    FILE *output = fopen("elenco.txt", "w");
    if (!output) {
        perror("Errore nell'apertura del file elenco.txt");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < numParole; i++) {
        fprintf(output, "%s;%.4f\n", parole[i].parola, parole[i].surprisal);
    }

    fclose(output);

    printf("Elenco ordinato salvato in elenco.txt.\n");

    return 0;
}
