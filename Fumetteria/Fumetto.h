
#ifndef Fumetto_H_
#define Fumetto_H_

#include <iostream>
#include <string>

using namespace std;


enum Tipo { KODOMO = 0, SPOKON, GEKIGA };
#include <algorithm>
#include <set>
    

class Fumetto
{
private:
    string titolo;
    string autore;
    int prezzo;
    Tipo tipo;
    string riferimentoA;
    
public:
    Fumetto(string _titolo = "", string _autore = "", int _prezzo = 0, Tipo _tipo = KODOMO, string _riferimentoA = "") : titolo(_titolo), autore(_autore), prezzo(_prezzo), tipo(_tipo), riferimentoA(_riferimentoA) {}

    string getTitolo() const { return titolo; }
    void setTitolo(string v) { titolo = v; }

    string getAutore() const { return autore; }
    void setAutore(string v) { autore = v; }

    int getPrezzo() const { return prezzo; }
    void setPrezzo(int v) { prezzo = v; }

    Tipo getTipo() const { return tipo; }
    void setTipo(Tipo v) { tipo = v; }

    string getRiferimentoA() const { return riferimentoA; }
    void setRiferimentoA(string v) { riferimentoA = v; }

    

    bool operator==(const Fumetto& right) const { 
        return titolo == right.titolo && autore == right.autore && prezzo == right.prezzo && tipo == right.tipo && riferimentoA == right.riferimentoA; 
    }

    bool operator<(const Fumetto& right) const { 
        return titolo < right.titolo && autore < right.autore && prezzo < right.prezzo && tipo < right.tipo && riferimentoA < right.riferimentoA; 
    }

friend ostream& operator<<(ostream& out, const Fumetto& x) { return out << "[" << x.titolo << ", " << x.autore << ", " << x.prezzo << ", " << x.tipo << ", " << x.riferimentoA << "]"; }
};

#endif
