#include "power.h"

long int power(int base, int power){
    int i;
    long int store=base;
    for(i=0; i<power; i++){
        store*=store;
    }
    return store;
}
