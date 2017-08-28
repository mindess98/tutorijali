#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente prvog vektora: ";
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x;
        std::cin>>x;
        a.push_back(x);
    }

    std::cout<<"Unesite broj elemenata drugog vektora: ";
    int m;
    std::cin>>m;
    std::cout<<"Unesite elemente drugog vektora: ";
    vector<int> b;
    for(int i = 0; i < m; i++){
        int x;
        std::cin>>x;
        b.push_back(x);
    }

    vector<vector<int>> KroneckerovProizvod(vector<int>, vector<int>);

    auto c = KroneckerovProizvod(a, b);

    int NajvecaSirina(vector<vector<int>>);
    int sirina = NajvecaSirina(c) + 1;
    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < c[0].size(); j++)
            std::cout<<std::setw(sirina)<<c[i][j];
        std::cout<<std::endl;
    }

    return 0;
}


vector<vector<int>> KroneckerovProizvod(vector<int> a, vector<int> b){
    vector<vector<int>> c(a.size(), vector<int>(b.size()));

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++)
            c[i][j] = a[i] * b[j];
    }
    return c;
}

int NajvecaSirina(vector<vector<int>> c){
    int BrojCifara(int);
    int sol = 0;
    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < c[i].size(); j++){
            int numDig = BrojCifara(c[i][j]);
            if(c[i][j] < 0) numDig++;
            if(numDig > sol) sol = numDig;
        }
    }
    return sol;
}

int BrojCifara(int x){
    int sol = 0;
    while(x != 0){
        x /= 10;
        sol++;
    }
    return sol;
}


