#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <string>

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

    friend bool porediTimove(Tim* t1, Tim* t2);
};

class Liga
{
    int broj_timova;
    const int max_br_timova;
    Tim** timovi;

    int nadjiTim(const char ime[]);
public:
    explicit Liga(int velicina_lige);
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

Liga::Liga(int velicina_lige) : max_br_timova(velicina_lige), broj_timova(0)
{
    if(velicina_lige <= 0){
        timovi = nullptr;
        throw range_error("Neispravna velicina lige");
    }
    try{
        timovi = new Tim*[max_br_timova];
    }
    catch(bad_alloc& e){
        throw bad_alloc();
    }
    catch(...){
        throw exception();
    }
}
Liga::Liga(initializer_list<Tim> lista_timova) : max_br_timova(lista_timova.size()), broj_timova(lista_timova.size())
{
    try{
        auto p = lista_timova.begin();
        timovi = new Tim*[broj_timova];
        for(int i = 0; i < broj_timova; i++, p++)
            timovi[i] = new Tim(p->DajImeTima());
    }
    catch(bad_alloc& e){
        throw bad_alloc();
    }
    catch(...){
        throw exception();
    }
}

Liga::~Liga()
{
    if(max_br_timova <= 0) return;
    if(broj_timova <= 0) delete[] timovi;
    for(int i = 0; i < broj_timova; i++)
        delete timovi[i];
    delete[] timovi;
}

int Liga::nadjiTim(const char ime[])
{
    if(broj_timova == 0) return -1;
    for(int i = 0; i < broj_timova; i++)
        if(strcmp(timovi[i]->DajImeTima(), ime)==0) return i;
    return -1;

}
Liga::Liga(const Liga& l) : max_br_timova(l.max_br_timova), broj_timova(l.broj_timova)
{
    try{
        this->timovi = new Tim*[max_br_timova];
        for(int i = 0; i < broj_timova; i++)
            this->timovi[i] = new Tim(l.timovi[i]->DajImeTima());
    }
    catch(bad_alloc& e){
        throw bad_alloc();
    }
    catch(...){
        throw exception();
    }
}
Liga::Liga(Liga&& l) : max_br_timova(l.max_br_timova), broj_timova(l.broj_timova), timovi(l.timovi){}
Liga& Liga::operator=(const Liga& l)
{
    if(this->max_br_timova != l.max_br_timova) throw logic_error("Nesaglasni broj timova");
    if(this->timovi == l.timovi) return *this;
    try{
        for(int i = 0; i < this->broj_timova; i++)
            delete timovi[i];
        delete[] timovi;
        this->timovi = new Tim*[l.max_br_timova];
        for(int i = 0; i < l.broj_timova; i++)
            this->timovi[i] = new Tim(l.timovi[i]->DajImeTima());
    }
    catch(range_error& e){
        throw e;
    }
    catch(bad_alloc& e){
        throw e;
    }
    catch(...){
        throw exception();
    }
    this->broj_timova = l.broj_timova;
    return *this;
}
Liga& Liga::operator=(Liga&& l)
{
    if(this->max_br_timova != l.max_br_timova) throw logic_error("Nesaglasni kapaciteti liga");
    if(this->timovi == l.timovi) return *this;
    this->timovi = l.timovi;
    this->broj_timova = l.broj_timova;
    return *this;
}
void Liga::DodajNoviTim(const char ime_tima[])
{
    if(broj_timova == max_br_timova) throw range_error("Liga popunjena");
    if(nadjiTim(ime_tima) == -1 && broj_timova != 0) throw logic_error("Tim vec postoji");
    try{
        timovi[broj_timova++] = new Tim(ime_tima);
    }
    catch(range_error& e){
        throw e;
    }
    catch(bad_alloc& e){
        throw e;
    }
    catch(...){
        throw exception();
    }
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
{
    int i = nadjiTim(tim1);
    int j = nadjiTim(tim2);
    if(i == -1 || j == -1) throw logic_error("Tim nije nadjen");
    timovi[i]->ObradiUtakmicu(rezultat_1, rezultat_2);
    timovi[j]->ObradiUtakmicu(rezultat_2, rezultat_1);
}

bool porediTimove(Tim* t1, Tim* t2)
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
    sort(timovi, timovi + broj_timova, porediTimove);
    for(int i = 0; i < broj_timova; i++)
        timovi[i]->IspisiPodatke();
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

        int g1, g2;
        cout<<"Unesite broj postignutih golova za oba tima: ";
        cin>>g1>>g2;

        try{
            l.RegistrirajUtakmicu(s1.c_str(), s2.c_str(), g1, g2);
        }
        catch(logic_error& e){
            cout<<e.what()<<endl;
        }
        l.IspisiTabelu();

    } while(true);

    return 0;
}
