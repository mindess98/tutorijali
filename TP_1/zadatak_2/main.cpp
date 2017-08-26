/*
Napišite program koji traži da se sa tastature unesu tri realna broja a, b i c, i koji ispisuje da li ta tri broja mogu biti stranice nekog trougla. Podsjetimo se da za stranice trougla mora vrijediti
uvjet da su sve pozitivne i da je zbir dužina ma koje dvije stranice veći od dužine treće stranice. Ukoliko uneseni brojevi mogu predstavljati dužine stranica trougla, treba izračunati njegov obim,
površinu i najmanji ugao, a zatim ispisati izračunate vrijednosti obima, površine i najmanjeg ugla, pri čemu ugao trea ispisati u stepenima, minutama i sekundama. Za računanje površine trougla
koristite poznatu Heronovu formulu prema kojoj je P = sqrt(s*(s-a)(s-b)(s-c)) gdje je s = (a+b+c)/2, a za računanje ugla koristite kosinusnu teoremu prema kojoj je c^2=a^2+b^2-2ab cosγ (i analogno tome za preostale
kombinacije stranica i uglova). Računajte da 1 radijan ima 180/π stepeni, dok vrijednost π možete računati po formuli π = 4 ∙ arctg 1 (predmetni nastavnik ne želi da vidi da neko misli da je
π = 3.14, to mu pokvari dan). Ukoliko uneseni brojevi ne mogu predstavljati dužine stranica trougla, treba ispisati odgovarajući komentar. Dijalozi koje formira program trebaju izgledati poput
sljedećih (zanemarite eventualne probleme sa padežima i ostalom gramatikom):

    Unesite tri broja: 7 5 8
    Obim trougla sa duzinama stranica 7, 5 i 8 iznosi 20.
    Njegova povrsina iznosi 17.3205.
    Njegov najmanji ugao ima 38 stepeni, 12 minuta i 47 sekundi.

    Unesite tri broja: 5 15 7
    Ne postoji trougao cije su duzine stranica 5, 15 i 7!

Za unos podataka i ispis rezultata koristite objekte “cin” i “cout” iz biblioteke “iostream”, a za odgovarajuća računanja funkcije iz biblioteke “cmath”. Pretpostavite da će korisnik zaista unositi
 brojeve (ne nužno cijele), a ne neko “smeće”.
*/

#include <iostream>
#include <cmath>

const double PI = 4 * atan(1);

int main()
{
    std::cout<<"Unesite tri broja: ";
    double a, b, c;
    std::cin>>a>>b>>c;
    if(a+b<c || a+c<b || b+c<a){
        std::cout<<"Ne postoji trougao cije su duzine stranica "<<a<<", "<<b<<" i "<<c<<"!";
    }
    else{
        double o = a + b + c;
        std::cout<<"Obim trougla sa duzinama stranica "<<a<<", "<<b<<" i "<<c<< " iznosi "<<o<<"."<<std::endl;

        double s = o / 2;
        double p = sqrt(s * (s - a) * (s - b) * (s - c));
        std::cout<<"Njegova povrsina iznosi "<<p<<"."<<std::endl;

        double najmanjiUgao(double, double, double);
        double ugao = najmanjiUgao(a, b, c) * 180/PI;

        int stepeni = (int)ugao;
        int minute = (int)(60 * (ugao - stepeni));
        int sekunde = (int)(60 * (60 * (ugao - stepeni) - minute));

        std::cout<<"Njegov najmanji ugao ima "<<stepeni<<" stepeni, "<<minute<<" minuta i "<<sekunde<<" sekundi.";
    }
    return 0;
}

double najmanjiUgao(double a, double b, double c){

    if(b < a){
        double temp = a;
        a = b;
        b = temp;
    }
    if(c < a){
        double temp = a;
        a = c;
        c = temp;
    }
    return acos((c*c + b*b - a*a)/(2*c*b));
}
