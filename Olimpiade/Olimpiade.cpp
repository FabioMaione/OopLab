
#include "Olimpiade.h"
#include <set>
#include <algorithm>
/*
Restituire la nazione che ha speso meno. Ogni nazione paga i suoi atleti come segue:
	- 10.000 Euro per ogni medaglia di bronzo,
	- 15.000 Euro per ogni medaglia di argento,
	- 20.000 Euro per ogni medaglia di oro.
	
In caso siano presenti due o piu' nazioni con la stessa spesa minima restituire la seconda in ordine di apparizione nella lista di atleti.

Se non sono presenti atleti, restituire "-1".
            
*/
string Olimpiade::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(atleti.empty())
        return "-1";
    list<string> nazioni;
    for(auto it = atleti.begin(); it != atleti.end(); it++)
        nazioni.push_back(it->getNazione());

    set<string> trovato;
    for (list<string>::iterator x = nazioni.begin(); x != nazioni.end();)
        if (!trovato.insert(*x).second) 
            x = nazioni.erase(x);
        else 
            ++x;

    vector<int> spesaNazioni(nazioni.size(), 0);
    for(int i = 0; i < spesaNazioni.size(); i++){
        for(auto it = atleti.begin(); it != atleti.end(); it++){
            list<string>::iterator pos = nazioni.begin();
            advance(pos, i);
            string corrent = *pos;
            if(it->getNazione() == corrent){
                spesaNazioni[i] += (*it).getNumeroArgenti()*15000 + it->getNumeroBronzi()*10000 + it->getNumeroOri()*20000;
            }
        }
    }
    int spesaMinima = spesaNazioni[0];
    int indice = 0;
    for(int i = 0; i < spesaNazioni.size(); i++){
        if(spesaNazioni[i] < spesaMinima){
            spesaMinima = spesaNazioni[i];
            indice = i;
        }
    }
    list<string>::iterator posizione = nazioni.begin();
    advance(posizione, indice);
    return *posizione;
}

/*
Sia X il numero di ori vinti dal terzo atleta presente nella lista atleti. 

Sia N_ori il numero di ori, N_argenti il numero di argenti, N_bronzi il numero di bronzi,
vinti dagli atleti di una nazione, tale nazione si definisce vittoriosa se:
	N_ori > N_argenti > N_bronzi
ed inoltre, N_ori > X.

Restituire il numero di nazioni vittoriose. 

Se non sono presenti atleti oppure ne sono presenti meno di 3, restituire -1.

            
*/
int Olimpiade::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
}

/*
Creare una lista di nazioni ordinate in ordine descrescente in base al punteggio ottenuto, e a parita' di punteggio in ordine alfabetico.

Sia N_ori il numero di ori, N_argenti il numero di argenti, N_bronzi il numero di bronzi,
vinti dagli atleti di una nazione, il punteggio ottenuto da questa nazione e' calcolato come: 
	N_ori * 3 + N_argenti * 2 + N_bronzi

Restituire la nazione in ultima posizione nella lista cosi' ottenuta.

Se non sono presenti atleti, restituire "-1".

ATTENZIONE: Non modificare la lista atleti.
            
*/
string Olimpiade::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return "-1";
}

/*
Sia N la nazione con il maggior numero di atleti (In caso di piu` nazioni si consideri la prima in ordine alfabetico).
Restituire il nome dell'atleta meno giovane appartenente alla nazione N (In caso di piu` atleti si consideri il primo in ordine alfabetico).

Se non sono presenti atleti, restituire "-1".
            
*/

string Olimpiade::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(atleti.empty())
        return "-1";
}


