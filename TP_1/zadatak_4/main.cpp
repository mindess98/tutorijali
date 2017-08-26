/*
U numerologiji starih Grka, svi prirodni brojevi su se dijelili u tri kategorije, prema tome kakva im je suma svih njihovih djelilaca (ne računajući njega samog). Oni brojevi kod kojih je ta suma
manja od samog broja nazivali su se manjkavi (engl. deficient), oni kod kojih je ta suma veća od samog broja nazivali su se obilni (engl. abudant), dok su oni brojevi koji su jednaki sumi svih svojih
djelilaca (bez njega samog) nazivali savršeni (engl. perfect). Recimo, broj 49 je manjkav: njegovi djelioci su 1 i 7, pri čemu je 1 + 7 = 8 < 49. Isto tako, broj 42 je obilan: njegovi djelioci su
1,2, 3, 6, 7, 14 i 21, pri čemu je 1 + 2 + 3 + 6 + 7 + 14 + 21 = 54 > 42. Konačno, 28 je primjer savršenog broja: njegovi djelioci su 1, 2, 4, 7 i 14, a vrijedi 1 + 2 + 4 + 7 + 14 = 28.

Napišite program koji traži da se sa tastature unese prirodan broj . U slučaju da korisnik unese nešto što nije prirodan broj (što uključuje i situaciju kada uneseni podatak uopće nije broj), treba
ispisati poruku upozorenja, i ponoviti unos. Ukoliko je unos ispravan, program treba da ispita i ispiše da li je uneseni broj manjkav, obilan ili savršen. Nakon toga, program treba da traži unos novog
broja i da ponavlja postupak sve dok se kao broj ne unese nula. Dijalog između programa i korisnika trebao bi izgledati poput sljedećeg:

    Unesite prirodan broj ili 0 za kraj: 42
    Broj 42 je obilan!
    Unesite prirodan broj ili 0 za kraj: 28
    Broj 28 je savrsen!
    Unesite prirodan broj ili 0 za kraj: 49
    Broj 49 je manjkav!
    Unesite prirodan broj ili 0 za kraj: -1
    Niste unijeli prirodan broj!
    Unesite prirodan broj ili 0 za kraj: 2.15
    Niste unijeli prirodan broj!
    Unesite prirodan broj ili 0 za kraj: qwerty
    Niste unijeli prirodan broj!
    Unesite prirodan broj ili 0 za kraj: 0
    Dovidjenja!
*/

#include <iostream>

int main()
{
    float a;
    for(;;){
        std::cout<<"Unesite prirodan broj ili 0 za kraj: ";
        std::cin>>a;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Niste unijeli prirodan broj!\n";
            continue;
        }
        if(a < 0){
            std::cout<<"Niste unijeli prirodan broj!\n";
            continue;
        }
        if(a != (int) a){
            std::cout<<"Niste unijeli prirodan broj!\n";
            continue;
        }
        if(a == 0) {
            std::cout<<"Dovidjenja!\n";
            break;
        }
        int b = (int)a;
        int sum = 0;
        for(int i = 1; i < b; i++)
            if(b % i == 0) sum += i;
        if(sum > b) std::cout<<"Broj "<<b<<" je obilan!\n";
        else if(sum < b) std::cout<<"Broj "<<b<<" je manjkav!\n";
             else std::cout<<"Broj "<<b<<" je savrsen!\n";
    }
    return 0;
}
