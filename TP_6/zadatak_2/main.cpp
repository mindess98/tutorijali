#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename Iterator>
auto KreirajIzvrnutiNiz(Iterator left, Iterator right) -> decltype(*left + *left)* {
    if(left == right) throw domain_error(" ");
    int n(0);
    Iterator i = left;
    while(i++ != right)
        n++;

    decltype(*left + *left)* p;

    try{
        p = new decltype(*left + *left)[n];
    }
    catch(...){
        throw bad_alloc();
    }
    for(int i = n-1; i>=0; i--){
        p[i] = *(left++);
    }
    return p;
}


int main()
{
    cout<<"Koliko zelite elemenata: ";
    int n;
    cin>>n;

    vector<double> v;
    double* p;
    try{
        cout<<"Unesite elemente: ";
        for(int i = 0; i < n; i++){
            double x;
            cin>>x;
            v.push_back(x);
        }
        p = KreirajIzvrnutiNiz(v.begin(), v.end());
    }
    catch(bad_alloc& e){
        cout<<"Nedovoljno memorije";
        return 1;
    }
    catch(...){
        cout<<"Undefined error";
        return 1;
    }
    cout<<"Kreirani niz: ";
    for(int i = 0; i < 10; i++)
        cout<<p[i]<<" ";

    return 0;
}
