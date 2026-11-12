#include <iostream>
#include<vector>
using namespace std;

int main()
{   system("chcp 65001 > nul");  
    vector<int>v;
    v.push_back(78);
    v.push_back(88);
    v.push_back(68);
    v.push_back(79);
    v.push_back(77);
    v.push_back(75);
    v.push_back(74);
    v.push_back(89);
    v.push_back(70);
    v.push_back(81);
    v.push_back(98);
    cout<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<sizeof(v);
    system("pause");
    return 0;
}