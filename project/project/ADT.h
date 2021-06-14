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
};

Numchar::Numchar(vector<char> &ch)
{
    int i = 0;
    double afterpoint;
    if (ch[0] >= '0' && ch[0] <= '9')
    {
        this->Number=0.0;
        vector<char>::iterator it;
        for(it=ch.begin();it!=ch.end()||*it!='.';it++)
        {
            this->Number = this->Number*10 + ((int)*it -(int)'0');
        }
        if (*it == '.')
            for(it=it+1;it!=ch.end();it++)
            {
                i = i+1;
                afterpoint = (int)*it -(int)'0';
                for (int n = 0; n < i; n++)
                {
                    afterpoint = afterpoint/10;
                }
                this->Number = this->Number+ afterpoint;
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
        this->Number=0.0;
        vector<char>::iterator it;
        for(it=ch.begin();it!=ch.end()||*it!='.';it++)
        {
            this->Number = this->Number*10 + ((int)*it -(int)'0');
        }
        if (*it == '.')
            for(it=it+1;it!=ch.end();it++)
            {
                i = i+1;
                afterpoint = (int)*it -(int)'0';
                for (int n = 0; n < i; n++)
                {
                    afterpoint = afterpoint/10;
                }
                this->Number = this->Number+ afterpoint;
            }  
        if (ch[0] == 'A')
            this->Number = abs(this->Number);
        else
            this->Number = sqrt(this->Number);
        this->isNum = 1;
    }
    
}

class Formula
{
private:
    vector<vector<char>> charlist;
    vector<Numchar> Fm;
    vector<double> Number;
    vector<char> Operator;
    vector<Formula> Another;

public:
    Formula();
    ~Formula();
};

Formula::Formula()
{
    vector<Numchar> Fm;
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

#endif // ADT_H
