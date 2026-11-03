#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    system("chcp 65001 > nul");

    int score;
    cout << "请输入分数:";
    cin >> score;

    cout << "你输入的分数是:" << score << endl;
    cout << "加 10 分之后是:" << score + 10 << endl;

    system("pause");
    return 0;
}