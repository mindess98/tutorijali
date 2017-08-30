#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int brojCifara(int x){
    int sol(0);
    while(x != 0){
        x /= 10;
        sol++;
    }
    return sol;
}

int main(){
    int a[1000];

    cout<<"Unesite broj elemenata (max. 1000): ";
    int n;
    cin>>n;

    cout<<"Unesite elemente: ";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    cout<<"Najveci element niza je "<<*max_element(a, a+n)<<endl;
    cout<<"Najmanji element se pojavljuje "<<count(a, a+n, *min_element(a, a+n))<<" puta"<<endl;
    cout<<"U nizu ima "<<count_if(a, a+n, [](int b)->bool{return sqrt(b) == static_cast<int>(sqrt(b));})<<" brojeva koji su potpuni kvadrati"<<endl;
    cout<<"Prvi element sa najmanjim brojem cifara je "<<*min_element(a, a+n, [](int x, int y)->bool{return brojCifara(x) < brojCifara(y);})<<endl;

    int b[1000];

    int* e = remove_copy_if(a, a+n, b, [](int x)->bool{return brojCifara(x) == 3;});
    for(int* p = b; p < e; p++){
        cout<<*p<<" ";
    }

    return 0;
}
