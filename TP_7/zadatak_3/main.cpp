#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    cout<<"Koliko zelite recenica: ";
    int n;
    cin>>n;

    string* c;
    try{
        cout<<"Unesite recenice:\n";
        c = new string[n];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int i = 0; i < n; i++)
            getline(cin, c[i]);
    }
    catch(...){
        cout<<"Problemi sa memorijom";
        delete[] c;
        return -1;
    }

    sort(c, c+n);

    cout<<"Sortirane recenice:\n";
    for(int i = 0; i < n; i++)
        cout<<c[i]<<endl;

    delete[] c;
    return 0;
}
