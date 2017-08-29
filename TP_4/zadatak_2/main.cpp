#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

void Izvrni(string& s){
    for(int i = 0, j = s.size()-1; i < j; i++, j--)
        swap(s[i], s[j]);
    return;
}

int main()
{
    cout<<"Unesite recenicu: ";
    string s;
    getline(cin, s);
    Izvrni(s);
    cout << s << endl;
    return 0;
}
