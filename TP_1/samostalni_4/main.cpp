#include <iostream>


int main()
{
    std::cout << "Unesite zeljeni broj sati: ";
    float a;
    std::cin>>a;
    std::cout<<"Isplatnija je "<<((10 + .5 * a < .8 * a)? "prva" : "druga")<<" firma";
    return 0;
}
