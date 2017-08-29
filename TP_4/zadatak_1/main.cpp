#include <iostream>
#include <cmath>

using namespace std;

int Cifre(long long int n, int& c_min, int& c_max){
    if(n == 0){
        c_min = c_max = 0;
        return 1;
    }
    int sol(0), mi(10), Ma(0);
    int cifra;
    while(n != 0){
        cifra = abs(n % 10);
        if(cifra < mi) mi = cifra;
        if(cifra > Ma) Ma = cifra;
        n /= 10;
        sol++;
    }
    c_min = mi;
    c_max = Ma;
    return sol;
}

int main()
{
    int mi,ma;
    cout<<Cifre(0, mi, ma)<<" ";
    cout<<mi<<" "<<ma;
    return 0;
}
