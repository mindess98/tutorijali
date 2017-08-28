/*
Prepravite prethodni program tako da se brojevi ispisuju razdvojeni zarezom a ne razmakom,
pri čemu iza posljednjeg broja u svakom redu ne treba da bude zarez. Na primjer, za iste
ulazne podatke kao u prethodnom zadatku, dijalozi između korisnika i programa trebali bi
izgledati ovako:

    Koliko zelite unijeti elemenata: 12
    Unesite elemente: 15 23 18 -26 0 142 -333 73 11111 -312 9 5555555
    15,-26,0,73,-312
    23,18,142,-333,11111,9,5555555

    Koliko zelite unijeti elemenata: 5
    Unesite elemente: 24 73 112 -17 0
    24,73,112,-17,0

    Koliko zelite unijeti elemenata: 4
    Unesite elemente: 32 -23 111 45
    32,-23,111,45

Ovaj put za ispis elemenata vektora nemojte koristiti rangovsku for-petlju, jer ćete u
suprotnom teško postići da ne bude ispisan zarez iza posljednjeg elementa u svakom redu.
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

    for(int i = 0; i < b.size() - 1; i++){
        std::cout<<b[i]<<",";
    }
    std::cout<<b[b.size() - 1];
    std::cout<<std::endl;
    for(int i = 0; i < c.size() - 1; i++){
        std::cout<<c[i]<<",";
    }
    std::cout<<c[c.size() - 1];
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
