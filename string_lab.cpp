#include <iostream>
#include <string>
using namespace std;

int main()
{   system("chcp 65001 > nul");  
    string name = "张三";
    cout<<name<<endl;
    name="李四";
    cout<<name<<endl;
    string name2="李四";
    if (name==name2)
    {
        cout<<"相等"<<endl;

    }else{
        cout<<"不相等"<<endl;
    }
    cout<<name+name2<<endl;
    cout << "length():" << name.length() << endl;
    system("pause");
    return 0;
}