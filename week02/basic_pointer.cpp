#include<iostream>
using namespace std;

main()
{
    int a[5] = {1,2,3,4,5};  
    int* p = a;         // a == &a[0]
    cout << *(p+3) << endl;
    p+=3;
    cout << *(p-1) << endl;
}