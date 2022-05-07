
#ifndef Libro_H_
#define Libro_H_

#include <iostream>
#include <string>

using namespace std;


enum Tipo { NARRATIVA = 0, GIALLO, SAGGISTICA };
#include <algorithm>
#include <set>
    

class Libro
{
private:
    string nomeLibro;
    string autore;
    int prezzo;
    Tipo tipo;
    string riferimentoA;
    
public:
    Libro(string _nomeLibro = "", string _autore = "", int _prezzo = 0, Tipo _tipo = NARRATIVA, string _riferimentoA = "") : nomeLibro(_nomeLibro), autore(_autore), prezzo(_prezzo), tipo(_tipo), riferimentoA(_riferimentoA) {}

    string getNomeLibro() const { return nomeLibro; }
    void setNomeLibro(string v) { nomeLibro = v; }

    string getAutore() const { return autore; }
    void setAutore(string v) { autore = v; }

    int getPrezzo() const { return prezzo; }
    void setPrezzo(int v) { prezzo = v; }

    Tipo getTipo() const { return tipo; }
    void setTipo(Tipo v) { tipo = v; }

    string getRiferimentoA() const { return riferimentoA; }
    void setRiferimentoA(string v) { riferimentoA = v; }

    

    bool operator==(const Libro& right) const {
         return nomeLibro == right.nomeLibro && autore == right.autore && prezzo == right.prezzo && tipo == right.tipo && riferimentoA == right.riferimentoA; 
    }
    bool operator<(const Libro& right) const {
         return nomeLibro < right.nomeLibro && autore < right.autore && prezzo < right.prezzo && tipo < right.tipo && riferimentoA < right.riferimentoA; 
    }
    bool operator<=(const Libro& right) const {
         return nomeLibro <= right.nomeLibro && autore <= right.autore && prezzo <= right.prezzo && tipo <= right.tipo && riferimentoA <= right.riferimentoA; 
    }
    bool operator>(const Libro& right) const {
         return nomeLibro > right.nomeLibro && autore > right.autore && prezzo > right.prezzo && tipo > right.tipo && riferimentoA > right.riferimentoA; 
    }

friend ostream& operator<<(ostream& out, const Libro& x) { return out << "[" << x.nomeLibro << ", " << x.autore << ", " << x.prezzo << ", " << x.tipo << ", " << x.riferimentoA << "]"; }
};

#endif
