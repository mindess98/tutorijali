#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

class ApstraktniStudent
{
protected:
    string ime;
    string prezime;
    int brIndeksa;
    int brPolozenih;
    double proOcjena;

public:
    ApstraktniStudent(string ime, string prezime, int brIndeksa) : ime(ime), prezime(prezime), brIndeksa(brIndeksa), brPolozenih(0), proOcjena(5) {}
    string DajIme() const { return ime; }
    string DajPrezime() const { return prezime; }
    int DajBrojIndeksa() const { return brIndeksa; }
    int DajBrojPolozenih() const { return brPolozenih; }
    double DajProsjek() const { return proOcjena; }
    void RegistrirajIspit(int ocjena){
        if(ocjena < 5) throw domain_error("Neispravna ocjena");
        if(ocjena > 5) {
            proOcjena *= brPolozenih;
            brPolozenih++;
            proOcjena += ocjena;
            proOcjena /= brPolozenih;
        }
    }
    void PonistiOcjene() {brPolozenih = 0; proOcjena = 5;}
    virtual void IspisiPodatke() const = 0;
    virtual ApstraktniStudent* DajKopiju() const = 0;
};

class StudentBachelor : public ApstraktniStudent
{
public:
    StudentBachelor(string ime, string prezime, int brIndeksa) : ApstraktniStudent(ime, prezime, brIndeksa) {}
    void IspisiPodatke() const {cout<<"Student bachelor studija "<<ime<<" "<<prezime<<", sa brojem indeksa "<<brIndeksa<<", ima prosjek "<<proOcjena<<".";}
    StudentBachelor* DajKopiju() const { return new StudentBachelor(ime, prezime, brIndeksa);}
};

class StudentMaster : public ApstraktniStudent
{
    int godina;
public:
    StudentMaster(string ime, string prezime, int brIndeksa, int godina) : ApstraktniStudent(ime, prezime, brIndeksa), godina(godina) {}
    void IspisiPodatke() const {cout<<"Student master studija "<<ime<<" "<<prezime<<", sa brojem indeksa "<<brIndeksa<<", zavrsio bachelor studij godine "<<godina<<", ima prosjek "<<proOcjena<<".";}
    StudentMaster* DajKopiju() const { return new StudentMaster(ime, prezime, brIndeksa, godina); }
};

class Fakultet
{
    vector<ApstraktniStudent*> studenti;
    void DealocirajStudente() { for(ApstraktniStudent* s : studenti) delete s; studenti.resize(0);}
    vector<ApstraktniStudent*>::iterator NadjiStudenta(int ind){ for(auto p = studenti.begin(); p != studenti.end(); p++)
                                                                            if((*p)->DajBrojIndeksa() == ind) return p;
                                                                        return studenti.end();}
public:
    Fakultet()  { for(auto s : studenti) s = nullptr;}
    Fakultet(const Fakultet& f) { for(ApstraktniStudent const* s : f.studenti)
                                    this->studenti.push_back(s->DajKopiju()); }
    Fakultet& operator=(const Fakultet& f) { for(ApstraktniStudent const* s : f.studenti)
                                                this->studenti.push_back(s->DajKopiju());
                                             return *this; }
    Fakultet(Fakultet&& f) : studenti(f.studenti) { for(auto s : f.studenti) s = nullptr; }
    Fakultet& operator=(Fakultet&& f) { this->studenti = f.studenti; for(auto s : f.studenti) s = nullptr; }
    void UpisiStudenta(string ime, string prezime, int brIndeksa) {
        if(NadjiStudenta(brIndeksa) != studenti.end()) throw logic_error("Student sa zadanim brojem indeksa vec postoji");
        studenti.push_back(new StudentBachelor(ime, prezime, brIndeksa));
    }
    void UpisiStudenta(string ime, string prezime, int brIndeksa, int godina) {
        if(NadjiStudenta(brIndeksa) != studenti.end()) throw logic_error("Student sa zadanim brojem indeksa vec postoji");
        studenti.push_back(new StudentMaster(ime, prezime, brIndeksa, godina));
    }
    void ObrisiStudenta(int brIndeksa)
    {
        auto x = NadjiStudenta(brIndeksa);
        if(x != studenti.end()) throw logic_error("Student sa zadanim brojem indeksa vec postoji");
        studenti.erase(x, ++x);
    }
    ApstraktniStudent& operator[](int ind)
    {
        auto x = NadjiStudenta(ind);
        if(x == studenti.end()) throw logic_error("Student sa zadanim brojem indeksa ne postoji");
        return **x;
    }

  /*  const ApstraktniStudent& operator[](int ind) const
    {
        auto x = NadjiStudenta(ind);
        if(x == studenti.end()) throw logic_error("Student sa zadanim brojem indeksa ne postoji");
        const& sol = **x;
        return sol;
    }
    */
    void IspisiSveStudente() //const
    {
        sort(studenti.begin(), studenti.end(), [](ApstraktniStudent* s1,  ApstraktniStudent* s2){ return s1->DajProsjek() > s2->DajProsjek();});
        for(ApstraktniStudent* s : studenti){
            s->IspisiPodatke();
            cout<<endl;
        }
    }
};

int main()
{
    Fakultet f;
    f.UpisiStudenta("tata", "ko", 16666);
    f.UpisiStudenta("jaja", "lo", 16665, 2018);
    f[16665].RegistrirajIspit(8);
    f.IspisiSveStudente();
    return 0;
}
