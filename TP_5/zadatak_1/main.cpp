#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

char* odDrugeRijeci(char* recenica){
    cout<<"Unesite recenicu: ";


    gets(recenica);

    char* p;
    for(p = recenica; *p != '\0'; p++){
        if(!isspace(*p)){
            while(!isspace(*p))
                p++;
            while(isspace(*p))
                p++;
            return p;
        }
    }
    return p;
}

int main()
{

    char recenica[10000];
    char* c = odDrugeRijeci(recenica);

    cout<<"Recenica bez prve dvije rijeci glasi: ";
    for(; *c != 0; c++)
        cout<<*c;
    return 0;
}
