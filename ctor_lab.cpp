#include <iostream>
using namespace std;

class student
{
private:
    int score;
public:
    string name;
    student(string a,int b)
    {
        
        name=a;
        score=b;
        cout<<"构造："<<name<<endl;
    }
    void setScore(int s){
        if (s>=0&&s<=100)
        {
            score=s;
        }
    }
        int getScore()
        {
            return score;
        }
    void show()
    {
        cout<<"姓名:"<<name<<"成绩："<<score<<endl;
    }
    ~student()
{
    cout << "析构: " << name << endl;
}
};

int main()
{   system("chcp 65001 > nul");  
    student s1("张一",88);
    student s2("张二",89);
    student s3("张三",100);
    s1.show();
    s2.show();
    s3.show();
    system("pause");
    return 0;
}