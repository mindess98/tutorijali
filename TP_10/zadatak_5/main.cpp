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
    int stepeni, minute, sekunde;
    double SMSURadijane(int s, int m, int se) const;
    double Normaliziraj(double& rad);
    void Normaliziraj(int& step, int& minu, int& seku){
        if(step < 0) {
            minu *= -1;
            seku *= -1;
        }
        minu += (seku / 60);
        seku %= 60;
        if(seku < 0){
            minu--;
            seku += 60;
        }
        step += (minu / 60);
        minu %= 60;
        if(minu < 0){
            step--;
            minu += 60;
        }
        step %= 360;
        if(step < 0) step += 360;
    }
    void OcitajKlasicneJedinice2(double rad, int& step, int& minu, int& seku);
public:
    static constexpr double const PI = atan(1) * 4;

    Ugao(double rad = 0) {Normaliziraj(rad);
                          OcitajKlasicneJedinice2(rad, stepeni, minute, sekunde);}
    Ugao(int stepeni, int minute, int sekunde) : stepeni(stepeni), minute(minute), sekunde(sekunde) { Normaliziraj(this->stepeni, this->minute, this->sekunde); }
    void Postavi(double rad) { Normaliziraj(rad);
                               OcitajKlasicneJedinice2(rad, stepeni, minute, sekunde);};
    void Postavi(int step, int minu, int seku) { this->stepeni = step;
                                                 this->minute = minu;
                                                 this->sekunde = seku;
                                                 Normaliziraj(stepeni, minute, sekunde);}
    double DajRadijane() const {return SMSURadijane(stepeni, minute, sekunde);}
    void OcitajKlasicneJedinice(int& stepeni, int& minute, int& sekunde) const;
    int DajStepene() const {return stepeni;}
    int DajMinute() const {return minute;}
    int DajSekunde() const {return sekunde;}
    void Ispisi() const {cout<<SMSURadijane(stepeni, minute, sekunde)<<endl;}
    void IspisiKlasicno() const {cout<<DajStepene()<<"deg "<<DajMinute()<<"min "<<DajSekunde()<<"sec";}
    Ugao& SaberiSa(const Ugao& u) {
        this->stepeni += u.stepeni;
        this->minute += u.minute;
        this->sekunde += u.sekunde;
        Normaliziraj(this->stepeni, this->minute, this->sekunde);
    }
    Ugao& PomnoziSa(double x){
        this->stepeni *= x;
        this->minute *= x;
        this->sekunde *= x;
        Normaliziraj(this->stepeni, this->minute, this->sekunde);
        }
    friend Ugao ZbirUglova(const Ugao& u1, const Ugao& u2){
        Ugao u(u1.stepeni + u2.stepeni, u1.minute + u2.minute, u1.sekunde + u2.sekunde);
        u.Normaliziraj(u.stepeni, u.minute, u.sekunde);
        return u;
    }
    friend Ugao ProduktUglaSaBrojem(const Ugao& u, double x){
        Ugao u1(u.stepeni * x, u.minute * x, u.sekunde * x);
        u1.Normaliziraj(u1.stepeni, u1.minute, u1.sekunde);
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
    stepeni = this->stepeni;
    minute = this->minute;
    sekunde = this->sekunde;
}
void Ugao::OcitajKlasicneJedinice2(double rad,int& stepeni, int& minute, int& sekunde){
    double stepeniSaDecimalnim = rad * (180/PI);
    stepeni = roundeps(stepeniSaDecimalnim,1.0e-12);
    minute = roundeps((roundeps(stepeniSaDecimalnim,1.0e-12) - stepeni) * 60, 1.0e-6);
    sekunde = roundeps(roundeps(stepeniSaDecimalnim,1.0e-12)*3600 - stepeni*3600 - minute*60, 1.0e-6);
}



int main()
{
    Ugao u(-90,59,59);
    u.Ispisi();
    u.IspisiKlasicno();


    return 0;
}
