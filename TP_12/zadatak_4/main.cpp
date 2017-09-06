#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Kompleksni {
    double re, im;

public:
    Kompleksni(double re = 0, double im = 0) : re(re), im(im) {}
    friend ostream& operator<<(ostream& o, const Kompleksni& w);
};

ostream& operator<<(ostream& o, const Kompleksni& w)
{
    bool reNula = (w.re == 0);
    bool imNula = (w.im == 0);
    bool imJedan = (abs(w.im) == 1);
    bool imNeg = (w.im < 0);
    if(imNula)
        return o<<w.re;
    if(reNula){
        if(imJedan){
            if(imNeg)
                return o<<"-i";
            return o<<"i";
        }
        return o<<w.im<<"i";
    }
    else {
        if(imJedan){
            if(imNeg)
                return o<<w.re<<"-i";
            return o<<w.re<<"+i";
        }
        if(imNeg)
            return o<<w.re<<w.im<<"i";
        return o<<w.re<<"+"<<w.im<<"i";
    }

    return o;
}

int main()
{
    Kompleksni z(2, -1);
    cout<<z;

    return 0;
}
