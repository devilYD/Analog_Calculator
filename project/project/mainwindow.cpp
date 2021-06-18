#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>
#define Maxlen 500
using namespace std;
double fabs(double x);
void judge(char *p, char *q);
double solve(char *q);
int Flag;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *widget = new QWidget; //构建一个QWidget布局将设置的布局添加进这个QWidget
    this->setCentralWidget(widget);

    inputLine = new QLineEdit;
    inputLine->setText(input);

    zeroButton = new QPushButton("0");
    oneButton = new QPushButton("1");
    twoButton = new QPushButton("2");
    threeButton = new QPushButton("3");
    fourButton = new QPushButton("4");
    fiveButton = new QPushButton("5");
    sixButton = new QPushButton("6");
    sevenButton = new QPushButton("7");
    eightButton = new QPushButton("8");
    nineButton = new QPushButton("9");
    decButton = new QPushButton(".");
    label = new QLabel("请注意ABS和SQR后需要加括号");
    botButton = new QPushButton("SQR");
    timButton = new QPushButton("ABS");
    addButton = new QPushButton("+");
    subButton = new QPushButton("-");
    mulButton = new QPushButton("*");
    divButton = new QPushButton("/");
    equButton = new QPushButton("=");

    lefButton = new QPushButton("(");
    rigButton = new QPushButton(")");
    CEButton = new QPushButton("CE");
    ACButton = new QPushButton("AC");
    QGridLayout *H = new QGridLayout(this); //声明了一个网格布局

    inputLine->setFixedHeight(50); //调整第一行大小
    CEButton->setFixedHeight(50);
    ACButton->setFixedHeight(50);

    H->addWidget(inputLine, 0, 0, 1, 3);
    H->setRowStretch(0, 100);
    H->addWidget(CEButton, 0, 3);
    H->addWidget(ACButton, 0, 4);

    H->addWidget(oneButton, 1, 0);
    H->addWidget(twoButton, 1, 1);
    H->addWidget(threeButton, 1, 2);
    H->addWidget(botButton, 1, 3);
    H->addWidget(timButton, 1, 4);

    H->addWidget(fourButton, 2, 0);
    H->addWidget(fiveButton, 2, 1);
    H->addWidget(sixButton, 2, 2);
    H->addWidget(addButton, 2, 3);
    H->addWidget(subButton, 2, 4);

    H->addWidget(sevenButton, 3, 0);
    H->addWidget(eightButton, 3, 1);
    H->addWidget(nineButton, 3, 2);
    H->addWidget(mulButton, 3, 3);
    H->addWidget(divButton, 3, 4);

    H->addWidget(zeroButton, 4, 0);
    H->addWidget(decButton, 4, 1);
    H->addWidget(lefButton, 4, 2);
    H->addWidget(rigButton, 4, 3);
    H->addWidget(equButton, 4, 4);

    H->addWidget(label, 5, 0, 1, 3);

    widget->setLayout(H); //将布局显示出来

    connect(zeroButton, SIGNAL(clicked()), this, SLOT(buttonZeroClicked())); //信号与槽函数
    connect(oneButton, SIGNAL(clicked()), this, SLOT(buttonOneClicked()));
    connect(twoButton, SIGNAL(clicked()), this, SLOT(buttonTwoClicked()));
    connect(threeButton, SIGNAL(clicked()), this, SLOT(buttonThreeClicked()));
    connect(fourButton, SIGNAL(clicked()), this, SLOT(buttonFourClicked()));
    connect(fiveButton, SIGNAL(clicked()), this, SLOT(buttonFiveClicked()));
    connect(sixButton, SIGNAL(clicked()), this, SLOT(buttonSixClicked()));
    connect(sevenButton, SIGNAL(clicked()), this, SLOT(buttonSevenClicked()));
    connect(eightButton, SIGNAL(clicked()), this, SLOT(buttonEightClicked()));
    connect(nineButton, SIGNAL(clicked()), this, SLOT(buttonNineClicked()));

    connect(addButton, SIGNAL(clicked()), this, SLOT(buttonAddClicked()));
    connect(subButton, SIGNAL(clicked()), this, SLOT(buttonSubClicked()));
    connect(mulButton, SIGNAL(clicked()), this, SLOT(buttonMulClicked()));
    connect(divButton, SIGNAL(clicked()), this, SLOT(buttonDivClicked()));

    connect(botButton, SIGNAL(clicked(bool)), this, SLOT(buttonBotClicked())); //正负号
    connect(timButton, SIGNAL(clicked(bool)), this, SLOT(buttonTimClicked())); //时间
    connect(decButton, SIGNAL(clicked(bool)), this, SLOT(buttonDecClicked())); //点号

    connect(lefButton, SIGNAL(clicked(bool)), this, SLOT(buttonLefClicked())); //左括号
    connect(rigButton, SIGNAL(clicked(bool)), this, SLOT(buttonRigClicked())); //右括号

    connect(CEButton, SIGNAL(clicked()), this, SLOT(buttonCEClicked()));
    connect(ACButton, SIGNAL(clicked()), this, SLOT(buttonACClicked()));

    connect(equButton, SIGNAL(clicked()), this, SLOT(buttonEquClicked())); //等于号*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonZeroClicked() //以下是实现相应的槽函数
{
    if (input == "0")
        input = '0';
    else
        input = input + '0';
    inputLine->setText(input);
}

void MainWindow::buttonOneClicked()
{
    if (input == "0")
        input = '1';
    else
        input = input + '1';
    inputLine->setText(input);
}

void MainWindow::buttonTwoClicked()
{
    if (input == "0")
        input = '2';
    else
        input = input + '2';
    inputLine->setText(input);
}

void MainWindow::buttonThreeClicked()
{
    if (input == "0")
        input = '3';
    else
        input = input + '3';
    inputLine->setText(input);
}

void MainWindow::buttonFourClicked()
{
    if (input == "0")
        input = '4';
    else
        input = input + '4';
    inputLine->setText(input);
}

void MainWindow::buttonFiveClicked()
{
    if (input == "0")
        input = '5';
    else
        input = input + '5';
    inputLine->setText(input);
}

void MainWindow::buttonSixClicked()
{
    if (input == "0")
        input = '6';
    else
        input = input + '6';
    inputLine->setText(input);
}

void MainWindow::buttonSevenClicked()
{
    if (input == "0")
        input = '7';
    else
        input = input + '7';
    inputLine->setText(input);
}

void MainWindow::buttonEightClicked()
{
    if (input == "0")
        input = '8';
    else
        input = input + '8';
    inputLine->setText(input);
}

void MainWindow::buttonNineClicked()
{
    if (input == "0")
        input = '9';
    else
        input = input + '9';
    inputLine->setText(input);
}

void MainWindow::buttonAddClicked()
{
    if (input == "0")
        input = '+';
    else
        input = input + '+';
    inputLine->setText(input);
}

void MainWindow::buttonSubClicked()
{
    if (input == "0")
        input = '-';
    else
        input = input + '-';
    inputLine->setText(input);
}

void MainWindow::buttonMulClicked()
{
    if (input == "0")
        input = '*';
    else
        input = input + '*';
    inputLine->setText(input);
}

void MainWindow::buttonDivClicked()
{
    if (input == "0")
        input = '/';
    else
        input = input + '/';
    inputLine->setText(input);
}

void MainWindow::buttonTimClicked() //Time
{
    if (input == "0")
        input = "ABS";
    else
        input = input + "ABS";
    inputLine->setText(input);
}

void MainWindow::buttonDecClicked() //小数点
{
    if (input == "0")
        input = '.';
    else
        input = input + '.';
    inputLine->setText(input);
}

void MainWindow::buttonBotClicked() //加减号
{
    if (input == "0")
        input = "SQR";
    else
        input = input + "SQR";
    inputLine->setText(input);
}

void MainWindow::buttonLefClicked() //左括号
{
    if (input == "0")
        input = '(';
    else
        input = input + '(';
    inputLine->setText(input);
}

void MainWindow::buttonRigClicked() //右括号
{
    if (input == "0")
        input = ')';
    else
        input = input + ')';
    inputLine->setText(input);
}

void MainWindow::buttonCEClicked()
{
    input = input.left(input.length() - 1); //减去一字符
    inputLine->setText(input);
}
void MainWindow::buttonACClicked() //直接清空
{
    input = '0';
    inputLine->setText(input);
}

void MainWindow::buttonEquClicked() //等于号
{
    string inputTemp = input.toStdString();
    char ch[500];
    for (int i = 0; i < inputTemp.length()+1; i++)
    {
        ch[i] = inputTemp[i];
    }
    char answer[500];
    judge(ch, answer);
    double ans = solve(answer);

    if (Flag != 1)
    {
        input = input + "=" + QString::number(ans);
        inputLine->setText(input);
    }
    else
    {
        input = input + "=syntax error";
        inputLine->setText(input);
    }
}

double fabs(double x) //求绝对值，因为原型处理数字超过9位会出现错误
{
    if (x < 0)
        return 0 - x;
    return x;
}

void judge(char *p, char *q) //实现判断表达式并且将正确的表达式转换为后缀式
{
    int i = 0, j = 0;      //i表示p的下标，j代表q的下标
    int f = 1;             //判断当前字符是否与左括号相邻，默认相邻，用于取正、取负的运算。
    int sum = 0;           //判断括号是否匹配
    for (i = 0; p[i]; i++) //判断括号是否匹配以及是否有非法字符
    {
        if (p[i] == 's' || p[i] == 'S') //判断是否是完整的SQR
        {
            if (p[i + 1] != 'q' && p[i + 1] != 'Q')
            {
                Flag = 4;
                return;
            }
            if (p[i + 2] != 'r' && p[i + 2] != 'R')
            {
                Flag = 4;
                return;
            }
            if (p[i + 3] != '(')
            {
                Flag = 3;
                return;
            }
            i += 2;
            continue;
        }
        if (p[i] == 'a' || p[i] == 'A') //判断是否是完整的ABS
        {
            if (p[i + 1] != 'b' && p[i + 1] != 'B')
            {
                Flag = 4;
                return;
            }
            if (p[i + 2] != 's' && p[i + 2] != 'S')
            {
                Flag = 4;
                return;
            }
            if (p[i + 3] != '(')
            {
                Flag = 3;
                return;
            }
            i += 2;
            continue;
        }
        if (p[i] != '+' && p[i] != '-' && p[i] != '*' && p[i] != '/' && p[i] != '(' && p[i] != ')' && p[i] != '.' && (p[i] < '0' || p[i] > '9')) //判断是否出现其他不合法符号
        {
            Flag = 4;
            return;
        }
        if (p[i] == '(')
            sum += 1; //判断括号是否匹配
        else if (p[i] == ')')
            sum -= 1;
        if (sum < 0)
        {
            Flag = 2;
            return;
        }
    }
    if (sum != 0)
    {
        Flag = 2;
        return;
    }

    stack<char> s;       // 申明一个栈s，存运算符
    i = 0;               // 初始化下标
    while (p[i] != '\0') // 遍历字符串p
    {
        switch (p[i])
        {
        case '(': //将左括号入栈，f赋为1
            s.push(p[i++]);
            f = 1;
            break;
        case ')': //将右括号这一层内的所有运算符出栈存入q中
            while (s.top() != '(')
            {
                q[j++] = s.top();
                s.pop();
            }
            s.pop(); //这一层的左括号出栈
            i++;
            f = 0;
            break;
        case '+':
            if (f) //紧跟左括号，所以是取正运算，为了区分用"?"表示，将其入栈
            {
                s.push('?');
                i++;
                break;
            }
            while (!s.empty() && s.top() != '(') //加法运算，因为运算最低级，所以将这一层其他运算符全部出栈后再入栈
            {
                q[j++] = s.top();
                s.pop();
            }
            s.push(p[i++]);
            f = 0;
            break;
        case '-':
            if (f) //紧跟左括号，所以是取负运算，为了区分用"@"表示，将其入栈
            {
                s.push('@');
                i++;
                break;
            }
            while (!s.empty() && s.top() != '(') //减法运算，因为运算最低级，所以将这一层其他运算符全部出栈后再入栈
            {
                q[j++] = s.top();
                s.pop();
            }
            s.push(p[i++]);
            f = 0;
            break;
        case '*':
        case '/':
            while (!s.empty() && (s.top() != '+' && s.top() != '-' && s.top() != '(')) //乘除法，将同级运算符全部出栈后再入栈
            {
                q[j++] = s.top();
                s.pop();
            }
            s.push(p[i++]);
            f = 0;
            break;
        case 's':
        case 'S':
            s.push('s'); //开方，因为带括号所以最高级，用"s"表示入栈
            i += 3;
            f = 0;
            break;
        case 'a':
        case 'A': //取绝对值，因为带括号所以最高级，用"a"表示入栈
            s.push('a');
            i += 3;
            f = 0;
            break;
        default:
            while (p[i] >= '0' && p[i] <= '9') //判断是否为数字，依次存入q中
            {
                q[j++] = p[i++];
            }
            if (p[i] == '.') //判断是否有小数点
            {
                q[j++] = '.';
                i++;
                while (p[i] >= '0' && p[i] <= '9')
                {
                    q[j++] = p[i++];
                }
            }
            q[j++] = '#'; //用一个"#"代表一个数字的结束
            f = 0;
            break;
        }
    }
    while (!s.empty()) //没出栈的出栈
    {
        q[j++] = s.top();
        s.pop();
    }
    q[j] = '\0';
    return;
}
double solve(char *q) //计算后缀式子q
{
    double a, b, ans;    //a,b为中间变量，ans为最终结果
    double sum, x;       //sum为字符转数字的变量，x为小数时的辅助变量
    int i = 0;           //i为字符串q的下标
    stack<double> s;     //申明double型的结果栈
    while (q[i] != '\0') //遍历q，遇到运算符提取结果栈中相应个数的数求得结果再存入栈，如果提不出来说明输入有误。
    {
        switch (q[i])
        {
        case '+':
            if (!s.empty())
            {
                a = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            if (!s.empty())
            {
                b = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            s.push(b + a);
            break;
        case '-':
            if (!s.empty())
            {
                a = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            if (!s.empty())
            {
                b = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            s.push(b - a);
            break;
        case '*':
            if (!s.empty())
            {
                a = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            if (!s.empty())
            {
                b = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            s.push(b * a);
            break;
        case '/':
            if (!s.empty())
            {
                a = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            if (fabs(a) <= 0.0000000001) //除数为0的情况
            {
                Flag = 5;
                return 0;
            }
            if (!s.empty())
            {
                b = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            s.push(b / a);
            break;
        case '?':
            if (!s.empty())
            {
                a = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            s.push(a);
            break;
        case '@':
            if (!s.empty())
            {
                a = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            s.push(-a);
            break;
        case 'a':
            if (!s.empty())
            {
                a = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            s.push(fabs(a));
            break;
        case 's':
            if (!s.empty())
            {
                a = s.top();
                s.pop();
            }
            else
            {
                Flag = 3;
                return 0;
            }
            if (a < 0) //开方数小于零的情况
            {
                Flag = 6;
                return 0;
            }
            s.push(sqrt(a));
            break;
        default: //字符转换数字
            sum = 0;
            while (q[i] >= '0' && q[i] <= '9')
            {
                sum = sum * 10 + (q[i] - '0');
                i++;
            }
            if (q[i] == '.')
            {
                x = 0.1;
                i++;
                while (q[i] >= '0' && q[i] <= '9')
                {
                    sum = sum + x * (q[i] - '0');
                    x *= 0.1;
                    i++;
                }
            }
            s.push(sum);
        }
        i++;
    }
    if (!s.empty())
    {
        ans = s.top();
        s.pop();
        if (s.empty()) //有且仅剩一个结果，返回计算结果
            return ans;
    }
    Flag = 3;
    return 0;
}

void MainWindow::on_Formula_linkActivated(const QString &link)
{
}
