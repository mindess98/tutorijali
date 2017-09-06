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
    static void Normaliziraj(Sat& sat);
public:
    static bool DaLiJeIspravno(int h, int m, int s) { return h>0&&h<24 && m>0&&m<60 && s>0&&s<60;}
    void Postavi(int hh, int mm, int ss) {if(!DaLiJeIspravno(hh,mm,ss)) throw domain_error("Neispravno vrijeme");
                                          this->h = hh; this->m = mm; this->s = ss;}
    Sat(int hh, int mm, int ss) {if(!DaLiJeIspravno(hh,mm,ss)) Normaliziraj(hh, mm, ss);
                                                       this->h = hh; this->m = mm; this->s = ss;}
    Sat() : h(0), m(0), s(0) {}
    friend Sat& operator++(Sat& sat) {++sat.s; if(!DaLiJeIspravno(sat.h,sat.m,sat.s)) Normaliziraj(sat.h, sat.m, sat.s); return sat;}
    friend Sat& operator--(Sat& sat) {--sat.s; if(!DaLiJeIspravno(sat.h,sat.m,sat.s)) Normaliziraj(sat.h, sat.m, sat.s); return sat;}
    friend Sat operator++(Sat& sat, int a) {Sat sa(sat);++sat.s; if(!DaLiJeIspravno(sat.h,sat.m,sat.s)) Normaliziraj(sat.h, sat.m, sat.s); return sa;}
    friend Sat operator--(Sat& sat, int a) {Sat sa(sat);--sat.s; if(!DaLiJeIspravno(sat.h,sat.m,sat.s)) Normaliziraj(sat.h, sat.m, sat.s); return sa;}
    Sat& operator+=(int ss) {s += ss; if(!DaLiJeIspravno(h,m,s)) Normaliziraj(h, m, s); return *this;}
    Sat& operator-=(int ss) {s -= ss; if(!DaLiJeIspravno(h,m,s)) Normaliziraj(h, m, s); return *this;}
    int DajSate() const {return this->h;}
    int DajMinute() const {return this->m;}
    int DajSekunde() const {return this->s;}
    friend ostream& operator<<(ostream& tok, const Sat& sat) {return tok<<setfill('0')<<setw(2)<<sat.h<<":"<<setfill('0')<<setw(2)<<sat.m<<":"<<setfill('0')<<setw(2)<<sat.s<<endl;}

    friend int operator-(const Sat& s1, const Sat& s2);
    friend Sat operator+(const Sat& s1, const Sat& s2);
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

void Sat::Normaliziraj(Sat& sat){
    Normaliziraj(sat.h, sat.m, sat.s);
}

int operator-(const Sat& s1, const Sat &s2){
    int sekunde1 = s1.h*3600 + s1.m*60 + s1.s;
    int sekunde2 = s2.h*3600 + s2.m*60 + s2.s;
    return sekunde1 - sekunde2;
}

Sat operator+(const Sat& s1, const Sat& s2){
    Sat s3(s1.h + s2.h, s1.m + s2.m, s1.s + s2.s);
    Sat::Normaliziraj(s3);
    return s3;
}


int main()
{
    int h, m, ss;
    h = 0;
    m = 0;
    ss = -1;
    Sat s(h,m,ss);
    cout<<s;
    cout<<s++;
    cout<<s--;
    --s;
    --s;
    cout<<s;
    s+=13;
    Sat s2(h,m,ss);

    cout<<s<<s2;
    cout<<s2-s<<endl;
    cout<<s2+s;
    return 0;
}
