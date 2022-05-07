
#include "GestoreComputers.h"

/*
Calcolare il massimo delle medie dei prezzi dei computers prodotti da ogni produttore.

Utilizzare la divisione intera.

Se non sono presenti computers, restituire -1.
            
*/
int GestoreComputers::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(computers.empty())
        return -1;
    int max = 0;
    list<string>produttori;
    for(auto it : computers)
        produttori.push_back(it.getProduttore());
    
    produttori.sort();
    produttori.unique();

    for(auto i : produttori){
        int conta = 0;
        int somma = 0;
        for(auto it : computers){
            if(it.getProduttore() == i){
                somma += it.getPrezzo();
                conta++;
            }
        }
        if(conta > 0)
            somma /= conta;
        if (somma > max)
            max = somma;
    }
    return max;
}

/*
Determinare la mediana dei computers ottenuta considerando la seguente relazione d'ordine:

Un computer C1 precede un computer C2 se il prezzo di C1 e' minore del prezzo di C2 e a parita' di prezzo, il tipo di C1 precede il tipo di C2 (ULTRABOOK precede NETBOOK precede NOTEBOOK).

Restituire il prezzo del computer che si trova in corrispondenza della mediana.

Nel caso in cui non ci siano computers presenti nel gestore, restituire -1.

NOTA BENE: calcolare mediana nel seguente modo: dopo aver ordinato gli oggetti si prende quello presente nel mezzo (utilizzare la divisione intera). 
            
*/

bool precede(Computer c1, Computer c2){
    return (c1.getPrezzo() < c2.getPrezzo()) || 
                (c1.getPrezzo() == c2.getPrezzo() && c1.getTipo() < c2.getTipo());
}

int GestoreComputers::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(computers.empty())
        return -1;
    list<Computer>copia(computers);
    copia.sort(precede);
    auto mid = std::next(copia.begin(), copia.size() / 2);
    return mid->getPrezzo();
}

/*
Siano P1 e P2 produttori distinti tali per cui la somma dei prezzi di tutti i prodotti di P1 meno 
la somma dei prezzi di tutti i prodotti di P2 e' minima rispetto ad ogni altra coppia di produttori.
Determinare la posizione del primo produttore tra P1 e P2 in ordine di occorrenza nell'elenco.

Se non sono presenti computers o e' presente un solo produttore, restituire -1.

NOTA BENE: nel caso ci siano piu' coppie di produttori distinti che verificano la condizione, 
considerare il primo produttore in ordine di occorrenza nell'elenco che si trova in una di queste coppie.
            
*/
int GestoreComputers::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(computers.empty())
        return -1;
    vector<string>produttori;
    for(auto i : computers)
        produttori.push_back(i.getProduttore());
    sort(produttori.begin(), produttori.end());
    unique(produttori.begin(), produttori.end());
    if(produttori.size() < 2)
        return -1;
    vector<int>somme(produttori.size(), 0);

    for(int i = 0; i < produttori.size(); ++i)
        for(auto j : computers)
            if(produttori[i] == j.getProduttore())
                somme[i] += j.getPrezzo();

    int posP1 = 0;
    int posP2 = 0;
    int min = 0;

    for(int i = 0; i < somme.size(); ++i){
        for(int j = 0; j < somme.size(); ++j){
            if(i != j){
                if(min > (somme[i]-somme[j])){
                    min = somme[i]-somme[j];
                    posP1 = i, posP2 = j;
                }
            }
        }
    }
    string p1, p2;
    for(int i = 0; i < produttori.size(); ++i){
        if(i == posP1)
            p1 = produttori[i];
        if(i == posP2)
            p2 = produttori[i];
    } 
    int indice = 0;
    int ind = 0;
    for(auto i : computers){
        if(i.getProduttore() == p1 || i.getProduttore() == p2){
            indice = ind;
            break;
        }
        else 
            ind++;
    }
    return indice;
}

/*
Data la seguente definizione:
Un computer C1 e' connesso con un Computer C2 se:
- C1 e' connesso con C2, oppure
- C1 e' connesso con C3 e C3 e' connesso con C2.

Il metodo deve restituire il numero massimo di computer connessi tra loro.

Nel caso in cui non ci siano computers restituisce -1.
            
*/
int GestoreComputers::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}


