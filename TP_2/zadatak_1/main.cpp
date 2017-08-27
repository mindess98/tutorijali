/*
Prosti brojevi su oni prirodni brojevi koji imaju tačno dva različita djelioca
u skupu ℕ: jedinicu i samog sebe (prividno slična definicija po kojoj su
prosti brojevi oni i samo oni koji su djeljivi samo sa jedinicom i sa samim
sobom nije u potpunosti tačna, razmislite zašto). Napišite prvo funkciju
“DaLiJeProst” sa jednim parametrom “n” koji predstavlja neki cijeli broj, a
koja kao rezultat vraća logičku vrijednost “tačno” ili “netačno” u ovisnosti
od toga da li je parametar prost broj ili ne. Zatim napišite funkciju
“ProstiBrojeviUOpsegu”, također sa dva cjelobrojna parametra “a” i “b” koja
kao rezultat vraća vektor koji se sastoji od svih prostih brojeva u intervalu
od “a” do “b” uključivo (tj. svih prostih brojeva koji su veći ili jednaki od
“a”, a manji ili jednaki od “b”). Napisanu funkciju iskoristite u glavnom
programu koji traži da se sa tastature unesu dva cijela broja, a zatim za sve
cijele brojeve u opsegu između ta dva unesena broja ispisuje koji su prosti
brojevi u datom opsegu, ili informaciju da nema prostih brojeva u datom opsegu.
Dijalozi između korisnika i programa trebali bi izgledati poput sljedećih
(ovisno ima li ili nema prostih brojeva u zadanom opsegu):

    Unesite pocetnu i krajnu vrijednost: 15 30
    Prosti brojevi u rasponu od 15 do 30 su: 17, 19, 23, 29

    Unesite pocetnu i krajnu vrijednost: 24 28
    Nema prostih brojeva u rasponu od 24 do 28!

Pretpostavite da će korisnik unijeti smislene podatke, tj. nije potrebno
provjeravati da li su zaista uneseni cijeli brojevi.
*/


#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int main()
{
    std::cout<<"Unesite pocetnu i krajnju vrijednost: ";
    int a,b;
    std::cin>>a>>b;
    bool DaLiJeProst(int);

    vector<int> ProstiBrojeviUOpsegu(int,int);
    vector<int> prostiBrojevi(ProstiBrojeviUOpsegu(a, b));

    if(prostiBrojevi[0] == 0){
        std::cout<<"Nema prostih brojeva u rasponu od "<<a<<" do "<<b<<"!";
    }
    else{
        std::cout<<"Prosti brojevu u rasponu od "<<a<<" do "<<b<<" su: ";
        int ent = prostiBrojevi.size() - 1;
        for(int i = 0; i<prostiBrojevi.size() - 1; i++){
            if(prostiBrojevi[i+1] == 0){
                ent = i;
            break;
            }
            std::cout<<prostiBrojevi[i]<<", ";
        }
        std::cout<<prostiBrojevi[ent];
    }
    return 0;
}


bool DaLiJeProst(int a){
    if(a <= 1) return false;
    for(int i = 2; i <= sqrt(a); i++)
        if(a % i == 0) return false;
    return true;
}

vector<int> ProstiBrojeviUOpsegu(int a, int b){
    vector<int> sol(b-a+1);
    int c = 0;
    for(int i = a; i <= b ; i++){
        if(DaLiJeProst(i)){
            sol[c] = i;
            c++;
        }
    }
    return sol;
}
