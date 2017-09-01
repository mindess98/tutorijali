#include <iostream>
#include <set>

using namespace std;

template <typename T>
set<T> Unija (set<T> s1, set<T> s2){
    set<T> sol;
    for(auto b = s1.begin(); b != s1.end(); b++)
        sol.insert(*b);
    for(auto b = s2.begin(); b != s2.end(); b++)
        sol.insert(*b);
    return sol;
}
template <typename T>
set<T> Presjek (set<T> s1, set<T> s2){
    set<T> sol;
    for(auto b = s1.begin(); b != s1.end(); b++)
        if(s2.find(*b) != s2.end()) sol.insert(*b);
    return sol;
}


int main()
{
    set<string> s = Presjek(set<string>{"aba", "baba", "dada", "mama", "tata", "nana", "iaia"},set<string>{"baba", "dada", "mama", "nana"});
    for(string x : s)
        cout<<x<<" ";
    return 0;
}
