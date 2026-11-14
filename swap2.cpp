#include <iostream>
using namespace std;
void swap(int &a,int&b){
int t=a;
a=b;
b=t;
};
int main()
{   system("chcp 65001 > nul");  
    int m=1;
    int n=2;
    swap(m,n);
    cout<<n<<endl;
    cout<<m<<endl;
    system("pause");
    return 0;
}