#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

int main()
{
    cout<<"Koliko zelite elemenata: ";
    int n;
    cin>>n;

    cout<<"Unesite elemente: ";
    vector<double> v(n);
    for(double& i : v)
        cin>>i;

    //transform(v.begin(), v.end(), v.begin(), bind1st(divides<double>(), 1));
    transform(v.begin(), v.end(), v.begin(), bind(divides<double>(), 1, _1));

    for(double i : v)
        cout<<i<<" ";
    return 0;
}
