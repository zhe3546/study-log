#include<iostream>
using namespace std;
int* makeScores()
{
    int *s=new int[10];
    s[0]=10;s[1]=11;s[2]=22;s[3]=33;s[4]=44;s[5]=55;s[6]=66;s[7]=77;s[8]=88;s[9]=99;
    cout<<"s="<<s<<endl;
    return s;
}
int main()
{
    system("chcp 65001 > nul");
        int* p = makeScores();
    cout << "main 里 p = " << p << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    delete[] p;

    system("pause");
    return 0;
}