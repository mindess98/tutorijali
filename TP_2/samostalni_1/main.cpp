#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    std::cout<<"Unesite n (za nxn tablicu mnozenja): ";
    int n;
    std::cin>>n;

    for(int j = 1;; j++){
        for(int i = 1;; i++){
            std::cout<<"+-----";
            if(i == n){
                std::cout<<"+"<<std::endl;
                break;
            }
        }
        for(int i = 1;; i++){
            std::cout<<"|"<<std::setw(4)<<j*i<<" ";
            if(i == n) {
                std::cout<<"|"<<std::endl;
                break;
            }
        }
        if(j == n){
            for(int i = 1;; i++){
                std::cout<<"+-----";
                if(i == n){
                    std::cout<<"+"<<std::endl;
                    break;
                }
            }
            break;
        }
    }
    return 0;
}
