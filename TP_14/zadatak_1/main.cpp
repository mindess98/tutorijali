#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using namespace std;

void provjeriIme(string s)
{
    for(char c : s)
        if(!isalpha(c) && c!='-' && c!=' ') throw exception();
}

void provjeriIndeks(string s)
{
    for(char c : s)
        if(!isdigit(c)) throw exception();
}

bool prestupna(int god)
{
    if(god % 400 == 0) return true;
    if(god % 100 == 0) return false;
    if(god % 4  == 0) return true;
    return false;
}

void provjeriDatum(string s)
{
    int daniUMjesecu[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int danMjesecGodina = 0;
    int datum[3]{};
    for(char c : s){
        if(!isdigit(c) && c!='/') throw exception();
        if(c == '/'){
            danMjesecGodina++;
            if(danMjesecGodina > 2) throw exception();
            continue;
        }
        datum[danMjesecGodina] = datum[danMjesecGodina]*10 + (c - 48);
    }
    if(datum[2] < 0) throw exception();
    if(prestupna(datum[2])) daniUMjesecu[1]++;
    if(datum[1] < 1 || datum[1] > 12) throw exception();
    if(datum[0] < 1 || datum[0] > daniUMjesecu[datum[1]-1]) throw exception();
}

vector<int> vratiOcjene(string s)
{
    int trenutnaOcjena = 0;
    vector<int> ocjene;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(!isdigit(c) && c!=',') throw exception();
        if(c == ','){
            if(i == s.size() - 1) throw exception();
            ocjene.push_back(trenutnaOcjena);
            trenutnaOcjena = 0;
            continue;
        }
        trenutnaOcjena = trenutnaOcjena*10 + (c - 48);
    }
    ocjene.push_back(trenutnaOcjena);
    for(int o : ocjene)
        if(o < 5 || o > 10) throw exception();
    return ocjene;
}

int main()
{
    ifstream ifs("STUDENTI.txt");
    if(!ifs){
        cout<<"Datoteka STUDENTI.TXT ne postoji!"<<endl;
        return -1;
    }
    string s;
    vector<vector<string>> v(4);
    int vrstaUpisa = 0;
    while(!ifs.eof()){
        if(ifs.bad()){
            cout<<"Problemi pri citanju datoteke STUDENTI.TXT"<<endl;
            return -1;
        }
        getline(ifs, s);
        v[vrstaUpisa++].push_back(s);
        vrstaUpisa %= 4;
    }
    int brojStudenata = v[0].size();
    vector<pair<double,int>> prosjeci;
    try{
        for(int i = 1; i < 4; i++)
            if(v[i].size() != brojStudenata) throw exception();
        for(int i = 0; i < brojStudenata; i++){
            provjeriIme(v[0][i]);
            provjeriIndeks(v[1][i]);
            provjeriDatum(v[2][i]);
            vector<int> ocjene = vratiOcjene(v[3][i]);
            int suma = 0;
            int brojPolozenih = ocjene.size();
            for(int o : ocjene){
                if(o != 5)
                    suma += o;
                else brojPolozenih--;
            }
            double prosjek;
            if(suma == 0) prosjek = 5;
            else prosjek = (suma + 0.0) / brojPolozenih;
            prosjeci.push_back(pair<double, int>(prosjek, i));
        }
    }
    catch(...)
    {
        cout<<"Neispravan format datoteke STUDENTI.TXT"<<endl;
        return -1;
    }
    sort(prosjeci.begin(), prosjeci.end(), [](pair<double, int> a, pair<double, int> b) {return a.first > b.first;});

    ofstream ofs("IZVJESTAJ.TXT");
    ofs<<setw(30)<<left<<"Student"<<setw(10)<<left<<"Indeks"<<setw(20)<<left<<"Datum rodjenja"<<setw(10)<<left<<"Prosjek"<<endl;
    ofs<<setw(30)<<left<<"-------"<<setw(10)<<left<<"------"<<setw(20)<<left<<"--------------"<<setw(10)<<left<<"-------"<<endl;
    for(int i = 0; i < prosjeci.size(); i++){
        ofs<<setw(30)<<left<<v[0][prosjeci[i].second];
        ofs<<setw(10)<<left<<v[1][prosjeci[i].second];
        ofs<<setw(20)<<left<<v[2][prosjeci[i].second];
        ofs<<setw(10)<<left<<setprecision(2)<<fixed<<prosjeci[i].first<<endl;
    }
    return 0;
}
