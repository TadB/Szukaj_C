#include "szukaj.h"
#include "power.h"

int find(char *sentence, char *search){
    char *it;
    int i, len, fingerprint, origin;
    unsigned long long int hBufor=0;

    it = sentence;
    len = length(search);
    origin = hash(search, len, &hBufor); //obliczenie fingerprinta szukanego ciagu znakow
    hBufor=0;
    for(i=0;(*(it+len-1))!='\n';it++, i++){
        fingerprint = hash(it, len, &hBufor);
        if(fingerprint == origin){
            if(check(it, search)==0)
                return(i);
        }
    }
    return(-1); //nic nie znaleziono


}

int hash(char *sequence, int howMany, unsigned long long int* bMod){
//{{{zmienne
    char *input;
    char oldHOD; //old high-order digit
    char newLOD; //new low-order digit
    int modulo=17;
    int shift = 3;
    unsigned long long int sum=0, temp=0;
    int result=0;
//}}}
    input = sequence;
    howMany--;

    //pierwsze uruchomienie funkcji hashujacej, oblicza caly hash
    if((*bMod)==0){
        for(; howMany>=0; howMany--){
            temp=power(shift, howMany);
            sum+=(*input)*temp;
            input++;
        }
    }
    //kolejne uruchomienie funkcji hashujacej dla nowego ciagu (rozniacego sie tylko jednym znakiem od poprzedniego) - oblczanie na podtawie starej zmiennej
    //Oszczednosc mocy obliczeniowej i czasu. Mniejsza zlozonosc, brak koniecznosci przeliczania kolejny raz tych samych liczb
    else{
        newLOD = *(sequence+howMany); //wartosc najmniej znaczacego znaku (o najmniej znaczacej wadze) dla nowej wartosci hash
        oldHOD = *(sequence-1); //wartosc najwazniejszego znaku(o najwiekszej wadze) dla starej wartosci
        sum = (((*bMod)-(oldHOD*power(shift, howMany)))*shift )+ newLOD;
    }
    *bMod = sum;
    result = sum%modulo;
    return(result);
}

int length(char *input){
    char *it;
    int counter;

    it = input;
    for(it=input; (*it)!='\n'; it++){
        counter++;
    }
    return(counter);

}

int check(char *suspect, char *word){
    char *toFind = word;
    char *it = suspect;
    for(; (*toFind)!='\n'; toFind++, it++){
        if((*toFind)!=(*it))
            return -1;
    }
    return 0;
}
