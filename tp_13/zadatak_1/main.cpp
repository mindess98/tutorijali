#include <iostream>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <cctype>
#include <string>
#include <cstdio>

using namespace std;

class Lik
{
public:
    virtual void IspisiSpecificnosti() const = 0;
    virtual double DajObim() const = 0;
    virtual double DajPovrsinu() const = 0;
    virtual void Ispisi() const {IspisiSpecificnosti(); cout<<endl<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu();}
};

class Krug : public Lik
{
    double r;
    static constexpr double PI = acos(-1);
public:
    Krug(double r) : r(r) { if(r <= 0) throw domain_error("Neispravni parametri");}
    void IspisiSpecificnosti() const{ cout<<"Krug poluprecnika "<<r; };
    double DajObim() const {return 2*PI*r;}
    double DajPovrsinu() const {return r*r*PI;}
};

class Pravougaonik : public Lik
{
    double a,b;
public:
    Pravougaonik(double a, double b) : a(a), b(b) { if(a<=0 || b<=0) throw domain_error("Neispravni parametri");}
    void IspisiSpecificnosti() const {cout<<"Pravougaonik sa stranicama duzine "<<a<<" i "<<b; }
    double DajObim() const { return 2*a + 2*b; }
    double DajPovrsinu() const { return a * b; }
};

class Trougao : public Lik
{
    double a, b, c;
public:
    Trougao(double a, double b, double c) : a(a), b(b), c(c) { if(c>=a+b || a>=b+c || b>=a+c) throw domain_error("Neispravni parametri"); }
    void IspisiSpecificnosti() const { cout<<"Trougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c; }
    double DajObim() const { return a + b + c; }
    double DajPovrsinu() const { double s = DajObim() / 2; return sqrt(s*(s-a)*(s-b)*(s-c)); }
};
int main()
{
    cout<<"Koliko zelite likova: ";
    int n;
    cin>>n;
    vector<shared_ptr<Lik>> v;
    for(;v.size() < n;){
            /*
        double a,b,c;
        cout<<"Lik "<<v.size()+1<<": ";
        try{
            switch(toupper(cin.get())){
            case 'K':
                cin.unget();
                if(!scanf("%c%lf\n", &a)) throw exception();
                v.push_back(make_shared<Krug>(a));
                break;
            case 'P':
                cin.unget();
                if(!scanf("%c%lf,%lf\n", &a, &b)) throw exception();
                v.push_back(make_shared<Pravougaonik>(a,b));
                break;
            case 'T':
                cin.unget();
                if(!scanf("%c%lf,%lf,%lf\n", &a, &b, &c)) throw exception();
                v.push_back(make_shared<Trougao>(a,b,c));
                break;
            default:
                throw exception();
            }
        } catch(...) {
            cout<<"Pogresni podaci, ponovite unos!"<<endl;
        }
        */
        char c;
        cout<<"Lik "<<v.size()+1<<": ";
        cin>>c;
        try{
            switch(toupper(c)){
            case 'K':
               double r;
               cin>>r;
               if(cin.peek() != '\n') throw exception();
               if(!cin) throw exception();
               v.push_back(make_shared<Krug>(r));
               break;
            case 'T':
                double x,y,z;
                if(scanf("%lf,%lf,%lf",&x,&y,&z) != 3) throw exception();
                v.push_back(make_shared<Trougao>(x,y,z));
                break;
            case 'P':
                double w,q;
                if(scanf("%lf,%lf",&w,&q) != 2) throw exception();
                v.push_back(make_shared<Pravougaonik>(w,q));
                break;
            default :
                throw exception();
            }
        }
        catch(...) {
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"Pogresni podaci, ponovite unos!\n";
        }

    }
    for(auto t : v){
        t->Ispisi();
        cout<<endl;
    }

    return 0;
}
