#include <iostream>
#include <stdexcept>

using namespace std;

class StedniRacun{
    double stanjeRacuna;
    static int brojKreiranih;
    static int brojAktivnih;
public:
    StedniRacun(double sR = 0) { if(sR < 0) throw logic_error("Nedozvoljeno pocetno stanje"); stanjeRacuna = sR; brojKreiranih++; brojAktivnih++; }
    ~StedniRacun() { brojAktivnih--;}
    double DajStanje() const {return stanjeRacuna;}
    void Ulozi(double u){ stanjeRacuna += u;}
    void Podigni(double p) { if(stanjeRacuna < p) throw logic_error("Transakcija odbijena"); stanjeRacuna -= p;}
    void ObracunajKamatu(double k) { if(k < 0) throw logic_error("Japanska kamatna stopa"); stanjeRacuna *= k+1;}
    static int DajBrojKreiranih() {return brojKreiranih;}
    static int DajBrojAktivnih() {return brojAktivnih;}
};

int StedniRacun::brojKreiranih = 0;
int StedniRacun::brojAktivnih = 0;

int main()
{
    StedniRacun sr(2), sr1(2), sr2(3);
    sr.Ulozi(3);
    sr.Podigni(1.5);
    cout<<sr.DajStanje();
    {
        StedniRacun sr3(4);
        cout<<endl<<StedniRacun::DajBrojAktivnih();
    }
    cout<<endl<<StedniRacun::DajBrojAktivnih();
    cout<<endl<<StedniRacun::DajBrojKreiranih();
    sr.ObracunajKamatu(0.1);
    StedniRacun sr5(10);
    cout<<endl<<StedniRacun::DajBrojKreiranih();
    cout<<endl<<StedniRacun::DajBrojAktivnih();
    cout<<endl<<sr.DajStanje();
    return 0;
}
