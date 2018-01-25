#include<stdio.h>
#include"szukaj.h"
#include"power.h"
#define N1 100
#define N2 50

int main(){

    char phrase[N1], toSearch[N2];
    int index=0;
    char *tmp;
    puts("podaj zdanie: ");
    fgets(phrase, N1, stdin);
    puts("podaj szukany wyraz do znalezienia: ");
    fgets(toSearch, N2, stdin);
    tmp=phrase;
    puts("trafienia na indeksach: ");
    index=find(tmp, toSearch);
    tmp+=index+1;
    printf(" |%d| ", index);
    return 0;
}
