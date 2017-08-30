#include <iostream>

using namespace std;

template <typename iterator1, typename iterator2>
iterator2 RazmijeniBlokove(iterator1 left1, iterator1 right1, iterator2 left2){
    for(left1; left1 != right1; left1++, left2++)
        swap(*left1, *left2);
    return left2;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6};
    int b[10] = {2, 5, 4, 1, 3, 6};

    RazmijeniBlokove(a, a+6, b);

    for(int i = 0; i < 10; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i = 0; i < 10; i++)
        cout<<b[i]<<" ";

    return 0;
}
