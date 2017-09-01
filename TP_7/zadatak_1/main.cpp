#include <iostream>
#include <string>
#include <limits>
#include <cstdio>

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


    for(int k = 0; k < n; k++){
        char* minrec;
        int minind;
        minrec = c[k];
        minind = k;
        for(int i = k; i < n; i++){
            for(int j = 0; c[i][j] != '\0' || minrec[j] != '\0'; j++){
                if(c[i][j] > minrec[j]){
                    goto sljedecaRecenica;
                } else if(c[i][j] < minrec[j]){
                    minrec = c[i];
                    minind = i;
                    goto sljedecaRecenica;
                } else continue;
            }
        sljedecaRecenica: ;
        }
        char* temp = c[k];
        c[k] = c[minind];
        c[minind] = temp;
    }


    cout<<"Sortirane recenice:\n";
    for(int i = 0; i < n; i++)
        printf("%s\n", c[i]);

    for(int i = 0; i < n; i++)
        delete[] c[i];
    delete[] c;
    return 0;
}
