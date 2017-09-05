#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>

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
    const char* DajImeTime() const {return ime_tima;}
    int DajBrojPoena() const { return broj_poena;}
    int DajGolRazliku() const { return broj_datih - broj_primljenih;}
    void IspisiPodatke() const;
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

int main()
{

    return 0;
}
