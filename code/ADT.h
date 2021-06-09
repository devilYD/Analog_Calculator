#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

double Last_Answer = 0.0;

class Formula
{
private:
    vector<char> Fm;
    vector<double> Number;
    vector<char> Operator;
    vector<Formula> Another;
public:
    Formula();
    ~Formula();
    void Get_init();//将数据存入Fm
};

Formula::Formula()
{
    vector<char> Fm;
    vector<double> Number;
    vector<char> Operator;
    vector<Formula> Another;
}

Formula::~Formula()
{
    Fm.clear();
    Number.clear();
    Operator.clear();
    Another.clear();
}

void Formula::Get_init()
{
    int ch;
    while ((ch = cin.get()) != EOF)
    {
        Fm.push_back((char)ch);
    }
}


void Main_Page(Formula &F); //生成主页面

void Main_Page(Formula &F)
{
    system("cls");
    cout << "欢迎使用没事找事模拟计算器！" << endl;
    cout << "上一次的计算结果为：" << Last_Answer << endl;
    cout << "请输入接下来需要运算的运算式：" << endl;
    cout << "（如需计算开方请在数字前加S，求绝对值则加A，如：S4、A-3）" << endl;
    F.Get_init();
}