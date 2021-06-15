#ifndef ADT_H
#define ADT_H

#include <vector>
#include <math.h>
using namespace std;

class Numchar
{
private:
    double Number;
    char Char;
    bool isNum;

public:
    Numchar(vector<char> &ch);
    ~Numchar();
    int Isnumber();
    double NValue();
    char CValue();
};

Numchar::Numchar(vector<char> &ch)
{
    int i = 0;
    double afterpoint;
    if (ch[0] >= '0' && ch[0] <= '9')
    {
        this->Number = 0.0;
        vector<char>::iterator it;
        for (it = ch.begin(); it != ch.end() || *it != '.'; it++)
        {
            this->Number = this->Number * 10 + ((int)*it - (int)'0');
        }
        if (*it == '.')
            for (it = it + 1; it != ch.end(); it++)
            {
                i = i + 1;
                afterpoint = (int)*it - (int)'0';
                for (int n = 0; n < i; n++)
                {
                    afterpoint = afterpoint / 10;
                }
                this->Number = this->Number + afterpoint;
            }
        this->isNum = 1;
    }
    else if (ch[0] == '+' || ch[0] == '-' || ch[0] == '*' || ch[0] == '/' || ch[0] == '(' || ch[0] == ')')
    {
        this->Char = ch[0];
        this->isNum = 0;
    }
    else if (ch[0] == 'A' || ch[0] == 'S')
    {
        this->Number = 0.0;
        vector<char>::iterator it;
        for (it = ch.begin(); it != ch.end() || *it != '.'; it++)
        {
            this->Number = this->Number * 10 + ((int)*it - (int)'0');
        }
        if (*it == '.')
            for (it = it + 1; it != ch.end(); it++)
            {
                i = i + 1;
                afterpoint = (int)*it - (int)'0';
                for (int n = 0; n < i; n++)
                {
                    afterpoint = afterpoint / 10;
                }
                this->Number = this->Number + afterpoint;
            }
        if (ch[0] == 'A')
            this->Number = abs(this->Number);
        else
            this->Number = sqrt(this->Number);
        this->isNum = 1;
    }
}

int Numchar::Isnumber()
{
    return this->isNum;
}

double Numchar::NValue()
{
    return this->Number;
}

char Numchar::CValue()
{
    return this->Char;
}

class Formula
{
private:
    vector<Numchar> Fm;
    vector<double> Number;
    vector<char> Operator;

public:
    Formula(vector<char> &ch);
    ~Formula();
    Numchar build(vector<char> &ch);
    double doit();
};

Formula::Formula(vector<char> &ch)
{
    vector<Numchar> Fm;
    vector<double> Number;
    vector<char> Operator;

    int change = 0; //0为数字状态，1为运算符
    vector<char> mid;

    vector<char>::iterator it;
    for (it = ch.begin(); it != ch.end(); it++)
    {
        if ((change == 0 && (*it > '9' || *it < '0') && *it != 'A' && *it != 'S')||(change == 1 && !(*it > '9' || *it < '0') && *it != 'A' && *it != 'S'))
        {
            Fm.push_back(build(mid));
            mid.clear();
            change = (change + 1) % 2;
        }
        mid.push_back(*it);
    }
}

Formula::~Formula()
{
    Fm.clear();
    Number.clear();
    Operator.clear();
}

Numchar Formula::build(vector<char> &ch)
{
    Numchar a = Numchar(ch);
    return a;
}

double Formula::doit()
{
    vector<Numchar> After;
    for (int i = 0; i < Fm.size(); i++)
    {
        if (Fm[i].Isnumber())
            After.push_back(Fm[i]);
        else
        {
            if (Fm[i].CValue() == '(')
            {
                /* code */
            }
            
        }
        
        
    }
    


}

int Priority(char operate)
{
    if (operate == '+' || operate == '-')
        return 1;
    else if (operate == '*' || operate == '/')
        return 2;
    else if (operate == '(')
        return 3;
    else
        return 0;
}
#endif // ADT_H
