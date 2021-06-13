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
    while ((ch = cin.get()) != (int)'\n')
    {
        Fm.push_back((char)ch);
    }
}


