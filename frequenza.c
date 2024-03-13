#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    FILE *in = fopen("parole_vere.txt", "r");
    FILE *out = fopen("statistiche.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Errore nell'apertura dei file!");
        exit(EXIT_FAILURE);
    }

    float p[26][5] = {0.0};
    int cont = 0, i, j, k;
    char parola[7];

    while (fgets(parola, sizeof(parola), in) != NULL) {
        cont++;
        for (i = 0; i < strlen(parola) - 1; i++) { // -1 per escludere il carattere di newline
            p[abs(97 - parola[i])][i] = p[abs(97 - parola[i])][i] + 1;
        }
    }

    for (j = 0; j < 26; j++) {
        for (k = 0; k < 5; k++) {
            p[j][k] = p[j][k] / cont;
        }
    }

    for (j = 0; j < 26; j++) {
        for (k = 0; k < 5; k++) {
            fprintf(out, "%f ", p[j][k]);
        }
        fprintf(out, "\n");
    }

    fclose(in);
    fclose(out);

    return 0;
}
