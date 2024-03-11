#include<stdio.h>
#include<stdlib.h>
#define A 97
#define Z 122

int main(){
    FILE * f=fopen("parole.txt","w");
    if (f == NULL) {
        printf("Errore di apertura file.");
        exit(1);
    }
    int a,b,c,d,e;
    for(a=A;a<=Z;a++){
        for(b=A;b<=Z;b++){
            for(c=A;c<=Z;c++){
                for(d=A;d<=Z;d++){
                    for(e=A;e<=Z;e++){
                        fprintf(f,"%c%c%c%c%c\n",a,b,c,d,e);
                    }
                }
            }
        }
    }
    fclose(f);
return 0;
}
