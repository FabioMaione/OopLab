
#ifndef Biblioteca_H
#define Biblioteca_H

#include "Libro.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

Questa classe contiene una biblioteca di libri. Ogni libro e` caratterizzato dalle seguenti informazioni:

    - nomeLibro: il nome di un libro (string);

    - autore: il nome dell'autore che ha scritto il libro (string);

    - prezzo: il prezzo del libro (int);

    - tipo: il tipo del libro (un enumerativo con 3 possibili valori: NARRATIVA, GIALLO, SAGGISTICA);

    - riferimentoA: il riferimento ad un altro libro, stringa vuota se non esiste (string).
    
    Implementare nel file Biblioteca.cpp i metodi della classe Biblioteca.
    
*/
class Biblioteca   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Libro> biblioteca;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(Libro l) {biblioteca.push_back(l); return true;}
    
    
    inline list<Libro>& getContent() { return biblioteca; }
};
#endif
