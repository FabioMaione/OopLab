
#include "Biblioteca.h"
#include <functional>
/*
Sia A l'autore che ha scritto piu' libri nella biblioteca.
(Se piu' autori hanno questa proprieta', prendere il primo
di questi che compare nella biblioteca.) 
Restituire la somma dei prezzi di tutti i libri scritti da A.

Se non sono presenti libri nella biblioteca, restituire -1.
            
*/
int Biblioteca::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(biblioteca.empty()) 
        return -1;
    string maggiore = "";
    int max = 0;
    for(auto it = biblioteca.begin(); it != biblioteca.end(); it++){
        string corrente = it->getAutore(); int conta = 0;
        for(auto it2 = biblioteca.begin(); it2 != biblioteca.end(); it2++)
            if(it2->getAutore() == corrente)
                conta++;
        if(conta > max){
            max = conta;
            maggiore = corrente;
        }
    }

    int somma = 0;
    for(auto it : biblioteca)
        if(it.getAutore() == maggiore)
            somma += it.getPrezzo();
    return somma;
}

/*
Determinare la mediana dei libri ottenuta considerando la seguente relazione d'ordine:

Un libro L1 precede un libro L2 se il prezzo di L1 e' minore del prezzo di L2 e a parita' di prezzo, il tipo di L1 precede il tipo di L2 (NARRATIVA precede GIALLO precede SAGGISTICA).

Restituire il prezzo del libro che si trova in corrispondenza della mediana.

Nel caso in cui non ci siano libri presenti nella biblioteca, restituire -1.

NOTA BENE: calcolare mediana nel seguente modo: dopo aver ordinato gli oggetti in modo crescente,
si prende quello presente nel mezzo (utilizzare la divisione intera: size/2). 
            
*/
bool confronta(const Libro l1, const Libro l2){
    return (
        (l1.getPrezzo() < l2.getPrezzo()) ||
            ((l1.getPrezzo() == l2.getPrezzo()) && (l1.getTipo() < l2.getTipo()))
    );
}

int Biblioteca::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(biblioteca.empty())
        return -1;
    list<Libro> ordinati(biblioteca.begin(), biblioteca.end());
    ordinati.sort(confronta);
    list<Libro>::iterator it = ordinati.begin();
    advance(it, ordinati.size()/2);
    return it->getPrezzo();
}

/*
Data la seguente definizione:
Un libro L1 ha un riferimento ad un Libro L2 se:
- L1 ha un riferimento a L2, oppure
- L1 ha un riferimento a C3 e C3 ha un riferimento a C2.

Sia L il libro con il piu' alto numero di riferimenti, il metodo deve restituire il numero di libri con cui L ha un riferimento.

Nel caso in cui non ci siano libri nella biblioteca restituisce -1.
            
*/
bool riferimento(list<Libro> riferisce){
    return true;
}

int Biblioteca::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(biblioteca.empty())
        return -1;
    

    
    return 1;
}

/*
Data la seguente definizione:
Un libro L1 ha un riferimento ad un Libro L2 se:
- L1 ha un riferimento a L2, oppure
- L1 ha un riferimento a C3 e C3 ha un riferimento a C2.

Sia L il primo libro della biblioteca, il metodo deve restituire il numero di libri con cui L ha un riferimento.

Nel caso in cui non ci siano libri nella biblioteca restituisce -1.
            
*/
int Biblioteca::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(biblioteca.empty())
        return -1;
    
}


