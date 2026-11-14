#include <iostream>
using namespace std;

int main()
{
    system("chcp 65001 > nul");

    int a[1000000];
    for (int i = 0; i < 1000000; i++)
    {
        a[i] = i;
    }
    cout << "a[999999] = " << a[999999] << endl;

    system("pause");
    return 0;
}