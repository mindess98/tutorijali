#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Sat
{
    int h;
    int m;
    int s;
    static void Normaliziraj(int& hh, int& mm, int& ss);
public:
    static bool DaLiJeIspravno(int h, int m, int s) { return h>0&&h<24 && m>0&&m<60 && s>0&&s<60;}
    void Postavi(int hh, int mm, int ss) {if(!DaLiJeIspravno(hh,mm,ss)) throw domain_error("Neispravno vrijeme");
                                          this->h = hh; this->m = mm; this->s = ss;}
    void PostaviNormalizirano(int hh, int mm, int ss) {if(!DaLiJeIspravno(hh,mm,ss)) Normaliziraj(hh, mm, ss);
                                                       this->h = hh; this->m = mm; this->s = ss;}
    Sat& Sljedeci() {s++; if(!DaLiJeIspravno(h,m,s)) Normaliziraj(h, m, s); return *this;}
    Sat& Prethodni() {s--; if(!DaLiJeIspravno(h,m,s)) Normaliziraj(h, m, s); return *this;}
    Sat& PomjeriZa(int ss) {s += ss; if(!DaLiJeIspravno(h,m,s)) Normaliziraj(h, m, s); return *this;}
    int DajSate() const {return this->h;}
    int DajMinute() const {return this->m;}
    int DajSekunde() const {return this->s;}
    void Ispisi() const {cout<<setfill('0')<<setw(2)<<h<<":"<<setfill('0')<<setw(2)<<m<<":"<<setfill('0')<<setw(2)<<s;}
    static int Razmak(const Sat& s1,const Sat& s2);

    friend int BrojSekundiIzmedju(const Sat& s1,const Sat& s2);
};

void Sat::Normaliziraj(int& hh, int& mm, int& ss){
    int sekunde = ss + mm*60 + hh*3600;
    if(sekunde < 0){
        int t = sekunde / 86400;
        sekunde += (-t+1) * 86400;
    }
    if(sekunde > 86400) sekunde %= 86400;
    hh = sekunde / 3600;
    mm = (sekunde - hh * 3600) / 60;
    ss = sekunde - hh * 3600 - mm * 60;
}

int Sat::Razmak(const Sat& s1, const Sat& s2){
    int sekunde1 = s1.h*3600 + s1.m*60 + s1.s;
    int sekunde2 = s2.h*3600 + s2.m*60 + s2.s;
    return sekunde1 - sekunde2;
}

int BrojSekundiIzmedju(const Sat& s1, const Sat &s2){
    int sekunde1 = s1.h*3600 + s1.m*60 + s1.s;
    int sekunde2 = s2.h*3600 + s2.m*60 + s2.s;
    return sekunde1 - sekunde2;
}



int main()
{
    Sat s;
    int h, m, ss;
    h = 0;
    m = 0;
    ss = -1;
    try{
        s.Postavi(h,m,ss);
    }
    catch(domain_error& e){
        cout<<e.what()<<endl;
        s.PostaviNormalizirano(h,m,ss);
    }
    cout<<Sat::DaLiJeIspravno(25,3,3)<<endl;
    s.Ispisi();
    s.Sljedeci().Sljedeci();
    cout<<endl;
    s.Ispisi();
    s.Prethodni();
    cout<<endl;
    s.Ispisi();
    cout<<endl;
    s.PomjeriZa(-13);
    s.Ispisi();
    cout<<endl;
    Sat s2;
    s2.PostaviNormalizirano(h,m,ss);
    cout<<BrojSekundiIzmedju(s2,s);
    return 0;
}
