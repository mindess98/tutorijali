#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

template <typename T>
void UnosBroja(string prompt, string err, T& broj){

    cout<<prompt;

    string  line;
    line = "";
    while(getline(cin, line))
    {
        stringstream linestream(line);
        if (!linestream >> broj)
        {
            cout<<err;
            continue;
        }
        char peekChar;
        if (linestream >> peekChar)
        {
            cout<<err;
            continue;
        }
        break;
    }
    return;
}

int main()
{
    int broj;
    UnosBroja("Keks", "Pemeks", broj);

    cout<<broj;
    return 0;
}
