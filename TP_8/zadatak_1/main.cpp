#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

struct Vrijeme{
    int sati;
    int minute;
    int sekunde;
};

void TestirajVrijeme(Vrijeme v){
    if(v.sati < 0 || v.sati > 23
    || v.minute < 0 || v.minute > 59
    || v.sekunde < 0 || v.sekunde > 59) throw domain_error("Neispravno vrijeme");
    return;
}

Vrijeme SaberiVrijeme(Vrijeme v1, Vrijeme v2){
    Vrijeme sol;
    int vrijemeUSekundama;
    vrijemeUSekundama = v1.sekunde + v2.sekunde;
    vrijemeUSekundama += v1.minute * 60 + v2.minute * 60;
    vrijemeUSekundama += v1.sati * 3600 + v2.sati * 3600;

    sol.sati = (vrijemeUSekundama / 3600) % 24;
    sol.minute = (vrijemeUSekundama - (vrijemeUSekundama / 3600) * 3600) / 60;
    sol.sekunde = vrijemeUSekundama - (vrijemeUSekundama / 3600) * 3600 - sol.minute * 60;

    return sol;
}

void IspisiVrijeme(Vrijeme v){
    TestirajVrijeme(v);
    cout<<setfill('0')<<setw(2)<<v.sati<<":"<<setfill('0')<<setw(2)<<v.minute<<":"<<setfill('0')<<setw(2)<<v.sekunde;
    return;
}

int main()
{
    Vrijeme v1;
    Vrijeme v2;

    cout<<"Unesite prvo vrijeme (h m s): ";
    cin>>v1.sati>>v1.minute>>v1.sekunde;
    try{
        TestirajVrijeme(v1);
    }
    catch(domain_error& e){
        cout<<e.what();
        return -1;
    }

    cout<<"Unesite drugo vrijeme (h m s): ";
    cin>>v2.sati>>v2.minute>>v2.sekunde;
    try{
        TestirajVrijeme(v2);
    }
    catch(domain_error& e){
        cout<<e.what();
        return -1;
    }
    cout<<"Prvo vrijeme: ";
    IspisiVrijeme(v1);
    cout<<"\nDrugo vrijeme: ";
    IspisiVrijeme(v2);
    cout<<"\nZbir vremena: ";
    IspisiVrijeme(SaberiVrijeme(v1,v2));
    return 0;
}
