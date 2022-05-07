
#ifndef Fumetteria_H
#define Fumetteria_H

#include "Fumetto.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

Questa classe contiene una fumetteria. Ogni fumetto e` caratterizzato dalle seguenti informazioni:

    - titolo: il titolo del fumetto (string);

    - autore: il nome dell'autore che ha scritto il fumetto (string);

    - prezzo: il prezzo del fumetto (int);

    - tipo: il tipo del fumetto (un enumerativo con 3 possibili valori: KODOMO, SPOKON, GEKIGA);

    - riferimentoA: contiene il riferimento ad un altro fumetto, stringa vuota se non esiste (string).
    
    Implementare nel file Fumetteria.cpp i metodi della classe Fumetteria.
    
*/
class Fumetteria   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Fumetto> fumetteria;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(Fumetto f) {fumetteria.push_back(f); return true;}
    
    
    inline list<Fumetto>& getContent() { return fumetteria; }
};
#endif
