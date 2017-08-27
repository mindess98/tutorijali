#include <iostream>

using namespace std;

double UnesiBroj();

int main()
{
    double a,b,c;
    a = UnesiBroj();
    b = UnesiBroj();
    c = UnesiBroj();
    if(a == 0){
        std::cout<<"Jednacina ima beskonacno mnogo rjesenja";
    }
    else {
        std::cout<<"Rjesenje jednacine je: "<<(c - b)/a;
    }
    return 0;
}

double UnesiBroj(){
    double sol;
    std::cout<<"Unesite realan broj: ";
    for(;;){
        std::cin>>sol;
        if(!std::cin){
            std::cout<<"Neispravan unos. Molimo, pokusajte ponovo: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        } else break;
    }
    return sol;
}
