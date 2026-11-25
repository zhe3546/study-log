#include <iostream>
using namespace std;

class student
{
private:
    int score;
public:
    string name;
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
};

int main()
{   system("chcp 65001 > nul");  
    student s1,s2;
    s1.name="张一";
    s1.setScore(88);
    s2.name="张二";
    s2.setScore(89);
    s2.show();
    system("pause");
    return 0;
}