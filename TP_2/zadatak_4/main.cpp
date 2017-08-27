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
