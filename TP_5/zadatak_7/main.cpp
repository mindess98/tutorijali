#include <iostream>
#include <stdexcept>
#include <deque>

using namespace std;

template <typename iterator1>
auto SumaBloka(iterator1 left, iterator1 right) -> decltype(*left + *left){
    decltype(*left + *left) sum(0);
    if(left == right) throw range_error("Blok je prazan");
    for(left; left != right; left++)
        sum += *left;
    return sum;
}

int main()
{
    deque<int> d;

    cout<<"Unesite broj elemenata: ";
    int n;
    cin>>n;

    cout<<"Unesite elemente: ";
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        d.push_back(x);
    }
    cout<<"Suma unesenih elemenata je: "<<SumaBloka(d.begin(),d.end());
    return 0;
}
