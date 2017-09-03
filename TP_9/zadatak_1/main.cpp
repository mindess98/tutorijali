#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Vektor3d{
    T x;
    T y;
    T z;
public:
    void Postavi(T x, T y, T z){ this->x = x; this->y = y; this->z = z;}
    void Ocitaj(T& x, T& y, T& z) const { x = this->x; y = this->y; z = this->z;}
    void Ispisi() const { cout<<"{"<<x<<","<<y<<","<<z<<"}";}
    T DajX() const {return this->x;}
    T DajY() const {return this->y;}
    T DajZ() const {return this->z;}
    void PostaviX(T x) {this->x = x;}
    void PostaviY(T y) {this->y = y;}
    void PostaviZ(T z) {this->z = z;}
    double DajDuzinu() const { return sqrt(x * x + y * y + z * z);}
    void PomnoziSaSkalarom(T s) { x *= s; y *= s; z *= s;}
    void SaberiSa(const Vektor3d& v) { this->x += v.x; this->y += v.y; this->z += v.z;}
    friend Vektor3d<T> ZbirVektora(const Vektor3d<T>& v1, const Vektor3d<T>& v2);
};

template <typename T>
Vektor3d<T> ZbirVektora(const Vektor3d<T>& v1, const Vektor3d<T>& v2){
    Vektor3d<T> v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
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
