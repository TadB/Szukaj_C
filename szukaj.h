#include<stdio.h>
#ifndef SZUKAJ_H
#define SZUKAJ_H

int hash(char *, int, unsigned long long int*); //funkcja hashujaca - oblicza "wartosc" podanego slowa wg algorytmu
int check(char *, char *); //drugie sprawdzenie, malo efektywne ale wykonywane nie wiele razy, maly wplyw na zlozonosc obliczeniowa algorytmu
int length(char *); //zwraca dlugosc ciagu znakow
int find(char *, char *); //glowna funkcja szukajaca podanego ciagu znakow w podanym zdaniu (przesylany adres zdania i szukanego ciagu)
#endif
