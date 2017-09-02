#include <iostream>

using namespace std;

template <typename T>
struct Cvor{
    T element;
    Cvor<T>* veza;
};

template <typename T>
Cvor<T>* KreirajPovezanuListu(T zavrsni);

template <typename T>
int BrojElemenata(Cvor<T>* pocetak);

template <typename T>
T SumaElemenata(Cvor<T>* pocetak);

template <typename T>
int BrojVecihOd(Cvor<T>* pocetak, T prag);

template <typename T>
void UnistiListu(Cvor<T>* pocetak);


int main()
{
    Cvor<double>* a = KreirajPovezanuListu(0.0);
    cout<<"U slijedu ima "<<BrojVecihOd(a, SumaElemenata(a) / BrojElemenata(a))<<" brojeva vecih od njihove aritmeticke sredine";
    UnistiListu(a);
    return 0;
}


template <typename T>
Cvor<T>* KreirajPovezanuListu(T zavrsni){
    cout<<"Unesite elemente liste ("<<zavrsni<<" za kraj) :";
    Cvor<T>* pocetak = nullptr;
    Cvor<T>* t = nullptr;

    T vrijednost;
    cin>>vrijednost;
    if(vrijednost == zavrsni) return pocetak;
    pocetak = t = new Cvor<T>();
    t->element = vrijednost;
    t->veza = nullptr;

    while(true){
        cin>>vrijednost;
        if(vrijednost == zavrsni) break;

        t->veza = new Cvor<T>();
        t = t->veza;
        t->element = vrijednost;
        t->veza = nullptr;
    }
    return pocetak;
}

template <typename T>
void UnistiListu(Cvor<T>* pocetak){
    while(pocetak != nullptr){
        Cvor<T>* temp;
        temp = pocetak->veza;
        delete pocetak;
        pocetak = temp;
    }
    return;
}

template <typename T>
int BrojElemenata(Cvor<T>* pocetak){
    int broj(0);
    while(pocetak != nullptr){
        broj++;
        pocetak = pocetak->veza;
    }
    return broj;
}

template <typename T>
T SumaElemenata(Cvor<T>* pocetak){
    T sum{};
    while(pocetak != nullptr){
        sum+=pocetak->element;
        pocetak = pocetak->veza;
    }
    return sum;
}

template <typename T>
int BrojVecihOd(Cvor<T>* pocetak, T prag){
    int broj{};
    while(pocetak != nullptr){
        if(pocetak->element > prag) broj++;
        pocetak = pocetak->veza;
    }
    return broj;
}
