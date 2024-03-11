#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5

int main(){
    char s[100];
    FILE * f1 =fopen("tutte le parole della lingua inglese .txt","r");
    FILE * f2 =fopen("parole vere.txt","w");
    if (f1 == NULL) {
        printf("Errore di apertura file 'tutte le parole della lingua inglese'.");
        exit(1);
    }
    if (f2 == NULL) {
        printf("Errore di apertura file 'parole vere'.");
        exit(1);
    }
    while(!feof(f1)){
        fgets(s,100,f1);
        if(strlen(s)==6){
            fputs(s,f2);
            }
    }
    fclose(f1);
    fclose(f2);

return 0;
}
