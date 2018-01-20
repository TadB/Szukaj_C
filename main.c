#include<stdio.h>
#include"szukaj.h"
#define N1 100
#define N2 50

int main(){
    char phrase[N1], toSearch[N2];
    fgets(phrase, N1, stdin);
    fgets(toSearch, N2, stdin);
    int index[N1], i=0, temp=0;

    while(1){
        temp=find(phrase, toSearch);
        if(temp==-1)
            break;
        index[i++]=temp;
    }
    puts("trafienia na indeksach: ");
    for(; i>0; i--){
        printf(" | %d| ", index[i]);
    }
    return 0;
}
