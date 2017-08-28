/*
Prepravite prethodni program tako da umjesto tipa “vector” koristi tip “deque” (tj. da koristi dek
umjesto vektora), i uvjerite se da sve i dalje radi potpuno isto.
*/

#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main()
{
    std::cout<<"Koliko zelite unijeti elemenata: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente: ";
    deque<int> a;
    for(int i = 0; i < n; i++){
        int x;
        std::cin>>x;
        a.push_back(x);
    }
    deque<int> b,c;
    deque<int> IzdvojiElemente(deque<int>, bool);
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

deque<int> IzdvojiElemente(deque<int> v, bool paran){
    deque<int> IzdvojiElementePoOstatku(deque<int>, int, int);
    return IzdvojiElementePoOstatku(v, 2, !paran);
}

deque<int> IzdvojiElementePoOstatku(deque<int> v, int m, int o){
    deque<int> sol;
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
