#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Tim
{
    char ime_tima[21];
    int broj_odigranih;
    int broj_pobjeda;
    int broj_nerijesenih;
    int broj_poraza;
    int broj_datih;
    int broj_primljenih;
    int broj_poena;
public:
    Tim(const char ime[]) : broj_odigranih(0), broj_pobjeda(0), broj_nerijesenih(0), broj_poraza(0), broj_datih(0), broj_primljenih(0), broj_poena(0) { if(strlen(ime) > 20) throw range_error("Predugacko ime time"); strcpy(ime_tima, ime);}
    void ObradiUtakmicu(int broj_datih, int broj_primljenih);
    const char* DajImeTima() const {return ime_tima;}
    int DajBrojPoena() const { return broj_poena;}
    int DajGolRazliku() const { return broj_datih - broj_primljenih;}
    void IspisiPodatke() const;

    friend bool porediTimove(shared_ptr<Tim> t1, shared_ptr<Tim> t2);
};

class Liga
{
     vector<shared_ptr<Tim>> timovi;
    int nadjiTim(const char ime[]);
public:
    explicit Liga(int velicina_lige = 0);
    explicit Liga(std::initializer_list<Tim> lista_timova);
    ~Liga();
    Liga(const Liga& l);
    Liga(Liga&& l);
    Liga& operator=(const Liga& l);
    Liga& operator=(Liga&& l);
    void DodajNoviTim(const char ime_tima[]);
    void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2);
    void IspisiTabelu();
};

void Tim::ObradiUtakmicu(int brDatih, int brPrimljenih)
{
    if(brDatih < 0 || brPrimljenih < 0) throw range_error("Neispravan broj golova");
    broj_datih += brDatih;
    broj_primljenih += brPrimljenih;
    broj_odigranih++;
    if(brDatih > brPrimljenih){
        broj_pobjeda++;
        broj_poena+=3;
    }
    if(brDatih < brPrimljenih){
        broj_poraza++;
    }
    if(brDatih == brPrimljenih){
        broj_nerijesenih++;
        broj_poena++;
    }

}

void Tim::IspisiPodatke() const
{
    cout<<setw(20)<<left<<ime_tima<<right<<setw(4)<<broj_odigranih
        <<setw(4)<<broj_pobjeda<<setw(4)<<broj_nerijesenih
        <<setw(4)<<broj_poraza<<setw(4)<<broj_datih
        <<setw(4)<<broj_primljenih<<setw(4)<<broj_poena<<endl;

}

Liga::Liga(int velicina_lige) : timovi(velicina_lige)
{
}

Liga::Liga(initializer_list<Tim> lista_timova)
{
    for(auto p = lista_timova.begin(); p != lista_timova.end(); p++)
        timovi.push_back(make_shared<Tim>(p->DajImeTima()));
}

Liga::~Liga()
{
}

int Liga::nadjiTim(const char ime[])
{
    if(timovi.size() == 0) return -1;
    for(int i = 0; i < timovi.size(); i++)
        if(strcmp(timovi[i]->DajImeTima(), ime) == 0) return i;
    return -1;

}
Liga::Liga(const Liga& l)
{
    this->timovi = l.timovi;
}
Liga::Liga(Liga&& l) : timovi(move(l.timovi)){}
Liga& Liga::operator=(const Liga& l)
{
    this->timovi = l.timovi;
    return *this;
}
Liga& Liga::operator=(Liga&& l)
{
    this->timovi = move(l.timovi);
    return *this;
}
void Liga::DodajNoviTim(const char ime_tima[])
{
    if(nadjiTim(ime_tima) == -1 && timovi.size() > 0) throw logic_error("Tim vec postoji");
        timovi.push_back(make_shared<Tim>(ime_tima));
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
{
    int i = nadjiTim(tim1);
    int j = nadjiTim(tim2);
    if(i == -1 || j == -1) throw logic_error("Tim nije nadjen");
    timovi[i]->ObradiUtakmicu(rezultat_1, rezultat_2);
    timovi[j]->ObradiUtakmicu(rezultat_2, rezultat_1);
}

bool porediTimove(shared_ptr<Tim> t1, shared_ptr<Tim> t2)
{
    if(t1->broj_poena > t2->broj_poena) return true;
    if(t1->broj_poena < t2->broj_poena) return false;
    if(t1->broj_poena == t2->broj_poena){
        if(t1->broj_datih - t1->broj_primljenih > t2->broj_datih - t2->broj_primljenih) return true;
        if(t1->broj_datih - t1->broj_primljenih > t2->broj_datih - t2->broj_primljenih) return false;
        return strcmp(t1->ime_tima, t2->ime_tima) == -1;
    }
}

void Liga::IspisiTabelu()
{
    sort(timovi.begin(), timovi.end(), porediTimove);
    for(auto p : timovi)
        p->IspisiPodatke();
}


int main()
{
    Liga l{"Sarajevo", "Zrinjski", "Jednistvno" ,"Borac", "Celik", "Zeljeznicar"};
    l.IspisiTabelu();

    do{
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
        }
        string s1, s2;
        cout<<"\nUnesite ime prvog tima (Q za kraj): ";
        getline(cin, s1);
        if(s1 == "Q") return 0;
        cout<<"Unesite ime drugog tima: ";
        getline(cin, s2);
        cin.ignore(10000, '\n');

        int g1, g2;
        cout<<"Unesite broj postignutih golova za oba tima: ";
        cin>>g1>>g2;

        try{
            l.RegistrirajUtakmicu(s1.c_str(), s2.c_str(), g1, g2);
        }
        catch(logic_error& e){
            cout<<e.what();
        }
        cout<<endl<<endl;
        l.IspisiTabelu();

    } while(true);

    return 0;
}
