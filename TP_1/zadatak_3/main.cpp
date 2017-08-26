/*
Napišite program koji traži da se sa tastature unesu dva prirodna broja i , ne veća od 9999 i pri čemu je < , a koji zatim za sve prirodne brojeve u opsegu od do uključivo ispisuje tablicu njihovih
kvadrata, kvadratnih korijena i prirodnih logaritama. Tačan izgled tablice vidljiv je iz dijaloga koji će biti prikazan. Uglavnom, kolona za prikaz brojeva široka je 9 polja. Brojevi se ispisuju
poravnati ulijevo, pri čemu je prvo polje uvijek razmak. Kolone za prikaz kvadrata i korijena široke su 10 polja, dok je kolona za prikaz logaritama široka 11 polja. Kvadrati, korijeni i logaritmi se
ispisuju poravnati udesno, pri čemu je posljednje polje uvijek razmak. Pored toga, korijeni se ispisuju fiksno na tri decimale, a logaritmi fiksno na pet decimala. Slijedi primjer kako treba izgledati
dijalog između korisnika i programa:

    Unesite pocetnu i krajnu vrijednost: 95 103
    +---------+----------+----------+-----------+
    | Brojevi | Kvadrati | Korijeni | Logaritmi |
    +---------+----------+----------+-----------+
    | 95      |     9025 |    9.747 |   4.55388 |
    | 96      |     9216 |    9.798 |   4.56435 |
    | 97      |     9409 |    9.849 |   4.57471 |
    | 98      |     9604 |    9.899 |   4.58497 |
    | 99      |     9801 |    9.950 |   4.59512 |
    | 100     |    10000 |   10.000 |   4.60517 |
    | 101     |    10201 |   10.050 |   4.61512 |
    | 102     |    10404 |   10.100 |   4.62497 |
    | 103     |    10609 |   10.149 |   4.63473 |
    +---------+----------+----------+-----------+

Za ispis koristite objekat “cout” iz biblioteke “iostream” i odgovarajuće manipulatore iz iste biblioteke, kao i biblioteke “iomanip”. U programu ne trebate testirati da li su i zaista prirodni
brojevi ne veći od 9999, i da li je < . Međutim, ispitajte kako će se program ponašati ukoliko se unesu brojevi koji ne zadovoljavaju ova ograničenja.
*/


#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    std::cout<<"Unesite pocetnu i krajnju vrijednost: ";
    int a, b;
    std::cin>>a>>b;

    std::cout<<"+---------+----------+----------+-----------+\n";
    std::cout<<"| Brojevi | Kvadrati | Korijeni | Logaritmi |\n";
    std::cout<<"+---------+----------+----------+-----------+\n";
    for(int i = a; i<= b; i++){
        std::cout<<"|"<<i<<"|"<<i*i<<"|"<<sqrt(i)<<"|"<<log(i)<<"|\n";
    }
    std::cout<<"+---------+----------+----------+-----------+";

    return 0;
}
