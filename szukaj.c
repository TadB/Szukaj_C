#include "szukaj.h"
#include "exponent.h"

int find(char *sentence, char *search){
    char *it;
    int i, len, fingerprint, origin;
    long int hBufor=0;

    it = sentence;
    len = length(search);
    origin = hash(search, len, hBufor); //obliczenie fingerprinta szukanego ciagu znakow
    hBufor=0;
    for(i=0;(*(it+len))!='\n';it++, i++){
        fingerprint = hash(it, len, hBufor);
        if(fingerprint == origin){
            if(check(it, search))
                return(i);
        }
    }


}

//&bMod - adres zmiennej w ktorej przechowuje prawie obliczony hash //przed operacja modulo
//*sequence - adres poczatku (pierwszy wyraz) sprawdzanego fragmentu ciagu
int hash(char *sequence, int howMany, long int* bMod){
//{{{zmienne
    char *input;
    //int i=howMany;
    char oldHOD; //old high-order digit
    char newLOD; //new low-order digit
    int modulo=137;
    int shift = 7;
    long int sum=0;
    int result=0;
//}}}
    input = sequence;
    oldHOD = *(sequence-1); //wartosc najwazniejszego znaku(o najwiekszej wadze) dla starej wartosci hasha
    newLOD = *(sequence+howMany); //wartosc najmniej znaczacego znaku (o najmniej znaczacej wadze) dla nowej wartosci hash

    //pierwsze uruchomienie funkcji hashujacej, oblicza caly hash
    if((*bMod)==0){
        for(; howMany>0; howMany--){
            sum+=int(*input)*exp(shift, howMany);
        }
    }
    //kolejne uruchomienie funkcji hashujacej dla nowego ciagu (rozniacego sie tylko jednym znakiem od poprzedniego) - oblczanie na podtawie starej zmiennej
    //Oszczednosc mocy obliczeniowej i czasu. Mniejsza zlozonosc, brak koniecznosci przeliczania kolejny raz tych samych liczb
    else{
        sum = (*bMod-oldHOD*exp(shift, howMany))*shift + newLOD;
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

bool check(char *suspect, char *word){
    char *toFind = word;
    char *it = suspect;
    for(; (*toFind)!='\n'; toFind++, it++){
        if((*toFind)!=(*it))
            return false;
    }
    return true;
}
