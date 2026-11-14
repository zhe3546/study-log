#include <iostream>
using namespace std;

int main()
{
    system("chcp 65001 > nul");

    int a = 10;
    int &b = a;
    b = 20;
    cout << "a = " << a << endl;

    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    int c=a;
    c=30;
    cout<<"after c=30,a="<<a<<endl;
    system("pause");
    return 0;
}