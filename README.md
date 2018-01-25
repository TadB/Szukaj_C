Szukaj
Funkcja szukaj() na wejście powinna otrzymać wskaźnik do tablicy znaków. Zarówno dla wyrazu szukanego, jak i do zdania, w którym wyraz ma zostać znaleziony. Jeśli wyraz znajduje się w podanym zdaniu, zostaje zwrócony nr indeksu dla pierwszej litery szukanego wyrazu. Jeśli wyraz nie został znaleziony, funkcja zwraca wartość -1.
Do implementacji funkcji szukającej został wykorzystany algorytm Rabina-Karpa. NaPrzed właściwym sprawdzeniem, zostaje obliczona długość szukanego wyrazu poprzez zliczanie kolejnych znaków. Długość wyrazu jest potrzebna do wyliczenia wartości szukanego słowa, które odbywa się w funkcji hash(). Następnie podczas pierwszego sprawdzania funkcja hash() jest wywoływana dla kolejnych słów( o odpowiedniej długości) w przeszukiwanym zdaniu. Jeśli wartość zwracana przez funkcje hash() jest równa wartości obliczonej dla szukanego słowa, następuje dokładne sprawdzenie znak po znaku czy wyrazy napewno są identyczne.
Jeśli tak funkcja zwraca nr indeksu początku słowa, jeśli nie funkcja szuka dalej.

Szukany ciąg powinien być mniejszy od zdania, w którym użytkownik chce szukać. Po podaniu krótszego zdania niż szukany ciąg — występuje błąd: naruszenie ochrony pamięci. Wewnątrz funkcji nie jest sprawdzana długość zdania, ponieważ zliczanie kolejnych znaków jest nieoptymalne dla długich ciągów. Do funkcji jest przekazywany wskaźnik, więc nie ma możliwości skorzystania ze sprawdzenia wielkości tablicy przy użyciu funkcji sizeof().

Dla danych wejściowych, które nie są literami, np. "$%^&(" funkcja działa poprawnie, ponieważ algorytm pobiera wartości znaku z tablicy ASCII.
Do przeszukiwania zdania korzystamy z tablicy ASCII, więc wielkie i małe litery są rozróżnialne.
Funkcja była również przetestowana na szukanie pojedynczego znaku, słowa, które jest pierwszym słowem w zdaniu oraz ostatnim słowem w zdaniu. Dla każdych z tych przypadków zwróciła poprawny wynik.
