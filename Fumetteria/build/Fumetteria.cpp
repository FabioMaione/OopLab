
#include "Fumetteria.h"

/*
Sia A l'autore che ha scritto piu' fumetti nella fumetteria.
(Se piu' autori hanno questa proprieta', prendere il primo
di questi che compare nella fumetteria.) 
Restituire la somma dei prezzi di tutti i fumetti scritti da A.

Se non sono presenti fumetti nella fumetteria, restituire -1.
            
*/
int Fumetteria::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(fumetteria.empty())
        return -1;
    int maxFumetti = 0;
    string autoreMax;
    for(auto i : fumetteria){
        string corrente = i.getAutore();
        int contaFumetti = 0;
        for(auto j : fumetteria)
            if(j.getAutore() == corrente)
                contaFumetti++;
        if(contaFumetti > maxFumetti){
            maxFumetti = contaFumetti;
            autoreMax = corrente;
        }
    }
    int sommaPrezzi = 0;
    for(auto p : fumetteria)
        if(p.getAutore() == autoreMax)
            sommaPrezzi += p.getPrezzo();
    return sommaPrezzi;
}

/*
Determinare la mediana dei fumetti ottenuta considerando la seguente relazione d'ordine: 

Un fumetto F1 precede un fumetto F2 se il prezzo di F1 e' minore del prezzo di F2 e a parita' di prezzo, il tipo di F1 precede il tipo di F2 (KODOMO precede SPOKON precede GEKIGA).

Restituire il prezzo del fumetto che si trova in corrispondenza della mediana.

Nel caso in cui non ci siano fumetti presenti nella fumetteria, restituire -1.

NOTA BENE: calcolare mediana nel seguente modo: dopo aver ordinato gli oggetti in modo crescente,
si prende quello presente nel mezzo (utilizzare la divisione intera: size/2). 
            
*/
bool confronta(const Fumetto f1, const Fumetto f2){
    return (
        (f1.getPrezzo() < f2.getPrezzo()) ||
            ((f1.getPrezzo() == f2.getPrezzo()) && (f1.getTipo() < f2.getTipo()))
    );
}
int Fumetteria::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(fumetteria.empty())
        return -1;
    list<Fumetto>ordinati(fumetteria.begin(), fumetteria.end());
    ordinati.sort(confronta);
    list<Fumetto>::iterator centro = ordinati.begin();
    advance(centro, ordinati.size()/2);
    return centro->getPrezzo();
}

/*
Data la seguente definizione: 
Un fumetto F1 fa riferimento ad un fumetto F2 se:
- F1 fa riferimento a F2, oppure
- F1 fa riferimento a F3 e F3 fa riferimento a F2.

Sia F il fumetto con il piu' alto numero di riferimenti, il metodo deve restituire il numero di fumetti a cui F fa riferimento.

Nel caso in cui non ci siano fumetti nella fumetteria restituisce -1.
            
*/
int Fumetteria::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
Data la seguente definizione:
Un fumetto F1 fa riferimento ad un fumetto F2 se:
- F1 fa riferimento a F2, oppure
- F1 fa riferimento a F3 e F3 fa riferimento a F2.

Sia F il primo fumetto della fumetteria, il metodo deve restituire il numero di fumetti con cui F fa riferimento.

Nel caso in cui non ci siano fumetti nella fumetteria restituisce -1.
            
*/
int Fumetteria::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}


