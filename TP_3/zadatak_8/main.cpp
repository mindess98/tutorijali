/*
Napišite funkciju “IzdvojiRijec” sa dva parametra, od kojih je prvi tipa “string”, a drugi je
cjelobrojan (tipa “int”). Prvi parametar predstavlja neku rečenicu, a drugi parametar redni broj
riječi unutar te rečenice. Funkcija treba da izdvoji tu riječ iz rečenice, i da vrati kao rezultat tako
izdvojenu riječ. Na primjer, ukoliko je kao prvi parametar zadan tekst “ Na vrh brda vrba
mrda” a kao drugi parametar broj 4, funkcija treba kao rezultat da vrati string “vrba”. Ovdje pod
pojmom riječ podrazumijevamo bilo koji slijed uzastopnih znakova koji nisu razmaci, a ispred kojeg
se eventualno nalazi razmak (ili ništa), i iza kojeg eventualno slijedi razmak (ili ništa). Tako se, na
primjer, u tekstu “Kiša pada.Trava raste” slijed znakova “pada.Trava” tretira kao jedna riječ (druga
po redu), jer iza tačke nema razmaka (ovakav tretman vrijedi i u tekst procesorima poput Microsoft
Word-a). Obratite pažnju da riječi mogu biti razdvojene sa više uzastopnih razmaka, kao i da na
početku i kraju teksta može, ali i ne mora biti razmaka. Ukoliko je drugi parametar manji od 1 ili
veći od broja riječi u rečenici, funkcija treba baciti izuzetak tipa “range_error” uz prateći indeks
“Pogresan redni broj rijeci”.

Napisanu funkciju demonstrirajte u testnom programu u kojem se za prirodan broj unesen sa
tastature i rečenicu unesenu sa tastature ispisuje -ta riječ te rečenice (pozivom napisane funkcije).
U testnom programu obavezno predvidite hvatanje izuzetaka koji mogu biti bačeni iz funkcije.
Dijalozi između korisnika i programa trebaju izgledati poput sljedećeg:

    Unesite redni broj rijeci: 4
    Unesite recenicu: Na vrh brda vrba mrda
    Rijec na poziciji 4 je vrba

    Unesite redni broj rijeci: 6
    Unesite recenicu: Na vrh brda vrba mrda
    IZUZETAK: Pogresan redni broj rijeci!

Možete pretpostaviti da će na pitanje da se unese redni broj riječi zaista biti unesen broj.
*/

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{

    std::cout<<"Unesite redni broj rijeci: ";
    int redni;
    std::cin>>redni;

    std::cout<<"Unesite recenicu: ";
    string recenica;
    std::cin.ignore(10000, '\n');
    std::getline(std::cin, recenica);


    string IzdvojiRijec(string, int);
    string r = IzdvojiRijec(recenica, redni);
    std::cout<<r;
    return 0;
}

string IzdvojiRijec(string s, int w){
    bool whitespace = true;
    int wrdcnt = 0;
    string sol;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'){
            whitespace = true;
            continue;
        } else {
            if(whitespace == false) continue;
            else {
                whitespace = false;
                if(++wrdcnt == w){
                    for(int j = i; j < s.size(); j++){
                        if(s[j] == ' ' || s[j] == '\t' || s[j] == '\n') break;
                        sol.push_back(s[j]);
                    }
                    return sol;
                }
            }
        }
    }
    if(wrdcnt < w) throw std::range_error("IZUZETAK: Pogresan redni broj rijeci!");
}
