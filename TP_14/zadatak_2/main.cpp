#include <iostream>
#include <cmath>
#include <stdexcept>
#include <fstream>
#include <algorithm>

using namespace std;

class Predmet
{
protected:
    double gustina;
public:
    Predmet(double gustina): gustina(gustina) { if(gustina <= 0){
                                                    gustina = 0;
                                                    throw exception(); } }
    virtual double DajZapreminu() const = 0;
    double DajTezinu() const {return DajZapreminu()*gustina; }
};

class Lopta : public Predmet
{
    double r;
public:
    static constexpr double PI = acos(-1);
    Lopta(double gustina, double r) : Predmet(gustina), r(r) {if(r <= 0){ r = 0; throw exception(); }}
    double DajZapreminu() const { return 4*PI*r*r*r/3; }
};

class Cigla : public Predmet
{
    double a, b, c;
public:
    Cigla(double gustina, double a, double b, double c) : Predmet(gustina), a(a), b(b), c(c) {if(a<=0||b<=0||c<=0) {a=b=c=0; throw exception(); }}
    double DajZapreminu() const { return a*b*c; }
};

int main()
{
    cout<<"Unesite ime datoteke: ";
    string datotekaString;
    getline(cin, datotekaString);

    ifstream ifs(datotekaString);
    if(!ifs) {
        cout<<"Trazena datoteka ne postoji";
        return -1;
    }
    int n;
    ifs>>n;
    if(!ifs) {
        cout<<"Neispravan prvi red";
        return -1;
    }
    if(ifs.peek() != '\n') {
        cout<<"Neispravan prvi red";
        return -1;
    }

    Predmet** p;

    try{
        p = new Predmet*[n];

        for(int i = 0; i < n; i++){
            string s;
            char c;
            double x,y,z,w;
            if(ifs.eof()){
                cout<<"Datoteka sadrzi manje od "<<n<<" elemenata, pogresan prvi red";
                return -1;
            }
            ifs>>c;
            switch(toupper(c)){
            case 'L':
                ifs>>x;
                if(!ifs) cout<<"Neispravan "<<i+2<<"-ti red"<<endl;
                ifs>>y;
                if(!ifs) cout<<"Neispravan "<<i+2<<"-ti red"<<endl;
                if(ifs.peek() != '\n' && !ifs.eof()) cout<<"Neispravan "<<i+2<<"-ti red"<<endl;
                p[i] = new Lopta(x,y);
                break;
            case 'C':
                ifs>>x;
                if(!ifs) {
                    cout<<"Neispravan "<<i+2<<"-ti red"<<endl;
                    return -1;
                }
                ifs>>y;
                if(!ifs){
                    cout<<"Neispravan "<<i+2<<"-ti red"<<endl;
                    return -1;
                }
                ifs>>z;
                if(!ifs) {
                    cout<<"Neispravan "<<i+2<<"-ti red"<<endl;
                    return -1;
                }
                ifs>>w;
                if(!ifs) {
                    cout<<"Neispravan "<<i+2<<"-ti red"<<endl;
                    return -1;
                }
                if(ifs.peek() != '\n' && !ifs.eof()){
                    cout<<"Neispravan "<<i+2<<"-ti red";
                    return -1;
                }
                p[i] = new Cigla(x,y,z,w);
                break;
            default:
                throw exception();
            }
            if(i == n - 1 && !ifs.eof()) cout<<"Datoteka sadrzi vise od "<<n<<" elemenata, pogresan prvi red"<<endl;
        }
    }
    catch(bad_alloc& e)
    {
        cout<<"Nedovoljno memorije!";
        for(int i = 0; i < n; i++)
            delete p[i];
        delete[] p;
    }
    catch(...)
    {
        cout<<"Neispravan format datoteke";
    }
    sort(p, p+n, [](Predmet* p1, Predmet* p2){ return p1->DajTezinu() > p2->DajTezinu();});

    for(int i = 0; i < n; i++)
        cout<<p[i]->DajTezinu()<<endl;
    return 0;
}
