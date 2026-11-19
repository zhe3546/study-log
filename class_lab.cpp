#include <iostream>
using namespace std;

class student
{
private:
    int score;
public:
    string name;
    void setScore(int s){
        if (s>0&&s<100)
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
};

int main()
{   system("chcp 65001 > nul");  
    student s1;
    student s2;
    student s3;
    s1.name="张一";
    s1.setScore(88);
    s2.name="张二";
    s2.setScore(89);
    s3.name="张三";
    s3.setScore(91);
    s1.show();
    s2.show();
    s3.show();
    system("pause");
    return 0;
}