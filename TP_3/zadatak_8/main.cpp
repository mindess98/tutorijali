#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    string IzdvojiRijec(string, int);

    string r = IzdvojiRijec("   Na      vrh  brda  vrba mrda", 6);
    std::cout<<r;
    return 0;
}

string IzdvojiRijec(string s, int w){
    bool whitespace = true;
    int wrdcnt = 0;
    string sol;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'){
            whitespace = true;
            continue;
        } else {
            if(whitespace == false) continue;
            else {
                whitespace = false;
                if(++wrdcnt == w){
                    for(int j = i; j < s.size(); j++){
                        if(s[j] == ' ' || s[j] == '\t' || s[j] == '\n') break;
                        sol.push_back(s[j]);
                    }
                    return sol;
                }
            }
        }
    }
    if(wrdcnt < w) throw std::range_error("IZUZETAK: Pogresan redni broj rijeci!");
}
