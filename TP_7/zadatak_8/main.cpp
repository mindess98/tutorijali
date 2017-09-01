#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string IzvrniBezRazmaka(string s){
    string sol;
    remove_copy(s.rbegin(),s.rend(), back_inserter(sol), ' ');
    return sol;
}

int main()
{
    cout<<"Unesite recenicu: ";
    string s;
    getline(cin, s);

    cout<<"Unesena recenica, izvrnuta bez razmaka: ";
    s = IzvrniBezRazmaka(s);
    cout<<s;
    return 0;
}
