/*
Prepravite prethodni program tako što će se sve impedanse umjesto preko aktivnog otpora i
i reaktivnog otpora zadavati preko tzv. prividnog otpora i faznog pomaka , pri čemu vrijedi = .
Program na kraju treba prikazati prividni otpor i fazni pomak za čitavu paralelnu vezu. Fazni
pomak treba zadavati i ispisivati u stepenima. Dijalog između programa i korisnika treba da izgleda
poput sljedećeg:

    Unesi broj elemenata: 2
    Z1 = 10.5
    fi1 = 30
    Z2 = 2.8
    fi2 = -47.6
    Paralelna veza ovih elemenata ima Z = 2.57147 i fi = -33.7613
*/


#include <iostream>
#include <complex>
#include <cmath>

const double PI = 4 * atan(1);
using namespace std;

int main()
{
    std::cout<<"Unesite broj elemenata: ";
    int n;
    std::cin>>n;
    complex<double> sum(0,0);
    for(int i = 0; i < n; i++){
        std::cout<<endl;
        std::cout<<"Z"<<i+1<<" = ";
        double z;
        std::cin>>z;
        std::cout<<"fi"<<i+1<<" = ";
        double fi;
        std::cin>>fi;
        fi *= PI/180;
        complex<double> w;
        w = polar(z, fi);
        sum += 1. / w;
    }
    std::cout<<"Paralelna veza ovih elemenata ima Z = "<<abs(1./sum)<<" i fi = "<<arg(1./sum) * 180 / PI<<".";
}
