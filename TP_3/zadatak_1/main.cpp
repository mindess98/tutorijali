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
