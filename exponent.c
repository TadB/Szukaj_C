#include "exponent.h"

long int exp(int base, int exp){
    int i;
    long int store=base;
    for(i=0; i<exp; i++){
        store*=store;
    }
    return store;
}
