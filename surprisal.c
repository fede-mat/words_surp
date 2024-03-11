#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_PAROLA 100

// Funzione per calcolare il surprisal di una parola data la matrice delle probabilità
float calcolaSurprisal(char *parola, float frequenze[][5]) {
    float surprisal = 0.0;
    int lunghezza = strlen(parola);

    for (int i = 0; i < lunghezza; i++) {
        char carattere = tolower(parola[i]);
        if (carattere >= 'a' && carattere <= 'z') {
            int indice = carattere - 'a';
            surprisal -= log(frequenze[indice][i]);
        }
    }

    return surprisal;
}

int main() {
    FILE *parole_in = fopen("parole_vere.txt", "r");
    FILE *statistiche_in = fopen("statistiche.txt", "r");
    FILE *surprisal_out = fopen("surprisal.txt", "w");

    if (parole_in == NULL || statistiche_in == NULL || surprisal_out == NULL) {
        printf("Errore nell'apertura dei file!");
        exit(EXIT_FAILURE);
    }

    // Lettura delle frequenze dal file statistiche.txt
    float frequenze[26][5];
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 5; j++) {
            if (fscanf(statistiche_in, "%f", &frequenze[i][j]) != 1) {
                printf("Errore nella lettura delle frequenze!");
                exit(EXIT_FAILURE);
            }
        }
    }

    char parola[MAX_PAROLA];
    while (fscanf(parole_in, "%s", parola) != EOF) {
        float surprisal = calcolaSurprisal(parola, frequenze);
        fprintf(surprisal_out, "%s;%.4f\n", parola, surprisal);
    }

    fclose(parole_in);
    fclose(statistiche_in);
    fclose(surprisal_out);

    return 0;
}
