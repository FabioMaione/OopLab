
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

    list<string> autori;
    for(auto it = biblioteca.begin(); it != biblioteca.end(); it++)
        autori.push_back(it->getAutore());

    set<string> found;
    for (list<string>::iterator x = autori.begin(); x != autori.end();)
        if (!found.insert(*x).second) 
            x = autori.erase(x);
        else 
            ++x;

    vector<int> numeroLibri(autori.size(), 0);

    for(int i = 0; i < autori.size(); i++){
        for(auto it2 = biblioteca.begin(); it2 != biblioteca.end(); it2++){
            list<string>::iterator pos = autori.begin();
            advance(pos, i);
            string corrente = *pos;
            if(it2->getAutore() == corrente)
                numeroLibri[i]++;
        }
    }

    int massimo = 0;
    int indice = 0;
    for(int i = 0; i < numeroLibri.size(); i++)
        if(numeroLibri[i] > massimo){
            massimo = numeroLibri[i];
            indice = i;
        }
    list<string>::iterator posizione = autori.begin();
    advance(posizione, indice);
    string autoreMassimo = *posizione;

    int sommaPrezzi = 0;
    for(auto it3 = biblioteca.begin(); it3 != biblioteca.end(); it3++)
        if(it3->getAutore() == autoreMassimo)
            sommaPrezzi += it3->getPrezzo();
    return sommaPrezzi;
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


