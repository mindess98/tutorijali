#include <iostream>
#include <functional>

using namespace std;


function<double(double)> KompozicijaFunkcija(function<double(double)> f, function<double(double)> g){
    return [f, g](double x){return g(f(x));};
}

function<double(double)> IteriranaFunkcija(function<double(double)> f, int n){
    function<double(double)> sol = [](double x){return x;};
    for(int i = 0; i < n; i++)
        sol = KompozicijaFunkcija(sol, f);
    return sol;
}

double k (double x){
    return x+1;
}

int main()
{
    cout<<IteriranaFunkcija(k, 10)(2.5);
    return 0;
}
