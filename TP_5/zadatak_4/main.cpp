#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>

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
    deque<int> a;

    cout<<"Unesite broj elemenata : ";
    int n;
    cin>>n;

    cout<<"Unesite elemente: ";
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    cout<<"Najveci element deka je "<<*max_element(a.begin(), a.end())<<endl;
    cout<<"Najmanji element se pojavljuje "<<count(a.begin(), a.end(), *min_element(a.begin(), a.end()))<<" puta"<<endl;
    cout<<"U deku ima "<<count_if(a.begin(), a.end(), [](int b)->bool{return sqrt(b) == static_cast<int>(sqrt(b));})<<" brojeva koji su potpuni kvadrati"<<endl;
    cout<<"Prvi element sa najmanjim brojem cifara je "<<*min_element(a.begin(), a.end(), [](int x, int y)->bool{return brojCifara(x) < brojCifara(y);})<<endl;

    int b[1000];

    int* e = remove_copy_if(a.begin(), a.end(), b, [](int x)->bool{return brojCifara(x) == 3;});
    for(int* p = b; p < e; p++){
        cout<<*p<<" ";
    }

    return 0;
}
