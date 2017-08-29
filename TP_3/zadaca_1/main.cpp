#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> IzdvojiGadne(vector<int>, bool);
    auto c = IzdvojiGadne({56, 21, 31, 99, 85, 74, 63}, true);
    for(int z : c)
        std::cout<<z<<" ";
    return 0;
}

vector<int> IzdvojiGadne(vector<int> v, bool gadni){
    vector<int> sol;

    for(int k = 0;; k++){
continueOuter: if(k >= v.size()) break;
        int terCifre[3];
        terCifre[0] = terCifre[1] = terCifre[2] = 0;
        int y;
        y = v[k];
        while(y != 0){
            terCifre[y % 3]++;
            y /= 3;
        }
        if(v[k] == 0) terCifre[0]++;
        bool gadan = true;
        for(int i = 0; i < 3; i++){
            if(!gadan) break;
            if(terCifre[i] % 2 != 0){
                for(int j = 0; j < 3; j++)
                    if(terCifre[j] % 2 == 0){
                        k++;
                        goto continueOuter;
                    }
                gadan = false;
            }
        }
        if(gadan == gadni){
            bool VecPostoji;
            VecPostoji = false;
            std::cout<<v[k]<<" je gadan i "<<VecPostoji<<std::endl;
            for(int z : sol){
                if(v[k] == z) VecPostoji = true;
            }
            if(!VecPostoji) sol.push_back(v[k]);
        }
    }
    return sol;
}
