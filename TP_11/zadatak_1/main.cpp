#include <iostream>

using namespace std;

class NeobicnaKlasa
{
    int x;
public:
    explicit NeobicnaKlasa(int&& y) : x(y) { cout<<"Direktna inicijalizacija"<<endl;}
    NeobicnaKlasa(const int& n) {x = n; cout<<"Kopirajuca inicijalizacija"<<endl;}
};

int main()
{
    NeobicnaKlasa k1(5);
    NeobicnaKlasa k2 = 5;
    return 0;
}
