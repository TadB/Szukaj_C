#include "power.h"

unsigned long long int power(int base, int power){
    int i;
    unsigned long long int store=base;
    if(power == 0)
        return 1;
    for(i=1; i<power; i++){
        store*=store;
    }
    return store;
}
