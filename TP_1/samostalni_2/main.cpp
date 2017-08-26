/*
Napišite program koji traži da se sa tastature unese brzina broda u čvorovima koja se zadaje isključivo kao cijeli broj (obavezno koristiti promjenljivu tipa “int”), a zatim izračunava i ispisuje
brzinu broda u km/h kao decimalan broj. Koristite činjenicu da je čvor morska milja na sat, a da je jedna morska milja 1852 m (ovaj podatak obavezno definirati u programu kao konstantu).
Na primjer, ukoliko se kao brzina broda unese broj 20, program treba da ispiše rezultat 37.04 jer je 20 čvorova = 37.04 km/h.
*/

#include <iostream>

const float M2KM =1.852;

int main()
{
    std::cout<<"Unesi brzinu broda u cvorovima: ";
    int a;
    std::cin>>a;
    std::cout<<"Brzina broda u km/h je: "<<a * M2KM;
    return 0;
}
