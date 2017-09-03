#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Vektor3d{
    T koordinate[3];
public:
    void Postavi(T x, T y, T z){ this->koordinate[0] = x; this->koordinate[1] = y; this->koordinate[2] = z;}
    void Ocitaj(T& x, T& y, T& z) const { x = this->koordinate[0]; y = this->koordinate[1]; z = this->koordinate[2];}
    void Ispisi() const { cout<<"{"<<koordinate[0]<<","<<koordinate[1]<<","<<koordinate[2]<<"}";}
    T DajX() const {return this->koordinate[0];}
    T DajY() const {return this->koordinate[1];}
    T DajZ() const {return this->koordinate[2];}
    void PostaviX(T x) {this->koordinate[0] = x;}
    void PostaviY(T y) {this->koordinate[1] = y;}
    void PostaviZ(T z) {this->koordinate[2] = z;}
    double DajDuzinu() const { return sqrt(koordinate[0] * koordinate[0] + koordinate[1] * koordinate[1] + koordinate[2] * koordinate[2]);}
    void PomnoziSaSkalarom(T s) { koordinate[0] *= s; koordinate[1] *= s; koordinate[2] *= s;}
    void SaberiSa(const Vektor3d& v) { this->koordinate[0] += v.koordinate[0]; this->koordinate[1] += v.koordinate[1]; this->koordinate[2] += v.koordinate[2];}
    friend Vektor3d<T> ZbirVektora(const Vektor3d<T>& v1, const Vektor3d<T>& v2);
};

template <typename T>
Vektor3d<T> ZbirVektora(const Vektor3d<T>& v1, const Vektor3d<T>& v2){
    Vektor3d<T> v3;
    v3.koordinate[0] = v1.koordinate[0] + v2.koordinate[0];
    v3.koordinate[1] = v1.koordinate[1] + v2.koordinate[1];
    v3.koordinate[2] = v1.koordinate[2] + v2.koordinate[2];
    return v3;
}

int main()
{
    Vektor3d<int> v1;
    v1.Postavi(2, 3, 4);

    Vektor3d<int> v2;
    int x,y,z;
    v1.Ocitaj(x,y,z);
    v2.Postavi(2,3,4);
    v2.Ispisi();

    cout<<endl<<v1.DajDuzinu()<<endl;
    v2.PomnoziSaSkalarom(2);
    v2.Ispisi();


    return 0;
}
