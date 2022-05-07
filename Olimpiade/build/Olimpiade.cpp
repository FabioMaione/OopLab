
#include "Olimpiade.h"

/*
Restituire la nazione che ha speso meno. Ogni nazione paga i suoi atleti come segue:
	- 10.000 Euro per ogni medaglia di bronzo,
	- 15.000 Euro per ogni medaglia di argento,
	- 20.000 Euro per ogni medaglia di oro.	
In caso siano presenti due o piu' nazioni con la stessa spesa minima restituire 
la seconda in ordine di apparizione nella lista di atleti.
Se non sono presenti atleti, restituire "-1".           
*/

int totale (int oro, int argento, int bronzo){
    return(oro*20000 + argento*15000 + bronzo*10000);
}

string Olimpiade::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(atleti.empty())
        return "-1";

    int min = INT_MAX;
    string nazioneEconomica = "";
    vector<string>economicheUguali;
    for(auto i : atleti){
        string nazioneCorrente = i.getNazione();
        int minCorrente = 0;
        for(auto j : atleti)
            if(j.getNazione() == nazioneCorrente)
                minCorrente += totale(j.getNumeroOri(), j.getNumeroArgenti(), j.getNumeroBronzi());

        if(minCorrente == min)
            economicheUguali.push_back(nazioneCorrente);
        if(minCorrente < min){
            economicheUguali.clear();
            min = minCorrente;
            nazioneEconomica = nazioneCorrente;
            economicheUguali.push_back(nazioneCorrente);
        }
    }
    
    return economicheUguali.size() > 1 ? economicheUguali[1] : nazioneEconomica;
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
    if(atleti.empty() || atleti.size() < 3)
        return -1;
    
    int x = 0;
    auto it = atleti.begin();
    advance(it, 2);
    string terzo = it->getAtleta();
    for(auto j : atleti)
        if(j.getAtleta() == terzo)
            x += j.getNumeroOri();
    

    return -2;
}

/*
Creare una lista di nazioni ordinate in ordine descrescente in base al punteggio ottenuto, 
e a parita' di punteggio in ordine alfabetico.
Sia N_ori il numero di ori, N_argenti il numero di argenti, N_bronzi il numero di bronzi,
vinti dagli atleti di una nazione, il punteggio ottenuto da questa nazione e' calcolato come: 
	N_ori * 3 + N_argenti * 2 + N_bronzi
Restituire la nazione in ultima posizione nella lista cosi' ottenuta.
Se non sono presenti atleti, restituire "-1".
ATTENZIONE: Non modificare la lista atleti.      
*/

int punteggio (Atleta a){
    return a.getNumeroOri()*3 + a.getNumeroArgenti()*2 + a.getNumeroBronzi();
}

bool ordine(pair<string, int>p1, pair<string, int>p2){
    return (p2.second < p1.second) ||
            (p2.second == p1.second && p1.first < p2.first);
}

string Olimpiade::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(atleti.empty())
        return "-1";
    list<string> nazioniOrdinate;
    for(auto it : atleti)
        nazioniOrdinate.push_back(it.getNazione());
    nazioniOrdinate.sort();
    nazioniOrdinate.unique();

    list<pair<string, int>> setNazioni;
    for(auto i : nazioniOrdinate){
        int punti = 0;
        for(auto j: atleti)
            if(j.getNazione() == i)
                punti += punteggio(j);
        setNazioni.push_back(make_pair(i, punti));
    }
    setNazioni.sort(ordine);
    return setNazioni.back().first;
}

/*
Sia N la nazione con il maggior numero di atleti (In caso di piu` nazioni si consideri la prima in ordine alfabetico).
Restituire il nome dell'atleta meno giovane appartenente alla nazione N (In caso di piu` atleti 
si consideri il primo in ordine alfabetico).
Se non sono presenti atleti, restituire "-1".
*/

string Olimpiade::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(atleti.empty())
        return "-1";

    string nazionePiuAtleti;
    int maxAtleti = 0;
    for(auto i : atleti){
        string corrente = i.getNazione();
        int conta = 0;
        for(auto j : atleti)
            if(corrente == j.getNazione())
                conta++;
        if((conta > maxAtleti) || (conta == maxAtleti && corrente < nazionePiuAtleti)){
            nazionePiuAtleti = corrente;
            maxAtleti = conta;
        }
    }

    list<string>atletiVecchi;
    int eta = 0;
    for(auto p : atleti){
        if(p.getNazione() == nazionePiuAtleti){
            if(p.getEta() == eta)
                atletiVecchi.push_back(p.getAtleta());
            if(p.getEta() > eta){
                eta = p.getEta();
                atletiVecchi.clear();
                atletiVecchi.push_back(p.getAtleta());
            }
        }
    }
    
    atletiVecchi.sort();       
    return atletiVecchi.front();
}


