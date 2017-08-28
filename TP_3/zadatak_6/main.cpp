/*
U linearnoj algebri, pod Kroneckerovim ili tenzorskim proizvodom ⊗ vektora i čiji su
elementi , = 1, 2, …, odnosno , = 1, 2, …, , podrazumijevamo matricu C formata × čiji se
elementi računaju po formuli , = , = 1, 2, …, , = 1, 2, …, (koristeći kompaktniju notaciju
iz linearne algebre, ukoliko su i predstavljeni kao vektor kolone, vrijedi ⊗ =
). Napravite
funkciju “KronceckerovProizvod” koja prima kao parametre dva vektora cijelih brojeva (tipa
“int”), a vraća kao rezultat matricu organiziranu kao vektor vektôrā koja predstavlja Kroneckerov
proizvod vektora koji su zadani kao parametri (pri tome, funkcija se treba konzistentno ponašati
čak i ukoliko je neki od ulaznih vektora prazan). Napisanu funkciju iskoristite u glavnom programu
u kojem će se sa tastature unijeti elementi dva vektora, a zatim kreirati i prikazati na ekranu njihov
Kroneckerov proizvod. Pri tome, ispis na ekranu treba biti takav da se za svaki element matrice
zauzme prostor koji je za 1 veći nego što je širina najšireg broja u matrici, uz poravnavanje udesno
(pod širinom broja podrazumijeva se broj njegovih cifara, eventualno uvećan za 1 ako je broj
negativan, zbog prostora koji zauzima znak “−“). Za tu svrhu, u programu trebate napisati i još
jednu funkciju nazvanu “NajvecaSirina” koja kao parametar prima matricu organiziranu kao
vektor vektôrā cijelih brojeva, a vraća širinu najšireg broja u matrici. Funkcija treba ispravno da
radi i ukoliko joj se ponudi grbava matrica, pa čak i prazna matrica (u posljednjem slučaju, funkcija
treba vratiti 0 kao rezultat). Dijalog između korisnika i programa treba izgledati poput sljedećeg:

    Unesite broj elemenata prvog vektora: 4
    Unesite elemente prvog vektora: 3 124 -11 9
    Unesite broj elemenata drugog vektora: 6
    Unesite elemente drugog vektora: 42 1001 0 -213 16 5
    126 3003 0 -639 48 15
    5208 124124 0 -26412 1984 620
    -462 -11011 0 2343 -176 -55
    378 9009 0 -1917 144 45

Možete pretpostaviti da će svi ulazni podaci biti korektni. Za realizaciju ispisa matrice možete, ali i ne
morate koristiti rangovsku for-petlju (najbolje je da probate obje varijante, sa i bez rangovske
for-petlje).
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente prvog vektora: ";
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x;
        std::cin>>x;
        a.push_back(x);
    }

    std::cout<<"Unesite broj elemenata drugog vektora: ";
    int m;
    std::cin>>m;
    std::cout<<"Unesite elemente drugog vektora: ";
    vector<int> b;
    for(int i = 0; i < m; i++){
        int x;
        std::cin>>x;
        b.push_back(x);
    }

    vector<vector<int>> KroneckerovProizvod(vector<int>, vector<int>);

    auto c = KroneckerovProizvod(a, b);

    int NajvecaSirina(vector<vector<int>>);
    int sirina = NajvecaSirina(c) + 1;
    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < c[0].size(); j++)
            std::cout<<std::setw(sirina)<<c[i][j];
        std::cout<<std::endl;
    }

    return 0;
}


vector<vector<int>> KroneckerovProizvod(vector<int> a, vector<int> b){
    vector<vector<int>> c(a.size(), vector<int>(b.size()));

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++)
            c[i][j] = a[i] * b[j];
    }
    return c;
}

int NajvecaSirina(vector<vector<int>> c){
    int BrojCifara(int);
    int sol = 0;
    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < c[i].size(); j++){
            int numDig = BrojCifara(c[i][j]);
            if(c[i][j] < 0) numDig++;
            if(numDig > sol) sol = numDig;
        }
    }
    return sol;
}

int BrojCifara(int x){
    int sol = 0;
    while(x != 0){
        x /= 10;
        sol++;
    }
    return sol;
}


