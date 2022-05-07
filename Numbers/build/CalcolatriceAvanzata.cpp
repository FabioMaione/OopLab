
#include "CalcolatriceAvanzata.h"

/*
Un numero P e` primo se e` > 1 ed e` divisibile solo per 1 e per P.
Una tripla di numeri C=(num1,num2,num3) e` bilanciata se esattamente uno tra num1 e num2 e` primo.
Restituire il numero di triple bilanciate presenti nella lista.

Se non sono presenti triple di numeri, restituire -1.
            
*/


int CalcolatriceAvanzata::metodo1()
{
    /* IMPLEMENTARE QUESTO METODO */
    if(numeri.empty())
        return -1;

}

/*
Restituire il num1 della terza tripla della lista ordinata nel seguente modo:
- Prima tutte le triple con il valore piu` alto di num1.
- A parita` di valore del num1, le triple con il valore piu` alto di num2.
- A parita` di valore del num2, le triple con il valore piu` alto di num3.

Se la lista ha meno di 3 elementi restituire -1.
ATTENZIONE: NON MODIFICARE la lista di numeri ma creare una copia temporanea.
            
*/
int CalcolatriceAvanzata::metodo2()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
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
int CalcolatriceAvanzata::metodo3()
{
    /* IMPLEMENTARE QUESTO METODO */
    return -1;
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
    return -1;
}


