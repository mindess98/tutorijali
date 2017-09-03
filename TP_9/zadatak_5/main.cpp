#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Sat
{
    int s;
    static void Normaliziraj(int& hh, int& mm, int& ss);
    static void Normaliziraj(int& sekunde);
public:
    static bool DaLiJeIspravno(int h, int m, int s) { return h>0&&h<24 && m>0&&m<60 && s>0&&s<60;}
    void Postavi(int hh, int mm, int ss);
    void PostaviNormalizirano(int hh, int mm, int ss);
    Sat& Sljedeci() {s++; if(!DaLiJeIspravno(DajSate(),DajMinute(),DajSekunde())) Normaliziraj(s); return *this;}
    Sat& Prethodni() {s--; if(!DaLiJeIspravno(DajSate(),DajMinute(),DajSekunde())) Normaliziraj(s); return *this;}
    Sat& PomjeriZa(int ss) {s += ss; if(!DaLiJeIspravno(DajSate(),DajMinute(),DajSekunde())) Normaliziraj(s); return *this;}
    int DajSate() const {return this->s / 3600;}
    int DajMinute() const {return (this->s - DajSate()*3600) / 60;}
    int DajSekunde() const {return this->s - DajSate()*3600 - DajMinute()*60;}
    void Ispisi() const {cout<<setfill('0')<<setw(2)<<this->DajSate()<<":"<<setfill('0')<<setw(2)<<this->DajMinute()<<":"<<setfill('0')<<setw(2)<<this->DajSekunde();}
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
    mm = sekunde - hh*3600;
    ss = sekunde - hh*3600 - mm*60;
}
void Sat::Normaliziraj(int& sekunde){
    if(sekunde < 0){
        int t = sekunde / 86400;
        sekunde += (-t+1) * 86400;
    }
    if(sekunde > 86400) sekunde %= 86400;
}

int Sat::Razmak(const Sat& s1, const Sat& s2){
    return s1.s - s2.s;
}

int BrojSekundiIzmedju(const Sat& s1, const Sat &s2){
    return s1.s - s2.s;
}

 void Sat::Postavi(int hh, int mm, int ss)
 {
    if(!DaLiJeIspravno(hh,mm,ss)) throw domain_error("Neispravno vrijeme");
    this->s = hh*3600 + mm*60 +ss;
}

void Sat::PostaviNormalizirano(int hh, int mm, int ss)
{
    if(!DaLiJeIspravno(hh,mm,ss)) Normaliziraj(hh, mm, ss);
    this->s = hh*3600 + mm*60 + ss;
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
    cout<<Sat::DaLiJeIspravno(s.DajSate(),s.DajMinute(),s.DajSekunde())<<endl;
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
