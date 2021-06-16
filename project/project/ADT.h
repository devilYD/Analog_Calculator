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
    bool isOne;
    int gmnum;
public:
    Numchar(vector<char> &ch);
    ~Numchar();
    int Isnumber();
    int Isone();
    double NValue();
    char CValue();
    void setgmnum(int a);
    int hnum();
};

int Numchar::hnum()
{
    return this->gmnum;
}

void Numchar::setgmnum(int a)
{
    this->gmnum = a;
}

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
    else if (ch[0] == '+' || ch[0] == '-' || ch[0] == '*' || ch[0] == '/' || ch[0] == '(' || ch[0] == ')' || ch[0] == 'A' || ch[0] == 'S')
    {
        this->Char = ch[0];
        this->isNum = 0;
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
    int err;
public:
    Formula(vector<char> &ch);
    ~Formula();
    Numchar build(vector<char> &ch);
    double doit();
    int get_init(Numchar &ch,vector<Numchar> &After);
};

Formula::Formula(vector<char> &ch)
{
    vector<Numchar> Fm;
    vector<double> Number;
    vector<char> Operator;
    int err =0;

    int change = 0; //0为数字状态，1为运算符
    vector<char> mid;

    vector<char>::iterator it;
    for (it = ch.begin(); it != ch.end(); it++)
    {
        if (it == ch.begin())
        {
            if ( (*it > '0' && *it < '9' ) || *it == '.')
                change = 0;
            else
            {
                mid.push_back(*it);
                change = 1;
            }
        }
        if ( change == 0 && (*it < '0' || *it >'9')&&*it!='.')
        {
            Fm.push_back(build(mid));
            mid.clear();
            change = (change + 1) % 2;
        } else if (change == 1)
        {
            Fm.push_back(build(mid));
            if (Fm[Fm.size()-1].Isnumber())
                Fm.back().setgmnum(2);
            else
                Fm.back().setgmnum(1);
            mid.clear();
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
                
            }
            
        }
        
        
    }
}

int Priority(Numchar &operate)
{
    if (operate.CValue() == '+' || operate.CValue() == '-')
        return 2;
    else if (operate.CValue() == '*' || operate.CValue() == '/')
        return 3;
    else if (operate.CValue() == '(')
        return 1;
    else
        return 0;
}

int Formula::get_init(Numchar &ch,vector<Numchar> &After)
{
    vector<Numchar>::iterator it;
    if (ch.CValue() == '(')
    {
        After.push_back(ch);
    }
    else if( ch.CValue() == ')')
    {
        vector<Numchar> mid;
        while (After.back().CValue() != '(' || !After.empty())
        {
            mid.push_back(Pop(After));
        }
        if (After.empty())
        {
            this->err =1;//输入出错
        } else
        {
            After.pop_back();
        }
        while (!mid.empty())
        {
            After.push_back(Pop(mid));
        }    
    }
    else
    {
        vector<Numchar> mid;
        while (Priority(After.back())>=Priority(ch) && After.back().CValue() != '(')
        {
            mid.push_back(Pop(After));
        }
        After.push_back(ch);
        while (!mid.empty())
        {
            After.push_back(Pop(mid));
        }
    }
    return 0;
}

Numchar Pop(vector<Numchar> &X)
{
    Numchar ch(X.back());
    X.pop_back();
    return ch;
}
#endif // ADT_H
