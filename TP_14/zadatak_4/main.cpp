#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void IzvrniDatoteku(string dat)
{
    fstream fs(dat, ios::in | ios::out | ios::binary);
    fs.seekg(0, ios::end);
    int velicina_datoteke(fs.tellg());
    int broj_elemenata(velicina_datoteke / sizeof(double));
    for(int i = broj_elemenata - 1; i >= broj_elemenata / 2; i--){
        double broj1, broj2;
        fs.seekg(i * sizeof(double), ios::beg);
        fs.read(reinterpret_cast<char*>(&broj1), sizeof(double));
        fs.seekg((broj_elemenata - 1 - i) * sizeof(double), ios::beg);
        fs.read(reinterpret_cast<char*>(&broj2), sizeof(double));

        fs.seekp((broj_elemenata - 1 - i) * sizeof(double), ios::beg);
        fs.write(reinterpret_cast<char*>(&broj1), sizeof(double));
        fs.seekp(i * sizeof(double), ios::beg);
        fs.write(reinterpret_cast<char*>(&broj2), sizeof(double));
    }
}

void UpisiNiz(vector<double> v, string dat)
{
    ofstream ofs(dat, ios::binary);
    for(double d : v)
        ofs.write(reinterpret_cast<char*>(&d), sizeof (double));
}

vector<double> IspisiNiz(string dat)
{
    vector<double> sol;
    ifstream ifs(dat, ios::binary);
    ifs.seekg(0, ios::end);
    int velicina_datoteke(ifs.tellg());
    int broj_elemenata(velicina_datoteke / (sizeof(double)));
    for(int i = 0; i < broj_elemenata; i++){
        ifs.seekg(i * sizeof(double), ios::beg);
        double d;
        ifs.read(reinterpret_cast<char*>(&d), sizeof(double));
        sol.push_back(d);
    }
    return sol;
}

int main()
{
    vector<double> v {22.5, -3.14, -1.334e-12, 5555, -67.89, 4545};
    UpisiNiz(v, "datoteka.dat");

    vector<double> e = IspisiNiz("datoteka.dat");

    IzvrniDatoteku("datoteka.dat");

    vector<double> l = IspisiNiz("datoteka.dat");

    for(double d : e)
        cout<<d<<" ";
    cout<<endl;
    for(double d : l)
        cout<<d<<" ";
    return 0;
}
