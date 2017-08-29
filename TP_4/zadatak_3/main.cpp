#include <iostream>
#include <vector>
#include <string>

using namespace std;

void IzdvojiKrajnjeRijeci(const vector<string>& v, string& s_min, string& s_max){
    if(v.size() == 0){
        s_min = s_max = "";
        return;
    }
    s_min = s_max = v[0];
    for(const string& s : v){
        if(s > s_max) s_max = s;
        if(s < s_min) s_min = s;
    }
    return;
}

void ZadrziDuplikate(vector<string>& v){
    vector<string> pomocni;
    for(int i = 0; i < v.size(); i++){
        bool VecPostoji;
        VecPostoji = false;
        for(int j = 0; j < pomocni.size(); j++){
            if(pomocni[j] == v[i]){
                VecPostoji = true;
                break;
            }
        }
        if(!VecPostoji)
            for(int j = i + 1; j < v.size(); j++)
                if(v[i] == v[j]){
                    pomocni.push_back(v[i]);
                    break;
                }
    }
    v = pomocni;
    return;
}

int main()
{
    cout<<"Koliko zelite unijeti rijeci: ";
    int wrdcnt;
    cin>>wrdcnt;


    vector<string> v;

    cout<<"Unesite rijeci: ";
    cin.ignore(100,'\n');
    string s;
    for(int i = 0; i < wrdcnt; i++){
        cin>>s;
        v.push_back(s);
    }

    string smin, smax;
    IzdvojiKrajnjeRijeci(v, smin, smax);
    cout<<"Prva rijec po abecednom poretku je: "<<smin<<endl<<"Posljednja rijec po abecednom poretku je: "<<smax<<endl;

    ZadrziDuplikate(v);
    cout<<"Rijeci koje se ponavljaju su: ";
    for(string s : v)
        cout<<s<<" ";
    return 0;
}
