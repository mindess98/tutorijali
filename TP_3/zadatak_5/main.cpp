/*
U prethodnom programu, izvršite izmjene u funkciji “IzdvojiElemente” tako da se i dalje koristi
funkcija “push front”, ali da rezultat koji daje funkcija bude isti kakav je bio u Zadatku 3. (tako da i
ispis koji će program proizvesti bude isti kao u Zadatku 3.). Pri tome, u funkciji nije dozvoljeno
kreiranje ikakvih pomoćnih kontejnera (nizova, vektora, dekova, itd.).
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
        a.push_front(x);
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
            sol.push_front(x);
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
