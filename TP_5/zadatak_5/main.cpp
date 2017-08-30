#include <iostream>
#include <cmath>

const long double PI = 4 * atan(1);

using namespace std;

long double xNaTrecu(long double x){
    return x * x * x;
}

long double jedanKrozX(long double x){
    return 1/x;
}

long double TrapeznoPravilo(long double (*f)(long double), long double a, long double b, int n){
    long double sum = ((b-a)/n) * ((1/2) * f(a) + (1/2) * f(b));
    for(int i = 0; i < n; i++){
        sum += ((b-a)/n) * (f(a + ((b-a)*i)/n));
    }
    return sum;
}

int main()
{
    cout<<"Unesite broj podintervala: ";
    int n;
    cin>>n;

    cout<<"Za taj broj podintervala priblizne vrijednosti integrala iznose: \n";
    cout<<"- Za funkciju sin x na intervalu (0,pi): "<<TrapeznoPravilo(sin, 0, PI, n)<<endl;
    cout<<"- Za funkciju x^3 na intervalu (0,10): "<<TrapeznoPravilo(xNaTrecu, 0, 10, n)<<endl;
    cout<<"- Za funkciju sin 1/x na intervalu (1,2): "<<TrapeznoPravilo(jedanKrozX, 1, 2, n)<<endl;
    return 0;
}
