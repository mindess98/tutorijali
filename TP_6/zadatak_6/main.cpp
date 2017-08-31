#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

using namespace std;

template <typename Kontejner2D>
auto KreirajDinamickuKopiju2D(Kontejner2D k) -> decltype(k[0][0] + k[0][0])**{
    decltype(k[0][0] + k[0][0])** p;

    try{
        int sum(0);
        for(int i = 0; i < k.size(); i++)
            sum += k[i].size();

        p = new decltype(k[0][0] + k[0][0])*[k.size()];
        p[0] = new decltype(k[0][0] + k[0][0])[sum];

        for(int i = 1; i < k.size(); i++)
            p[i] = p[i-1] + k[i-1].size();

        for(int i = 0; i < k.size(); i++)
            for(int j = 0; j < k[i].size(); j++)
                p[i][j] = k[i][j];

    }
    catch(bad_alloc& e){
        for(int i = 0; i < k.size(); i++)
            delete[] p[i];
        delete[] p;
        throw e;
    }
    catch(...){
        for(int i = 0; i < k.size(); i++)
            delete[] p[i];
        delete[] p;
        throw;
    }
    return p;
}

int main()
{
    int** p;

    cout<<"Unesite broj redova kvadratne matrice: ";
    int n;
    cin>>n;

    try{
        vector<deque<int>> v(n, deque<int> (n));
        cout<<"Unesite elemente matrice: ";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>v[i][j];
            }
        }
        p = KreirajDinamickuKopiju2D(v);
    }
    catch(bad_alloc& e){
        cout<<"Nedovoljno memorije";
        return 1;
    }
    catch(...){
        cout<<"Undefined error";
        return 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
