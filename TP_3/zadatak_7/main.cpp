#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

using namespace std;

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

int main()
{
    vector<vector<int>> PascalovTrougao(int);

    auto c = PascalovTrougao(7);

    int sirina = NajvecaSirina(c) + 1;
    for(auto red : c){
        for(int broj : red)
            std::cout<<std::setw(sirina)<<broj;
        std::cout<<std::endl;
    }

    return 0;
}

vector<vector<int>> PascalovTrougao(int n){
    if(n < 0 ) throw std::domain_error("Broj redova ne smije biti negativan");
    vector<vector<int>> sol(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0)
                sol[i].push_back(1);
            else if(j == i)
                sol[i].push_back(1);
            else
                sol[i].push_back(sol[i-1][j] + sol[i-1][j-1]);
        }
    }
    return sol;
}
