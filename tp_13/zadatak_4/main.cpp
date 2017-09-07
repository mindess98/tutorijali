#include <iostream>
#include <string>
#include <stdexcept>

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
    void IspisiPodatke() const {cout<<"Student bachelor studija "<<ime<<" "<<prezime<<", sa brojem indeksa "<<brIndeksa<<", ima prosjek "<<proOcjena<<"."<<endl;}
    StudentBachelor* DajKopiju() const { return new StudentBachelor(ime, prezime, brIndeksa);}
};

class StudentMaster : public ApstraktniStudent
{
    int godina;
public:
    StudentMaster(string ime, string prezime, int brIndeksa, int godina) : ApstraktniStudent(ime, prezime, brIndeksa), godina(godina) {}
    void IspisiPodatke() const {cout<<"Student master studija "<<ime<<" "<<prezime<<", sa brojem indeksa "<<brIndeksa<<", zavrsio bachelor studij godine "<<godina<<", ima prosjek "<<proOcjena<<"."<<endl;}
    StudentMaster* DajKopiju() const { return new StudentMaster(ime, prezime, brIndeksa, godina); }
};

class Student
{
    ApstraktniStudent* s;
public:
    Student() : s(nullptr) {}
    Student(string ime, string prezime, int brIndeksa) : s(new StudentBachelor(ime, prezime, brIndeksa)) {}
    Student(string ime, string prezime, int brIndeksa, int godina) : s(new StudentMaster(ime, prezime, brIndeksa, godina)) {}
    Student& operator=(StudentBachelor sb) { delete s; s = sb.DajKopiju(); return *this;}
    Student& operator=(StudentMaster sm) { delete s; s = sm.DajKopiju(); return *this;}
    void RegistrirajIspit(int ocjena) { s->RegistrirajIspit(ocjena); }
    void IspisiPodatke() const { s->IspisiPodatke(); }
};

int main()
{
    Student s1, s2;

    return 0;
}
