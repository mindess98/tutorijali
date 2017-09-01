#include <iostream>
#include <string>
#include <limits>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    string s;

    cout<<"Koliko zelite recenica: ";
    int n;
    cin>>n;

    char** c;
    try{
        cout<<"Unesite recenice:\n";
        c = new char*[n];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int i = 0; i < n; i++){
            getline(cin, s);
            c[i] = new char[s.size() + 1];
            for(int j = 0; j < s.size(); j++)
                c[i][j] = s[j];
            c[i][s.size()] = '\0';
        }
    }
    catch(...){
        cout<<"Problemi sa memorijom";
        for(int i = 0; i < n; i++)
            delete[] c[i];
        delete[] c;
        return -1;
    }

    sort(c, c+n,                [](char* r1, char* r2){
                                    while(*r1 != '\0' && *r2 != '\0'){
                                        if(*r1 < *r2) return true;
                                        else if( *r1 > *r2) return false;
                                        r1++; r2++;
                                    }
                                    return false;
                                });


    cout<<"Sortirane recenice:\n";
    for(int i = 0; i < n; i++)
        printf("%s\n", c[i]);

    for(int i = 0; i < n; i++)
        delete[] c[i];
    delete[] c;
    return 0;
}
