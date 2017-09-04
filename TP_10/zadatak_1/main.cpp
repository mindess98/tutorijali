#include <iostream>
#include <stdexcept>

using namespace std;

class StedniRacun{
    double stanjeRacuna;
public:
    StedniRacun(double sR = 0){
        if(sR < 0) throw logic_error("Nedozvoljeno pocetno stanje");
        stanjeRacuna = sR;
    }
    double DajStanje() const {return stanjeRacuna;}
    void Ulozi(double u){ stanjeRacuna += u;}
    void Podigni(double p) { if(stanjeRacuna < p) throw logic_error("Transakcija odbijena"); stanjeRacuna -= p;}
    void ObracunajKamatu(double k) { if(k < 0) throw logic_error("Nedozvoljena kamatna stopa"); stanjeRacuna *= k+1;}
};

int main()
{
    StedniRacun sr(2);
    sr.Ulozi(3);
    sr.Podigni(1.5);
    cout<<sr.DajStanje();
    sr.ObracunajKamatu(0.1);
    cout<<endl<<sr.DajStanje();
    return 0;
}
