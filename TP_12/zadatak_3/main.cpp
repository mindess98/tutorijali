#include <iostream>

using namespace std;

enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

ostream& operator<<(ostream& o, Dani dan)
{
    const char c[7][20] = {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
    return o<<c[dan];
}

Dani operator++(Dani& dan, int a)
{
    Dani pomocni(dan);
    dan = Dani(((int)dan + 1) % 7);
    return pomocni;
}

int main()
{
    for(Dani d = Ponedjeljak;; d++){
        cout<< d <<endl;
        if(d == Nedjelja) break;
    }
    return 0;
}
