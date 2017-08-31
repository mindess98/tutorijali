#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
void NoviStepenDvojke(T* p, int n){
    if (n == 1) return;
    *(p + 1) = (*p) * 2;
    if(*(p + 1) < (*p)) throw overflow_error("Perkoracen dozvoljeni opseg");
    NoviStepenDvojke(p+1, n-1);
    return;
}


template <typename T>
T* GenerirajStepeneDvojke(int n){
    if(n < 1) throw domain_error(" ");
    T* p;
    try{
        p = new T[n];
    }
    catch(...){
        throw runtime_error(" ");
    }
    p[0] = 1;
    NoviStepenDvojke(p, n);

    return p;
}



int main()
{
    cout<<"Koliko zelite elemenata: ";
    int n;
    cin>>n;

    int* p;
    try{
    p = GenerirajStepeneDvojke<int>(n);
    }
    catch(domain_error e){
        cout<<"Broj elemenata mora biti pozitivan";
        goto cleanup;
    }
    catch(runtime_error e){
        cout<<"Alokacija nije uspjela";
        goto cleanup;
    }
    catch(...){
        cout<<"Undefined error";
        goto cleanup;
    }
    for(int i = 0; i < n; i++)
        cout<<p[i]<<" ";

cleanup:
    delete[] p;
    return 0;
}
