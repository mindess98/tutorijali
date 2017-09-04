#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Krug
{
    double r;
public:
    static constexpr double const PI = atan(1) * 4;

    explicit Krug(double r){ if(r<=0) throw domain_error("Neispravan poluprecnik");this->r = r;}
    Krug() = delete;
    void Postavi(double r) { if(r<=0) throw domain_error("Neispravan poluprecnik");this->r = r;}
    double DajPoluprecnik() const {return r;}
    double DajObim() const {return 2*r*PI;}
    double DajPovrsinu() const {return r*r*PI;}
    void Skaliraj(double k) { if(k<=0) throw domain_error("Neispravan faktor skaliranja");this->r *= k;}
    void Ispisi() const { cout<<"R="<<r<<" O="<<DajObim()<<" P="<<DajPovrsinu()<<endl;}
};

class Valjak
{
    Krug baza;
    double visina;
public:
    Valjak(double r, double h) : baza(r) {if(h<=0) throw domain_error("Neispravna visina"); visina = h;}
    Valjak() = delete;
    void Postavi(double r, double h) {if(h<=0) throw domain_error("Neispravna visina"); baza.Postavi(r); visina = h;}
    Krug DajBazu() const {return baza;}
    double DajVisinu() const {return visina;}
    double DajPovrsinu() const {return 2*baza.DajPoluprecnik()*Krug::PI*visina + 2*baza.DajPoluprecnik()*baza.DajPoluprecnik()*Krug::PI;}
    double DajPoluprecnikBaze() const {return baza.DajPoluprecnik();}
    double DajZapreminu() const {return baza.DajPoluprecnik()*baza.DajPoluprecnik()*Krug::PI*visina;}
    void Skaliraj(double k) {if(k<=0) throw domain_error("Neispravan faktor skaliranja"); visina*=k; baza.Skaliraj(k);}
    void Ispisi() const {cout<<"R="<<baza.DajPoluprecnik()<<" H="<<visina<<" P="<<DajPovrsinu()<<" V="<<DajZapreminu()<<endl;}
};


int main()
{
    Valjak v(2.,3.);
    v.Ispisi();
    v.Postavi(3.,4.);
    v.Ispisi();
    v.Skaliraj(1.5);
    v.Ispisi();
}
