#include<stdio.h>
#ifndef SZUKAJ_H
#define SZUKAJ_H

int hash(char *, int, int); //funkcja hashujaca - oblicza "wartosc" podanego slowa wg algorytmu
// bool check(char *); //pierwsze sprawdzenie, jesli nie przejdzie brak zgodnosci/ jesli zwroci true - podejrzenie o zgodnosc
bool check(char *, char *); //drugie sprawdzenie, malo efektywne ale wykonywane nie wiele razy, maly wplyw na zlozonosc obliczeniowa algorytmu

char *find(char *, char *); //glowna funkcja szukajaca podanego ciagu znakow w podanym zdaniu (przesylany adres zdania i szukanego ciagu)
#endif
