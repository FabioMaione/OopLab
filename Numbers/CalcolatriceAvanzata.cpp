
#include "CalcolatriceAvanzata.h"


/*
Un numero P e` primo se e` > 1 ed e` divisibile solo per 1 e per P.
Una tripla di numeri C=(num1,num2,num3) e` bilanciata se esattamente uno tra num1 e num2 e` primo.
Restituire il numero di triple bilanciate presenti nella lista.
Se non sono presenti triple di numeri, restituire -1.        
*/

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n ==2) return true;
   for(int i = 2; i <= n/2; ++i)
      if(n != i && n%i == 0)
        return false;
   return true;
}

bool bilanciata(TriplaNumeri a){
    return isPrime(a.getNum1()) && !isPrime(a.getNum2()) ||
               !isPrime(a.getNum1()) && isPrime(a.getNum2());
}

int CalcolatriceAvanzata::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(numeri.empty())
        return -1;
    int contaBilanciate = 0;
    for(auto i : numeri){
            if(bilanciata(i))
                contaBilanciate++;
    }
    return contaBilanciate;
}

/*
Restituire il num1 della terza tripla della lista ordinata nel seguente modo:
- Prima tutte le triple con il valore piu` alto di num1.
- A parita` di valore del num1, le triple con il valore piu` alto di num2.
- A parita` di valore del num2, le triple con il valore piu` alto di num3.
Se la lista ha meno di 3 elementi restituire -1.
ATTENZIONE: NON MODIFICARE la lista di numeri ma creare una copia temporanea.        
*/

bool ordine(TriplaNumeri a1, TriplaNumeri a2){
    return a1.getNum1() > a2.getNum1() ||
            (a1.getNum1() == a2.getNum1()) && (a1.getNum2() > a2.getNum2()) ||
                (a1.getNum1() == a2.getNum1()) && (a1.getNum2() == a2.getNum1()) && (a1.getNum3() > a2.getNum3());
}

int CalcolatriceAvanzata::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(numeri.size() < 3)
        return -1;
    vector<TriplaNumeri>ordinata(numeri.begin(), numeri.end());
    sort(ordinata.begin(), ordinata.end(), ordine);
    return ordinata[2].getNum1();
}

/*
Sia LD la lista di triple duplicate.
Una tripla e` considerata duplicata se i primi due numeri sono uguali.
Restituire il massimo della somma tra num1 e num2 degli elementi in LD.

Esempio:
(1,2,4) (1,2,6) (3,4,7) (3,4,7) (3,4,8) (5,6,2) (6,5,2)
Le triple duplicate sono (1,2,_) e (3,4,_).
La somma di num1 e num2 della prima tripla e` pari a 3.
La somma di num1 e num2 della seconda tripla a 7.
Quindi il metodo deve restituire 7.
Se la lista e` vuota o non ha duplicati restituire -1.       
*/

bool duplicata(TriplaNumeri a1, TriplaNumeri a2){
    return a1.getNum1() == a2.getNum1() && a1.getNum2() == a2.getNum2();
}

int CalcolatriceAvanzata::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(numeri.empty())
        return -1;
    vector<TriplaNumeri>vettoreNum(numeri.begin(), numeri.end());
    vector<TriplaNumeri>LD;
    for(unsigned i = 0; i < vettoreNum.size(); ++i)
        for(unsigned j = 0; j < vettoreNum.size(); ++j) 
            if(duplicata(vettoreNum[i], vettoreNum[j]) && i != j)
                LD.push_back(vettoreNum[i]);
    
    int maxLD = 0;
    for(auto i : LD)
        if(i.getNum1()+i.getNum2() > maxLD)
            maxLD = i.getNum1()+i.getNum2();
            
    return LD.empty() ? -1 : maxLD;
}

/*
Sia P il primo numero a 4 cifre della lista (considerando solo il num3).
Sia PMAX il numero max che e` possibile comporre usando tutte le cifre di P.
Sia PMIN il numero min che e` possibile comporre usando tutte le cifre di P.
Restituire PMAX-PMIN.
Ad esempio, sia P = 1243, allora PMAX=4321 e PMIN=1234.
Se la lista e` vuota o se non ha numeri a 4 cifre restituire -1.       
*/

int CalcolatriceAvanzata::metodo4()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(numeri.empty())
        return -1;
    int p = 0;
    for(auto i : numeri)
        if(i.getNum3() > 999 && i.getNum3() < 10000){
            p = i.getNum3();
            break;
        }
    if(p == 0)
        return -1;
    vector<int>numero;
    while(p){
        int c = p%10;
        numero.push_back(c);
        p/=10;
    }
    sort(numero.begin(), numero.end());
    int Pmin = 0;
    int Pmax = 0;

    int j = 1;
    int c = 1000;
    for(unsigned i = 0; i < 4; ++i){
        Pmin += numero[i] * c;
        Pmax += numero[i] * j;
        j*=10; c/=10;
    }
    return Pmax-Pmin;
}


