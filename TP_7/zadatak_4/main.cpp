#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <memory>


using namespace std;

int main()
{
    cout<<"Koliko zelite recenica: ";
    int n;
    cin>>n;


    try{
        unique_ptr<shared_ptr<string>> c(new shared_ptr<string>[n]);
        cout<<"Unesite recenice:\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int i = 0; i < n; i++){
            string s;
            getline(cin, s);
            c.get()[i] = shared_ptr<string>(new string(s));
        }
        sort(c.get(), c.get()+n, [](shared_ptr<string> a, shared_ptr<string> b){return *a < *b;});

        cout<<"Sortirane recenice:\n";
        for(int i = 0; i < n; i++)
            cout<<*(c.get()[i])<<endl;
    }
    catch(...){
        cout<<"Problemi sa memorijom";
        return -1;
    }

    return 0;
}
