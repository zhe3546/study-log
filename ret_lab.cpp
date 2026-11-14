#include <iostream>
using namespace std;

int* makeScores()
{
    int s[5] = {90, 80, 70, 60, 50};
    cout << "函数里 s 的地址: " << s << endl;
    return s;
}

int main()
{
    system("chcp 65001 > nul");

    int* p = makeScores();
    cout << "main 里 p 指向: " << p << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}