#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

int** KreirajTrougao(int n){
    if(n < 1) throw domain_error(" ");
    int** p;
    try{
        p = new int*[n];
        p[0] = new int [n * (2*n - 1)];
        for(int i = 1; i < n; i++) p[i] = p[i-1] + (2*n - 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 1 + 2*i; j++){
                p[i][j] = max(i-j+1, j-i+1);
            }
        }
    }
    catch(bad_alloc& e){
        throw e;
    }
    return p;
}

int main()
{
    int** p;

    cout<<"Koliko zelite redova: ";
    int n;
    cin>>n;

    try{
        p = KreirajTrougao(n);
    }
    catch(domain_error& e){
        cout<<"Izuztak: Broj redova mora biti pozitivan";
        return 1;
    }
    catch(bad_alloc& e){
        cout<<"Izuzetak: Nedovoljno memorije!";
        return 1;
    }
    catch(...){
        cout<<"Undefined error";
        return 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 1 + 2*i; j++)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }

    for(int i = 0; i < n; i++)
        delete[] p[i];
    delete[] p;
    return 0;
}
