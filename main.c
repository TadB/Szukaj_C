#include<stdio.h>
#include"szukaj.h"
#define N1 100
#define N2 50

int main(){
    char phrase[N1], toSearch[N2];
    int index=0;
    char *tmp;
    fgets(phrase, N1, stdin);
    fgets(toSearch, N2, stdin);
    tmp=phrase;
    puts("trafienia na indeksach: ");
    // while(1){
        index=find(tmp, toSearch);
        // if(index==-1)
            // break;
        printf(" | %d| ", index);
        // getchar();
        // tmp+=index+1;
    // }
    return 0;
}
