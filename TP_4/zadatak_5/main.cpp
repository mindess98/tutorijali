#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> Presjek(vector<T> v1, vector<T> v2){

    vector<T> sol;

    for(T x : v1){
        bool vecPostoji;
        vecPostoji = false;
        for(T z : sol)
            if(x == z) vecPostoji = true;
        if(vecPostoji) continue;
        for(T y : v2){
            if(x == y){
                vecPostoji = false;
                for(T z : sol)
                    if(x == z) vecPostoji = true;
                if(!vecPostoji) sol.push_back(x);
            }
        }
    }
    return sol;
}

int main()
{
    cout<<"Test za realne brojeve...\n";
    cout<<"Unesite broj elemenata prvog vektora: ";
    int n;
    cin>>n;

    cout<<"Unesite elemente prvog vektora: ";
    vector<int> v1;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v1.push_back(x);
    }

    cout<<"Unesite broj elemenata drugog vektora: ";
    cin>>n;

    cout<<"Unesite elemente drugog vektora: ";
    vector<int> v2;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }

    auto v = Presjek(v1, v2);

    cout<<"Zajednicki elementi su: ";
    for(auto x : v)
        cout<<x<<" ";
    return 0;
}
