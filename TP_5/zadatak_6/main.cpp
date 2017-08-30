#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumaCifara(int x){
    int sum(0);
    while(x != 0){
        sum += x % 10;
        x /= 10;
    }
    return abs(sum);
}

int main()
{

    vector<int> v;
    cout<<"Unesite broj elemenata: ";
    int n;
    cin>>n;

    cout<<"Unesite elemente: ";
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), [](int a,int b)->bool {if(sumaCifara(a) == sumaCifara(b)) return a < b;
                                                    else return sumaCifara(a) < sumaCifara(b);});
    cout<<"Niz sortiran po sumi cifara glasi: ";
    for(int x : v)
        cout<<x<<" ";
    cout<<"\nUnesite broj koji trazite: ";
    int y;
    cin>>y;

    cout<<(find(v.begin(), v.end(), y)-v.begin());


    return 0;
}
