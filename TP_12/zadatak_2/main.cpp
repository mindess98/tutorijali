#include <iostream>
#include <set>
#include <utility>

using namespace std;


template <typename T>
set<T> operator+(const set<T>& s1, const set<T>& s2)
{
    set<T> sol;
    for(T t : s1)
        sol.insert(t);
    for(T t : s2)
        sol.insert(t);
    return sol;
}

template <typename T>
set<T> operator*(const set<T>& s1, const set<T>& s2)
{
    set<T> sol;
    for(T t : s1)
        if(s2.find(t) != s2.end()) sol.insert(t);
    return sol;
}

template <typename T>
ostream& operator<<(ostream& tok, const set<T>& s)
{
    tok<<"{";
    auto e = --s.end();
    for(auto p = s.begin(); p != e; p++)
        tok<<*p<<",";
    return tok<<*e<<"}";
}

template <typename T1, typename T2>
ostream& operator<<(ostream& tok, pair<T1,T2> p)
{
    return tok<<"("<<get<0>(p)<<","<<get<1>(p)<<")";
}

template <typename T1, typename T2>
set<pair<T1,T2>> operator%(const set<T1>& s1, const set<T2>& s2)
{
    set<pair<T1,T2>> sol;
    for(T1 t1 : s1)
        for(T2 t2 : s2)
            sol.insert(make_pair(t1,t2));
    return sol;
}

int main()
{
    set<int> s1{3, 5, 1, 2, 8}, s2{7, 2, 8, 4};

    cout<<s1 + s2<<endl;
    cout<<s1 * s2<<endl;

    set<char> s3 {'A', 'B'};
    set<int> s4 {1, 2, 3};
    cout<<s3 % s4<< endl;
    return 0;
}


