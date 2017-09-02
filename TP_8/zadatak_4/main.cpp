#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;



void ZamijeniPremaRjecniku(string &s, map<string, string> m){
    vector<int> pozicijaRijeci;
    vector<int> duzinaRijeci;

    s.push_back(' ');
    bool whitespace = true;
    for(int i = 0; i < s.size(); i++){
        if(!isspace(s[i])){
            if(whitespace){
                whitespace = false;
                pozicijaRijeci.push_back(i);
            } else continue;
        } else {
            if(!whitespace){
                whitespace = true;
                duzinaRijeci.push_back(i - pozicijaRijeci[pozicijaRijeci.size() - 1]);
            } else continue;
        }
    }
    s.pop_back();
    for(int i = pozicijaRijeci.size(); i >= 0; i--)
        if(m.find(s.substr(pozicijaRijeci[i], duzinaRijeci[i])) != m.end())
            s.replace(pozicijaRijeci[i], duzinaRijeci[i], m[s.substr(pozicijaRijeci[i], duzinaRijeci[i])]);
}

int main()
{
    string s;
    getline(cin, s);

    map<string, string> moj_rjecnik{{"jabuka", "apple"}, {"da", "yes"},
                                {"ne", "no"}, {"kako", "how"},
                                {"majmun", "ape"}};
    ZamijeniPremaRjecniku(s, moj_rjecnik);
    cout<<s;
    return 0;
}
