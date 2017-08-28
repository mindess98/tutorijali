/*
Napišite funkciju “IzdvojiElemente” sa dva parametra, od kojih je prvi vektor
 cijelih brojeva (tipa “int”), a drugi logička vrijednost “tačno” ili “netačno”.
 Funkcija treba da kao rezultat vrati novi vektor koji se sastoji od onih elemenata
 čija je suma cifara parna odnosno neparna, ovisno od toga da li drugi parametar
 ima vrijednost “tačno” ili “netačno”. Elementi u novokreiranom vektoru trebaju
 biti u istom međusobnom poretku u kakvom su bili u izvornom vektoru. Za realizaciju
 funkcije obavezno koristite funkciju “push_back”. Napisanu funkciju iskoristite u
 testnom programu koji traži da se prvo unese prirodan broj , a nakon toga elementi
 vektora “a” koji ima cjelobrojnih elemenata. Program zatim treba da kreira dva nova
 vektora “b” i “c”, i da u vektor “b” prepiše sve brojeve iz vektora “a” sa parnom
 sumom cifara, a u vektor “c” sve brojeve iz vektora “a” sa neparnom sumom cifara.
 Konačno, program treba da u jednom redu ispiše brojeve sa parnom sumom cifara, a
 u drugom redu brojeve sa neparnim brojem cifara (moguće je da neki red ostane prazan,
ukoliko nema niti jedan broj sa traženim svojstvom). Mogući dijalozi između programa
i korisnika trebaju izgledati ovako:

    Koliko zelite unijeti elemenata: 12
    Unesite elemente: 15 23 18 -26 0 142 -333 73 11111 -312 9 5555555
    15 -26 0 73 -312
    23 18 142 -333 11111 9 5555555

    Koliko zelite unijeti elemenata: 5
    Unesite elemente: 24 73 112 -17 0
    24 73 112 -17 0

    Koliko zelite unijeti elemenata: 4
    Unesite elemente: 32 -23 111 45
    32 -23 111 45

Za sve manipulacije sa vektorima koristite isključivo rangovsku for-petlju, osim za unos
elemenata (u ovom trenutku još ne znate kako koristiti rangovsku for-petlju za unos, jer
Vam za to trebaju reference). Možete pretpostaviti da će svi ulazni podaci biti
korektni.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    std::cout<<"Koliko zelite unijeti elemenata: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente: ";
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x;
        std::cin>>x;
        a.push_back(x);
    }
    vector<int> b,c;
    vector<int> IzdvojiElemente(vector<int>, bool);
    b = IzdvojiElemente(a, true);
    c = IzdvojiElemente(a, false);

    for(int x : b){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    for(int x : c){
        std::cout<<x<<" ";
    }
    return 0;
}

vector<int> IzdvojiElemente(vector<int> v, bool paran){
    vector<int> IzdvojiElementePoOstatku(vector<int>, int, int);
    return IzdvojiElementePoOstatku(v, 2, !paran);
}

vector<int> IzdvojiElementePoOstatku(vector<int> v, int m, int o){
    vector<int> sol;
    int SumaCifara(int);
    for(int x : v){
        if(SumaCifara(x) % m == o)
            sol.push_back(x);
    }
    return sol;
}

int SumaCifara(int x){
    int sol = 0;
    while(x != 0){
        sol += x % 10;
        x /= 10;
    }
    return abs(sol);
}
