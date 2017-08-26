/*
Napišite program koji traži da sa tastature unesemo podatke o dva vremenska trenutka, u satima, minutama i sekundama, a koji računa i ispisuje vrijeme koje je proteklo između ta dva vremenska
trenutka, također u satima, minutama i sekundama. Pretpostaviti da je drugi vremenski trenutak uvijek nakon prvog. Na primjer, dijalog nakon pokretanja programa može da izgleda poput sljedećeg:

    Unesi prvo vrijeme (h min s): 14 15 7
    Unesi drugo vrijeme (h min s): 16 9 34

    Između ova dva trenutka proteklo je 1h 54min 27s.
*/

#include <iostream>

using namespace std;

int main()
{
    std::cout<<"Unesi prvo vrijeme (h min s): ";
    int h1, m1, s1;
    std::cin>>h1>>m1>>s1;
    int r1 = h1 * 3600 + m1 * 60 + s1;

    std::cout<<"Unesi drugo vrijeme (h min s): ";
    int h2, m2, s2;
    std::cin>>h2>>m2>>s2;
    int r2 = h2 * 3600 + m2 * 60 + s2;

    int d = r2 - r1;
    int dh = d / 3600;
    int dm = (d - dh * 3600) / 60;
    int ds = d - dh * 3600 - dm * 60;

    std::cout<<"Izmedju ova dva trenutka proteklo je "<<dh<<"h "<<dm<<"min "<<ds<<"s.";


    return 0;
}
