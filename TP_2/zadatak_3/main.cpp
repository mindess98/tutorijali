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
        std::cout<<"Z_"<<i+1<<" = ";
        complex<double> z;
        std::cin>>z;
        sum += 1. / z;
    }
    std::cout<<"Paralelna veza ovih elemenata ima impedansu Z = "<<1./sum<<".";
}
