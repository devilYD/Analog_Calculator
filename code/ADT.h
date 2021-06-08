#include <iostream>
#include <cstdlib>
using namespace std;

double Last_Answer = 0.0;

void Main_Page(); //生成主页面

void Main_Page()
{
    system("cls");
    cout << "欢迎使用没事找事模拟计算器！" << endl;
    cout << "上一次的计算结果为：" << Last_Answer << endl;
    cout << "请输入接下来需要运算的运算式：" << endl;
    cout << "（如需计算开方请在数字前加S，求绝对值则加A，如：S4、A-3）" << endl;
}