#include <iostream>
#include <string>
using namespace std;

int main()
{   
    system("chcp 65001 > nul");
    char a='A';
    cout <<"a里装的是"<<a<<endl;
    cout <<"它占了多少字节:"<<sizeof(a)<<endl;
    system("pause");
    return 0;
}