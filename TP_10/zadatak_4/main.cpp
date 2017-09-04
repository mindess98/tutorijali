#include <iostream>
#include <cmath>

using namespace std;

double roundeps(double x, double eps){
    if((int)(x+eps)> (int)x) return (int)(x+eps);
    if((int)(x-eps)< (int)x) return (int)(x-eps);
    return x;
}

class Ugao
{
    double radijani;
    double SMSURadijane(int s, int m, int se) const;
    double Normaliziraj(double& rad);
public:
    static constexpr double const PI = atan(1) * 4;

    Ugao(double rad = 0) : radijani(rad) {Normaliziraj(radijani);}
    Ugao(int stepeni, int minute, int sekunde) : radijani(SMSURadijane(stepeni,minute,sekunde)){Normaliziraj(radijani);}
    void Postavi(double rad) { radijani = Normaliziraj(rad);};
    void Postavi(int stepeni, int minute, int sekunde) { radijani = SMSURadijane(stepeni,minute,sekunde);
                                                         Normaliziraj(radijani);}
    double DajRadijane() const {return radijani;}
    void OcitajKlasicneJedinice(int& stepeni, int& minute, int& sekunde) const;
    int DajStepene() const {int s,m,se; OcitajKlasicneJedinice(s,m,se); return s;}
    int DajMinute() const {int s,m,se; OcitajKlasicneJedinice(s,m,se); return m;}
    int DajSekunde() const {int s,m,se; OcitajKlasicneJedinice(s,m,se); return se;}
    void Ispisi() const {cout<<radijani<<endl;}
    void IspisiKlasicno() const {cout<<DajStepene()<<"deg "<<DajMinute()<<"min "<<DajSekunde()<<"sec";}
    Ugao& SaberiSa(const Ugao& u) {
        this->radijani += u.radijani;
        Normaliziraj(this->radijani);
    }
    Ugao& PomnoziSa(double x){
        this->radijani *= x;
        Normaliziraj(this->radijani);
        }
    friend Ugao ZbirUglova(const Ugao& u1, const Ugao& u2){
        Ugao u(u1.radijani + u2.radijani);
        u.Normaliziraj(u.radijani);
        return u;
    }
    friend Ugao ProduktUglaSaBrojem(const Ugao& u, double x){
        Ugao u1(u.radijani * x);
        u1.Normaliziraj(u1.radijani);
        return u1;
    }
};
double Ugao::Normaliziraj(double& rad){
    int t = rad / (2*PI);
    rad -= 2*PI*t;
    if(rad < 0) rad += 2*PI;
    return rad;
}
double Ugao::SMSURadijane(int s, int m, int se) const  {
    double rad = s + m/60. + se/3600.;
    rad *= PI/180;
    return rad;
}
void Ugao::OcitajKlasicneJedinice(int& stepeni, int& minute, int& sekunde) const{
    double stepeniSaDecimalnim = radijani * (180/PI);
    stepeni = roundeps(stepeniSaDecimalnim,1.0e-12);
    minute = roundeps((roundeps(stepeniSaDecimalnim,1.0e-12) - stepeni) * 60, 1.0e-6);
    sekunde = roundeps(roundeps(stepeniSaDecimalnim,1.0e-12)*3600 - stepeni*3600 - minute*60, 1.0e-6);
}


int main()
{
    Ugao u(90,0,0);
    u.Ispisi();



    return 0;
}
