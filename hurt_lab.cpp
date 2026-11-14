#include <iostream>
using namespace std;

int main()
{   system("chcp 65001 > nul");  

    /*char name[20] = "张三";
name = "李四";*/
char a[20] = "张三";
char b[20] = "张三";

if (a == b) {
    cout << "相等" << endl;
} else {
    cout << "不相等" << endl;      // ← 你会看到这行!
}
    system("pause");
    return 0;
}