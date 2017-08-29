#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

long double myPow(double baza, int eksponent){
    long double sol = 1;

    if(eksponent >= 0){
        for(int i = 0; i < eksponent; i++) sol *= baza;
    }
    else {
        for(int i = 0; i < -eksponent; i++) sol /= baza;
    }

    return sol;
}

template <typename T>
void UnosBroja(string prompt, string err, T& broj){


    string  line;

    cout<<prompt;
    while(getline(cin, line))
    {
        stringstream linestream(line);
        if (!(linestream >> broj))
        {
            cout<<err;
            continue;
        }
        char peekChar;
        if (linestream >> peekChar)
        {
            if(peekChar == '\n') return;
            cout<<err;
            continue;
        }
        break;
    }
    return;
}

int main()
{
    double baza;
    UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...", baza);
    int eksponent;
    UnosBroja("Unesite cijelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...", eksponent);

    cout<< myPow(baza, eksponent);
    return 0;
}
