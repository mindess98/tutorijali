#include <iostream>
#include <functional>

using namespace std;

function<double(double)> plus2(double x){
    return [x](double y) {return x + y;};
}

function<function<double(double)>(double)> plus3(double x){
    return [x](double y) {return [x,y](double z){return x+y+z;};};
}

int main()
{
    cout<<"Unesite dva broja: ";
    double a, b;
    cin>>a>>b;

    cout<<"Suma je: "<<plus2(a)(b);

    cout<<"\nUnesite tri broja: ";
    double c;
    cin>>a>>b>>c;
    cout<<"Suma je: "<<plus3(a)(b)(c);
    return 0;
}
