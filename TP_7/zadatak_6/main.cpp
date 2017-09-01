#include <iostream>
#include <list>

using namespace std;

template <typename T>
list<T> SortirajListu(list<T> l){
    int i = 0;
    for(auto k = l.begin();;){
        auto mint = k;
        for(auto p = k; p != l.end(); p++)
            if(*p < *mint)
                mint = p;
        if(k == (--l.end())) break;
        if(k == mint){
            k++;
            continue;
        }
        l.insert(k, *mint);
        l.erase(mint);
    }
    return l;
}

int main()
{
    cout<<"Koliko ima elemenata: ";
    int n;
    cin>>n;

    list<int> l;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        l.push_back(x);
    }

    l = SortirajListu(l);
    for(int x : l)
        cout<<x<<" ";
    return 0;
}
