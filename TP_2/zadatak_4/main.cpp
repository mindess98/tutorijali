/*
Prepravite prethodni program tako što će se umjesto impedansi sa tastature posebno unositi aktivni
i reaktivni otpori i , i što će se na kraju ispisivati posebno aktivni i reaktivni otpor paralelne
veze elemenata. Dijalog između programa i korisnika treba da izgleda poput sljedećeg:

    Unesite broj elemenata: 3
    R1 = 3.5
    X1 = 2.8
    R2 = 10
    X2 = -1.54
    R3 = 12.37
    X3 = 0.24
    Paralelna veza ovih elemenata ima R = 2.51479 i X = 0.897637.
*/

#include <iostream>
#include <complex>

using namespace std;

int main()
{
    std::cout<<"Unesite broj elemenata: ";
    int n;
    std::cin>>n;
    complex<double> sum(0,0);
    for(int i = 0; i < n; i++){
        std::cout<<endl;
        double r;
        std::cout<<"R"<<i+1<<" = ";
        std::cin>>r;
        double x;
        std::cout<<"X"<<i+1<<" = ";
        std::cin>>x;
        complex<double> z;
        z = {r,x};
        sum += 1. / z;
    }
    std::cout<<"Paralelna veza ovih elemenata ima R = "<<real(1./sum)<<" i X = "<<imag(1./sum)<<".";
}
