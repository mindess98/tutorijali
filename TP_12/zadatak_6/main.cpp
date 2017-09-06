#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>

using namespace std;

template <typename TipEl>
class Matrica
{
    int br_redova, br_kolona;
    TipEl** elementi;
    char ime_matrice;
    static TipEl** AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl** elemmenti, int br_redova);
    void KopirajElemente(TipEl** elementi);
public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const Matrica& m);
    Matrica(Matrica&& m);
    ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
    Matrica<TipEl>& operator=(const Matrica& m);
    Matrica<TipEl>& operator=(Matrica&& m);
    Matrica<TipEl>& operator+=(Matrica<TipEl>& m);
    Matrica<TipEl>& operator-=(Matrica<TipEl>& m);
    Matrica<TipEl>& operator*=(Matrica<TipEl>& m);
    Matrica<TipEl>& operator*=(const TipEl k);
    operator string() const;
    TipEl* operator[](int a);
    TipEl& operator()(int a, int b);
    template <typename Tip2>
    friend Matrica<Tip2> operator+(const Matrica<Tip2>& m1, const Matrica<Tip2>& m2);
    template <typename Tip2>
    friend istream& operator>>(istream& is, Matrica<Tip2>& m);
    template <typename Tip2>
    friend ostream& operator<<(ostream& os, const Matrica<Tip2>& m);
    template <typename Tip2>
    friend Matrica<Tip2> operator-(const Matrica<Tip2>& m1, const Matrica<Tip2>& m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator*(const Matrica<Tip2>& m1, const Matrica<Tip2>& m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator*(const Matrica<Tip2>& m, const Tip2 k);
    template <typename Tip2>
    friend Matrica<Tip2> operator*(const Tip2 k, const Matrica<Tip2>& m);
};

template <typename TipEl>
TipEl** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
    TipEl** elementi(new TipEl*[br_redova]{});
    try {
        for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
    }
    catch(...) {
        DealocirajMemoriju(elementi, br_redova);
        throw;
    }
    return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl** elementi, int br_redova)
{
    for(int i = 0; i < br_redova; i++) delete[] elementi[i];
    delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
    br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
    elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl** elementi)
{
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl>& m) :
    br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
    elementi(AlocirajMemoriju(br_redova, br_kolona))
{
    KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl>&& m) :
    br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
    elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
    m.br_redova = 0; m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator=(const Matrica<TipEl>& m)
{
    if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
        TipEl** novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
        DealocirajMemoriju(elementi, br_redova);
        elementi = novi_prostor;
    }
    else if(br_redova > m.br_redova)
        for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
    br_redova = m.br_redova; br_kolona = m.br_kolona;
    ime_matrice = m.ime_matrice;
    KopirajElemente(m.elementi);
    return *this;
}
template <typename TipEl>
ostream& operator<<(ostream& os, const Matrica<TipEl>& m)
{
    int wi = os.width();
    for(int i = 0; i < m.br_redova; i++){
        for(int j = 0; j < m.br_kolona; j++)
            os<< setw(wi) << m.elementi[i][j];
        os<<endl;
    }
    return os;
}

template <typename TipEl>
istream& operator>>(istream& is, Matrica<TipEl>& m)
{
    for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++) {
            cout<<m.ime_matrice<< "("<<i+1<<","<<j+1<<") = ";
            is>>m.elementi[i][j];
        }
    return is;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator=(Matrica<TipEl>&& m)
{
    swap(br_redova, m.br_redova); swap(br_kolona, m.br_kolona);
    swap(ime_matrice, m.ime_matrice); swap(elementi, m.elementi);
    return *this;
}

template <typename TipEl>
Matrica<TipEl> operator+(const Matrica<TipEl>& m1, const Matrica<TipEl>& m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename TipEl>
Matrica<TipEl> operator-(const Matrica<TipEl>& m1, const Matrica<TipEl>& m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
    return m3;
}
template <typename TipEl>
Matrica<TipEl> operator*(const Matrica<TipEl>& m, const TipEl k)
{
    Matrica<TipEl> sol(m.br_redova, m.br_kolona);
    for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
            sol.elementi[i][j] = m.elementi[i][j] * k;
    return sol;
}

template <typename TipEl>
Matrica<TipEl> operator*(const TipEl k, const Matrica<TipEl>& m)
{
    Matrica<TipEl> sol(m.br_redova, m.br_kolona);
    for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
            sol.elementi[i][j] = m.elementi[i][j] * k;
    return sol;
}
template <typename TipEl>
Matrica<TipEl> operator*(const Matrica<TipEl>& m1, const Matrica<TipEl>& m2)
{
    if(m1.br_kolona != m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> sol(m1.br_redova, m2.br_kolona);
    for(int i = 0; i < m1.br_redova; i++){
        for(int j = 0; j < m2.br_kolona; j++){
            TipEl suma{};
            for(int k = 0; k < m1.br_kolona; k++)
                suma += m1.elementi[i][k] * m2.elementi[k][j];
            sol.elementi[i][j] = suma;
        }
    }
    return sol;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator+=(Matrica<TipEl>& m)
{
    return *this = (*this) + m;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator-=(Matrica<TipEl>& m)
{
    return *this = (*this) - m;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator*=(Matrica<TipEl>& m)
{
    return *this = (*this) * m;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator*=(const TipEl k)
{
    return *this = (*this) * k;
}
template <typename TipEl>
TipEl* Matrica<TipEl>::operator[](int a)
{
    return this->elementi[a];
}
template <typename TipEl>
TipEl& Matrica<TipEl>::operator()(int a, int b)
{
    if(a < 1 || a > br_redova || b < 1 || b > br_kolona) throw range_error("Neispravan indeks");
    return elementi[a-1][b-1];
}

template <typename TipEl>
Matrica<TipEl>::operator string() const
{
    string sol;
    sol+="{";
    for(int i = 0; i < br_redova; i++){
        sol+="{";
        for(int j = 0; j < br_redova - 1; j++){
            sol+=to_string(elementi[i][j]);
            sol+=",";
        }
        sol+=to_string(elementi[i][br_redova-1]);
        sol+="}";
    }
    sol+="}";
    return sol;
}

using namespace std;

int main()
{

    Matrica<double> a(2,2,'A'), b(2,2,'B');
    cout<<"Unesi matricu A:\n";

    cin>>a;
    cout<<"Unesi matricu B:\n";
    cin>>b;
    cout<<"Zbir ove dvije matrice je:\n";
    cout<<setw(3)<<(a*=b);
    return 0;
}
