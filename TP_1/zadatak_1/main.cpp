/*
Neka je dat bazen oblika kvadra dimenzije a×b×c i keramičke pločice oblika kvadrata dimenzija d×d. Napišite program koji prvo zahtijeva od korisnika da
unese dužinu, širinu i dubinu bazena (tj. a, b i c) u metrima, kao i širinu keramičke pločice u centimetrima. Program zatim treba da ispita da li je bazen
moguće popločati takvim pločicama, a da se pri tome niti jedna pločica ne treba lomiti (debljinu pločice zanemariti). Ukoliko to nije moguće, treba
ispisati odgovarajući komentar. Ukoliko jeste, treba ispisati koliko je pločica potrebno za popločavanje (naravno, popločavaju se zidovi i dno bazena).
Slijede primjeri dva dijaloga između programa i korisnika. Radi autotestiranja, dijalozi bi trebali izgledati tačno kako je prikazano, uključujući i
mjesta gdje se prelazi u novi red i prazne redove, samo se brojevi koje unosi korisnik mogu razlikovati (iza posljednje rečenice također je potreban
prelazak u novi red). Afrikati poput “č”, “ć” itd. se ne koriste u ispisu zbog činjenice da nije sasvim jednostavno podesiti da se oni ispravno prikazuju
(to će vrijediti i ubuduće).

primjer 1:
    Unesite duzinu, sirinu i dubinu bazena u metrima: 5 15 3
    Unesite sirinu plocice u centimetrima: 10
    Za poplocavanje bazena dimenzija 5x15x3m sa plocicama dimenzija 10x10cm
    potrebno je 19500 plocica.

primjer 2:
    Unesite duzinu, sirinu i dubinu bazena u metrima: 5 15 3
    Unesite sirinu plocice u centimetrima: 13
    Poplocavanje bazena dimenzija 5x15x3m sa plocicama dimenzija 13x13cm
    nije izvodljivo bez lomljenja plocica!

Za unos podataka i ispis rezultata koristite objekte “cin” i “cout” iz biblioteke “iostream”. Koristite isključivo cjelobrojni tip podataka
(tačnije tip “int”). Pretpostavite da su ulazni podaci smisleni (tj. ne morate testirati da li je korisnik unio smislene podatke).

*/

#include <iostream>

int main()
{
    std::cout<<"Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    int a, b, c;
    std::cin>>a>>b>>c;

    std::cout<<"Unesite sirinu plocice u centimetrima: ";
    int d;
    std::cin>>d;

    if((a*100)%d!=0 || (b*100)%d!=0 || (c*100)%d!=0)
        std::cout<<"Poplocavanje bazena dimenzija "<<a<<"x"<<b<<"x"<<c<<"m sa plocicama dimenzija "<<d<<"x"<<d<<"cm nije izvodljivo bez lomljenja plocica";
    else{
        int aPlocica = 100 * a / d;
        int bPlocica = 100 * b / d;
        int cPlocica = 100 * c / d;
        int sol = aPlocica * bPlocica + 2 * aPlocica * cPlocica + 2 * bPlocica * cPlocica;
        std::cout<<"Za poplocavanje bazena dimenzija "<<a<<"x"<<b<<"x"<<c<<"m sa plocicama dimenzija "<<d<<"x"<<d<<"cm potrebno je "<<sol<<" plocica.";
    }

    return 0;
}
