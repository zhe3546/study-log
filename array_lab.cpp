#include <iostream>
using namespace std;

int main()
{
    system("chcp 65001 > nul");

    int score[10];
    for (int i = 0; i < 10; i++)
    {
        score[i] = 60 + i;
    }

    cout << "sizeof(score) = " << sizeof(score) << endl;

    score[10] = 75;
    cout << "score[10] = " << score[10] << endl;
    cout << "score[50] = " << score[50] << endl;

    system("pause");
    return 0;
}